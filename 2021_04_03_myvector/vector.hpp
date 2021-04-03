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
		//�޲ι���
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//����������
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
		//��������
		void swap(const vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		//��������
		vector<T>(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			this->swap(tmp);
		}
		//��ֵ���������
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		//��������
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		//[]���������
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//�ȼ���size������������¿��ռ䣬_start��ı�
				size_t sz = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T)*sz);
				delete[] _start;
				_start = tmp;

				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		//���õ���������
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
		//��鱸�ÿռ��Ƿ�����
		void check_capacity()
		{
			if (_finish == _endofstorage) {
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
		}
		//β��Ԫ��
		void push_back(const T& val) {
			check_capacity();
			*_finish = val;
			++_finish;
		}
       //βɾԪ��
		void pop_back() {
			assert(_finish > _start);
			_finish--;
		}
		//��ĳλ�ò���Ԫ��
		iterator insert(iterator pos, const T& val) {
			//������λ���Ƿ�Ϸ�
			assert(pos >= _start && pos <= _finish);
			//��������������ݵ��¿����µĿռ䣬�������������ƶ�Ԫ�ر�Ȼ����
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
		//Ϊ��������ĵ�������ʧЧ����������ƣ������������һ��������
		void insert(iterator& pos, const T& val) {
			//������λ���Ƿ�Ϸ�
			assert(pos >= _start && pos <= _finish);
			//��������������ݵ��¿����µĿռ䣬�������������ƶ�Ԫ�ر�Ȼ����
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
		//ɾ��ĳλ�õ�Ԫ��
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			//�ƶ�����
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
