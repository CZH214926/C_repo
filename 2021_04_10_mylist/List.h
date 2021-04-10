#pragma once
#include <assert.h>
using std::cout;
using std::endl;

namespace czh{
	//list 中结点的定义
	template<class T>
	struct __list_node{
		T _data;
		__list_node<T>* _prev;
		__list_node<T>* _next;

		__list_node(const T& x = T())
			:_data(x)
			,_prev(nullptr)
			, _next(nullptr)
		{}
	};
	// 迭代器的设计
	template<class T, class Ref, class Ptr>
	struct __list_iterator{

		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;

		node* _node;

	    __list_iterator(node* node = nullptr)
			:_node(node)  //支持隐式类型转换
		{}
		//拷贝构造和赋值运算符重载用默认就可以，因为需要的是浅拷贝
		// it1 == it2
		bool operator==(const self& s)const 
		{
			return _node == s._node;
		}
		// it1 != it2
		bool operator!=(const self& s)const
		{
			return !(*this == s);
		}
		// ++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		// it++
		self operator++(int)
		{
			self tmp(*this);
			++*this;
			return tmp;
		}
		// --it
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		// it--
		self operator--(int)
		{
			self tmp = *this;
			--*this;
			return tmp;
		}
		// *it 对迭代器解引用，其实是结点的数据
		Ref operator*() const
		{
			return _node->_data;
		}
		// it->
		Ptr operator->() const
		{
			return &(_node->_data);
	      //return &(this->operator*());
		}
	};
	template<class T>
	class list{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iteraor;
		// 迭代器系列
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iteraor begin() const
		{
			return _head->_next;
		}
		const_iteraor end() const
		{
			return _head;
		}
		
		//构造函数系列
		// 无参构造
		list()
		{
			CreateHead();
		}
		//迭代器构造
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		// n val 构造
		list(int n, const T& val = T())
		{
			CreateHead();
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//拷贝构造
		list(const list<T>& lt)
		{
			CreateHead();
			list<T> tmp(lt.begin(), lt.end());
			this->swap(tmp);
		}
		//析构函数
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		//用于拷贝构造和赋值重载的交换函数
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}
		//赋值重载
		list<T>& operator=(list<T> lt)
		{
			this->swap(lt);
			return *this;
		}
		//修改list系列
		void push_back(const T& x)
		{
			//node* newnode = new node(x);
			//node* tail = _head->_prev;
			//// _head  ...  tail  newnode
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			//node* newnode = new node(x);//再开辟空间的同时，调用构造函数初始化
			//node* realhead = _head->_next;
			//newnode->_prev = _head;
			//_head->_next = newnode;
			//newnode->_next = realhead;
			//realhead->_prev = newnode;
			insert(begin(), x);
		}
		void pop_back()
		{
			/*if (_head->_next != nullptr)
			{
				delete _head->prev;
			}*/
			erase(--end());
		}
		void pop_front()
		{
			/*if (_head->_prev != nullptr)
			{
				delete _head->prev;
			}*/
			erase(begin());
		}
		//erase  重写
		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* cur = pos._node;
			node* next = cur->_next;
			node* prev = cur->_prev;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return iterator(next);
		}
		//insert   重写
		iterator insert(iterator pos, const T& x)
		{
			// prev newnode cur
			node* newnode = new node(x);
			node* cur = pos._node;
			node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}
		//清空list
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				//erase(it++);
			}
		}

		// list访问系列
		T& front()
		{
			return *begin();
			//对迭代器解引用* 是迭代器内封装的原生结点指针指向的结点的数据
		}
		const T& front() const
		{
			return *begin();
		}
		T& back()
		{
			return *(--end());
		}
		const T& back() const
		{
			return *(--end());
		}
		//容量相关操作
		size_t size() const
		{
			size_t count = 0;
			const_iteraor it = begin();
			while (it != end())
			{
				++it;
				++count;
			}
			return count;
		}
		bool empty()
		{
			return _head->_next == _head;
		}
	private:
		void CreateHead()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	private:
		node* _head;//双向带头循环链表
	};
	template<class T>
	void PrintList(const list<T>& l)
	{
		auto it = l.begin();
		while (it != l.end())
		{
			std::cout << *it << " ";
			++it;
		}
		cout << std::endl;
	}
}