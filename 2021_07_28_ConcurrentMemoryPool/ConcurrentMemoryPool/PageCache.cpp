#include "PageCache.h"

PageCache PageCache::_sInst;

// ��ϵͳ����kҳ�ڴ�
void* PageCache::SystemAllocPage(size_t k)
{
	return ::SystemAlloc(k);
}

//Span* PageCache::NewSpan(size_t k)
//{
//	std::lock_guard<std::mutex> lock(_mtx);
//	_NewSpan(k);
//}

Span* PageCache::NewSpan(size_t k)
{
	std::lock_guard<std::recursive_mutex> lock(_mtx);

	// ���ֱ���������NPAGES�Ĵ���ڴ棬ֱ����ϵͳҪ
	if (k >= NPAGES)
	{
		void* ptr = SystemAllocPage(k);
		Span* span = new Span;
		span->_pageId = (ADDRES_INT)ptr >> PAGE_SHIFT;
		span->_n = k;

		{
			//std::lock_guard<std::mutex> lock(_map_mtx);
			_idSpanMap[span->_pageId] = span;
		}

		return span;
	}

	if (!_spanList[k].Empty())
	{
		return _spanList[k].PopFront();
	}

	for (size_t i = k+1; i < NPAGES; ++i)
	{
		// ��ҳ����С,�г�kҳ��span����
		// �г�i-kҳ�һ���������
		if (!_spanList[i].Empty())
		{

			// ͷ��
			/*Span* span = _spanList[i].Begin();
			_spanList->Erase(span);

			Span* splitSpan = new Span;
			splitSpan->_pageId = span->_pageId + k;
			splitSpan->_n = span->_n - k;

			span->_n = k;

			_spanList[splitSpan->_n].Insert(_spanList[splitSpan->_n].Begin(), splitSpan);

			return span;*/

			// β�г�һ��kҳspan
			Span* span = _spanList[i].PopFront();

			Span* split = new Span;
			split->_pageId = span->_pageId + span->_n - k;
			split->_n = k;

			// �ı��г���span��ҳ�ź�span��ӳ���ϵ
			{
				//std::lock_guard<std::mutex> lock(_map_mtx);
				for (PageID i = 0; i < k; ++i)
				{
					_idSpanMap[split->_pageId + i] = split;
				}
			}

			span->_n -= k;

			_spanList[span->_n].PushFront(span);

			return split;
		}
	}

	Span* bigSpan = new Span;
	void* memory = SystemAllocPage(NPAGES - 1);
	bigSpan->_pageId = (size_t)memory >> 12;
	bigSpan->_n = NPAGES - 1;
	// ��ҳ�ź�spanӳ���ϵ����

	{
		//std::lock_guard<std::mutex> lock(_map_mtx);
		for (PageID i = 0; i < bigSpan->_n; ++i)
		{
			PageID id = bigSpan->_pageId + i;
			_idSpanMap[id] = bigSpan;
		}
	}

	_spanList[NPAGES - 1].Insert(_spanList[NPAGES - 1].Begin(), bigSpan);

	return NewSpan(k);
}

Span* PageCache::MapObjectToSpan(void* obj)
{
	//std::lock_guard<std::mutex> lock(_map_mtx);

	//std::lock_guard<std::recursive_mutex> lock(_mtx);

	PageID id = (ADDRES_INT)obj >> PAGE_SHIFT;
	/*auto ret = _idSpanMap.find(id);
	if (ret != _idSpanMap.end())
	{
		return ret->second;
	}
	else
	{
		assert(false);
		return  nullptr;
	}*/

	Span* span = _idSpanMap.get(id);
	if (span != nullptr)
	{
		return span;
	}
	else
	{
		assert(false);
		return nullptr;
	}
}

void PageCache::ReleaseSpanToPageCache(Span* span)
{
	if (span->_n >= NPAGES)
	{

		{
			//std::lock_guard<std::mutex> lock(_map_mtx);
			//_idSpanMap.erase(span->_pageId);
			_idSpanMap.erase(span->_pageId);
		}
		void* ptr = (void*)(span->_pageId << PAGE_SHIFT);
		SystemFree(ptr);
		delete span;
		return;
	}

	std::lock_guard<std::recursive_mutex> lock(_mtx);

	// ���ǰ�����spanҳ�����кϲ�,����ڴ���Ƭ����

	// ��ǰ�ϲ�
	while (1)
	{
		PageID preId = span->_pageId - 1;
		//auto ret = _idSpanMap.find(preId);
		//// ���ǰһ��ҳ��span�����ڣ�δ���䣬������ǰ�ϲ�
		//if (ret == _idSpanMap.end())
		//{
		//	break;
		//}
		Span* preSpan = _idSpanMap.get(preId);
		if (preSpan == nullptr)
		{
			break;
		}

		// ���ǰһ��ҳ��span����ʹ���У�������ǰ�ϲ�
		if (preSpan->_usecount != 0)
		{
			break;
		}

		// ��ʼ�ϲ�...

		// ����128ҳ������Ҫ�ϲ���
		if (preSpan->_n + span->_n >= NPAGES)
		{
			break;
		}

		// �Ӷ�Ӧ��span�����н��������ٺϲ�
		_spanList[preSpan->_n].Erase(preSpan);

		span->_pageId = preSpan->_pageId;
		span->_n += preSpan->_n;

		// ����ҳ֮��ӳ���ϵ
		{
			//std::lock_guard<std::mutex> lock(_map_mtx);
			for (PageID i = 0; i < preSpan->_n; ++i)
			{
				_idSpanMap[preSpan->_pageId + i] = span;
			}
		}

		delete preSpan;
	}

	// ���ϲ�
	while (1)
	{
		PageID nextId = span->_pageId + span->_n;
		/*auto ret = _idSpanMap.find(nextId);
		if (ret == _idSpanMap.end())
		{
			break;
		}*/

		Span* nextSpan = _idSpanMap.get(nextId);
		if (nextSpan == nullptr)
		{
			break;
		}

		//Span* nextSpan = ret->second;
		if (nextSpan->_usecount != 0)
		{
			break;
		}

		// ����128ҳ������Ҫ�ϲ���
		if (nextSpan->_n + span->_n >= NPAGES)
		{
			break;
		}

		_spanList[nextSpan->_n].Erase(nextSpan);

		span->_n += nextSpan->_n;

		{
			//std::lock_guard<std::mutex> lock(_map_mtx);
			for (PageID i = 0; i < nextSpan->_n; ++i)
			{
				_idSpanMap[nextSpan->_pageId + i] = span;
			}
		}

		delete nextSpan;
	}

	// �ϲ����Ĵ�span�����뵽��Ӧ��������
	_spanList[span->_n].PushFront(span);
}