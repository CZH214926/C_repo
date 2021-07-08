#include "CentralCache.h"
#include "PageCache.h"

CentralCache CentralCache::_sInst;

Span* CentralCache::GetOneSpan(SpanList& list, size_t size)
{
	// ����spanlist��ȥ�һ����ڴ��span
	Span* it = list.Begin();
	while (it != list.End())
	{
		if (it->_list)
		{
			return it;
		}

		it = it->_next;
	}

	// �ߵ����������span��û���ڴ��ˣ�ֻ����pagecache
	Span* span = PageCache::GetInstance()->NewSpan(SizeClass::NumMovePage(size));
	// �зֺù���list��
	char* start = (char*)(span->_pageId << PAGE_SHIFT);
	char* end = start + (span->_n << PAGE_SHIFT);
	while (start < end)
	{
		char* next = start + size;
		// ͷ��
		NextObj(start) = span->_list;
		span->_list = start;

		start = next;
	}
	span->_objsize = size;

	list.PushFront(span);

	return span;
}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t n, size_t size)
{
	size_t i = SizeClass::Index(size);
	//_spanLists[i].Lock();


	std::lock_guard<std::mutex> lock(_spanLists[i]._mtx);

	Span* span = GetOneSpan(_spanLists[i], size);

	// �ҵ�һ���ж����span���ж��ٸ�����
	size_t j = 1;
	start = span->_list;
	void* cur = start;
	void* prev = start;
	while (j <= n && cur != nullptr)
	{
		prev = cur;
		cur = NextObj(cur);
		++j;
		span->_usecount++;
	}

	span->_list = cur;
	end = prev;
	NextObj(prev) = nullptr;

	//_spanLists[i].Unlock();

	return j-1;
}

void CentralCache::ReleaseListToSpans(void* start, size_t byte_size)
{
	size_t i = SizeClass::Index(byte_size);
	std::lock_guard<std::mutex> lock(_spanLists[i]._mtx);

	while (start)
	{
		void* next = NextObj(start);

		// ��start�ڴ�������ĸ�span
		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);

		// �Ѷ�����뵽span�����list��
		NextObj(start) = span->_list;
		span->_list = start;
		span->_usecount--;
		// _usecount == 0˵�����span���г�ȥ�Ĵ���ڴ�
		// ����������
		if (span->_usecount == 0)
		{
			_spanLists[i].Erase(span);
			span->_list = nullptr;
			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}

		start = next;
	}
}
