#pragma once
#include <assert.h>
using std::cout;
using std::endl;

namespace czh{
	//list �н��Ķ���
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
	// �����������
	template<class T, class Ref, class Ptr>
	struct __list_iterator{

		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;

		node* _node;

	    __list_iterator(node* node = nullptr)
			:_node(node)  //֧����ʽ����ת��
		{}
		//��������͸�ֵ�����������Ĭ�ϾͿ��ԣ���Ϊ��Ҫ����ǳ����
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
		// *it �Ե����������ã���ʵ�ǽ�������
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
		// ������ϵ��
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
		
		//���캯��ϵ��
		// �޲ι���
		list()
		{
			CreateHead();
		}
		//����������
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
		// n val ����
		list(int n, const T& val = T())
		{
			CreateHead();
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//��������
		list(const list<T>& lt)
		{
			CreateHead();
			list<T> tmp(lt.begin(), lt.end());
			this->swap(tmp);
		}
		//��������
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		//���ڿ�������͸�ֵ���صĽ�������
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}
		//��ֵ����
		list<T>& operator=(list<T> lt)
		{
			this->swap(lt);
			return *this;
		}
		//�޸�listϵ��
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
			//node* newnode = new node(x);//�ٿ��ٿռ��ͬʱ�����ù��캯����ʼ��
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
		//erase  ��д
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
		//insert   ��д
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
		//���list
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				//erase(it++);
			}
		}

		// list����ϵ��
		T& front()
		{
			return *begin();
			//�Ե�����������* �ǵ������ڷ�װ��ԭ�����ָ��ָ��Ľ�������
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
		//������ز���
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
		node* _head;//˫���ͷѭ������
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