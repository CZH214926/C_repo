#pragma once
#include <assert.h>

namespace czh{
	template<class T>
	class vector{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		bool empty()
		{
			return _start == _finish;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		//无参构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//迭代器构造
		template<class Inputiterator>
		vector(Inputiterator first, Inputiterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(last - first);
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		//交换函数
		void swap(const vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		//拷贝构造
		vector<T>(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			this->swap(tmp);
		}
		//赋值运算符重载
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		//[]运算符重载
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//先计算size，否则后面重新开空间，_start会改变
				size_t sz = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T)*sz);
				delete[] _start;
				_start = tmp;

				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		//会用到匿名对象
		void resize(size_t n, const T& val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		//检查备用空间是否被用完
		void check_capacity()
		{
			if (_finish == _endofstorage) {
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
		}
		//尾插元素
		void push_back(const T& val) {
			check_capacity();
			*_finish = val;
			++_finish;
		}
       //尾删元素
		void pop_back() {
			assert(_finish > _start);
			_finish--;
		}
		//在某位置插入元素
		iterator insert(iterator pos, const T& val) {
			//检查插入位置是否合法
			assert(pos >= _start && pos <= _finish);
			//插入可能引起扩容导致开辟新的空间，如果不处理后面移动元素必然出错
			size_t posi = pos - _start;
			check_capacity();
			pos = _start + posi;

			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}
		//为了让外面的迭代器不失效可以这样设计，但是这样设计一定的问题
		void insert(iterator& pos, const T& val) {
			//检查插入位置是否合法
			assert(pos >= _start && pos <= _finish);
			//插入可能引起扩容导致开辟新的空间，如果不处理后面移动元素必然出错
			size_t posi = pos - _start;
			check_capacity();
			pos = _start + posi;

			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
		}
		//删除某位置的元素
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			//移动数据
			iterator it = pos + 1;
			while (it != _finish) {
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
