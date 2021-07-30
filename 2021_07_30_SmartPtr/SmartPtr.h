#pragma once

// C++98�е�����ָ���� auto_ptr �����ǲ��Ƽ��ã����¶�������
// C++11������3������ָ�룬unique_ptr��shared_ptr, weak_ptr
// unique�򵥴ֱ�����ֹ�����͸�ֵ
namespace czh
{
	// C++98 ��Դת�ƣ��ص��¿���ʱԭ��������
	// ʧ�ܵ���ƣ��������й�˾�����鲻Ҫʹ����
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* p)
			:_ptr(p)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//operator=

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr
		}

		T* get()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_auto_ptr()
	{
		auto_ptr<int> ap1(new int);
		auto_ptr<int> ap2(ap1);
		auto_ptr<int> ap3(ap2);

		//*ap1 = 1;


		//int* p1 = new int;
		//int* p2 = p1;
	}
	// C++11 unique_ptr shared_ptr weak_ptr
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* p)
			:_ptr(p)
		{}
		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* get()
		{
			return _ptr;
		}
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
	};
	void test_unique_ptr()
	{
		unique_ptr<int> up(new int);
		*up = 12;	
	}
	template<class T>
	class shared_ptr
	{
	public:
		explicit shared_ptr(T* p = nullptr)
			:_ptr(p)
			, _pCount(new int(1))
			, _pMtx(new mutex)
		{

		}
		// ++���ü���
		void AddUseCount()
		{
			unique_lock<mutex> lock(*_pMtx);
			++(*_pCount);
		}
		void Release()
		{
			// ��������Ϊ���ͷ��ڶ��ϵ�����Դ���趨��,�����ü����������ʱ��
			// ���������ҲҪ�ͷŵ�
			bool dFlag = false;
			_pMtx->lock();
			if (--(*_pCount) == 0)
			{
				if (_ptr)
				{
					cout << "delete:" << _ptr << endl;
					delete _ptr;
				}
				delete _pCount;
				dFlag = true;
			}
			_pMtx->unlock();

			if (dFlag)
				delete _pMtx;
		}
		~shared_ptr()
		{
			Release();
		}
		// ��������==>���ü���Ҫ++
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMtx(sp._pMtx)
		{
			AddUseCount();
		}
	    // ��ֵ����==>Ҫ���ǲ��ܸ��Լ���ֵ
		// sp1 = sp2;
		// sp1�����ü���Ҫ--,��Ƭsp2�����ü���Ҫ++
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				this->Release();
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMtx = sp._pMtx;

				AddUseCount();
			}
			return *this;
		}
		// ��ָ��һ������Ϊ
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T* get() const
		{
			return _ptr;
		}
		int use_count()
		{
			return *_pCount;
		}
	private:
		T* _ptr;// ����ָ����������Դ�ĵ�ַ
		int* _pCount; // ����ָ�����������ü������洢�ڶ���
		mutex* _pMtx; // ����Ļ�����
	};
	void test_shared_ptr1()
	{
		shared_ptr<int> sp1(new int(0));
		shared_ptr<int> sp2(sp1);

		shared_ptr<int> sp3(new int(1));
		shared_ptr<int> sp4(sp3);
		shared_ptr<int> sp5(sp3);

		// sp1 = sp1
		// sp1 = sp2

		sp1 = sp3;
		//sp2 = sp3;

	}
	struct Date
	{
		int _year = 1;
		int _month = 1;
		int _day = 1;
	};
	void SharePtrFunc(std::shared_ptr<Date>& sp, size_t n)
	{
		cout << sp.get() << endl;
		for (size_t i = 0; i < n; ++i)
		{
			// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
			// Ҫ��֤�������ü������̰߳�ȫ
			std::shared_ptr<Date> copy(sp);

			// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ��������տ����Ľ������һ���Ǽ���2n
			copy->_year++;
			copy->_month++;
			copy->_day++;
		}
	}
	void test_shared_ptr_thread_safe()
	{
		std::shared_ptr<Date> p(new Date);
		cout << p.get() << endl;
		cout << p.use_count() << endl;


		const size_t n = 100000;
		thread t1(SharePtrFunc, p, n);
		thread t2(SharePtrFunc, p, n);

		t1.join();
		t2.join();

		cout << p->_year << endl;
		cout << p->_month << endl;
		cout << p->_day << endl;


		cout << p.get() << endl;
		cout << p.use_count() << endl;
	}
	// shared_ptr ��ѭ����������
	struct ListNode
	{
		int val;
		
		/*std::shared_ptr<ListNode> next;
		std::shared_ptr<ListNode> prev;*/
		// ʹ��weak_ptr ���ѭ�����õ�����
		std::weak_ptr<ListNode> next;
		std::weak_ptr<ListNode> prev;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};
	void test_cycle_ref()
	{
		//ListNode* p = new ListNode;
		//delete p;

		std::shared_ptr<ListNode> node1(new ListNode);
		std::shared_ptr<ListNode> node2(new ListNode);

		cout << node1.use_count() << endl;
		cout << node2.use_count() << endl;

		node1->next = node2;
		node2->prev = node1;

		cout << node1.use_count() << endl;
		cout << node2.use_count() << endl;
	}
}