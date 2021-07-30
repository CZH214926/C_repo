#pragma once

// C++98中的智能指针是 auto_ptr ，但是不推荐用，导致对象悬空
// C++11引入了3个智能指针，unique_ptr，shared_ptr, weak_ptr
// unique简单粗暴，禁止拷贝和赋值
namespace czh
{
	// C++98 资源转移，回导致拷贝时原对象悬空
	// 失败的设计：几乎所有公司都建议不要使用它
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
		// ++引用计数
		void AddUseCount()
		{
			unique_lock<mutex> lock(*_pMtx);
			++(*_pCount);
		}
		void Release()
		{
			// 这个标记是为了释放在堆上的锁资源而设定的,当引用计数减到零的时候
			// 这个锁我们也要释放掉
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
		// 拷贝构造==>引用计数要++
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMtx(sp._pMtx)
		{
			AddUseCount();
		}
	    // 赋值重载==>要考虑不能给自己赋值
		// sp1 = sp2;
		// sp1的引用计数要--,碎片sp2的引用计数要++
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
		// 像指针一样的行为
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
		T* _ptr;// 智能指针所管理资源的地址
		int* _pCount; // 智能指针对象共享的引用计数，存储在堆上
		mutex* _pMtx; // 共享的互斥锁
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
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			// 要保证里面引用计数的线程安全
			std::shared_ptr<Date> copy(sp);

			// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
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
	// shared_ptr 的循环引用问题
	struct ListNode
	{
		int val;
		
		/*std::shared_ptr<ListNode> next;
		std::shared_ptr<ListNode> prev;*/
		// 使用weak_ptr 解决循环引用的问题
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