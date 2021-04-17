#pragma once

//仿函数
template<class T>
class Less{
public:
	bool operator()(const T& t1, const T& t2) const
	{
		return t1 < t2;
	}
};

template<class T>
class Greater{
public:
	bool operator()(const T& t1, const T& t2) const
	{
		return t1 > t2;
	}
};
namespace czh{

	template<class T, class Container = vector<T>, class Compare = Greater<T>>
	class priority_queue {

	public:
		priority_queue() = default;
		/*priority_queue()
		{}*/

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			//利用向下调整算法，从下到上建堆
			/*for (int i = (_con.size() - 2) / 2; i >= 0; i--)
			{
			AdjustDown(i);
			}*/
			////利用向上调整算法，从上到下调整
			for (size_t i = 1; i < _con.size(); i++)
			{
				AdjustUp(i);
			}
		}
		void push(const T& data)
		{
			_con.push_back(data);
			// 向上调整
			AdjustUp(_con.size() - 1);
		}
		void pop()
		{
			if (empty()) return;

			swap(_con.front(),_con.back());
			_con.pop_back();
			AdjustDown(0);
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() const
		{ 
			return _con.front();
		}
		bool empty() const
		{
			return _con.empty();
		}
	private:
		//向上调整算法
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) >> 1;
			while (child > 0)
			{
				/*if (_con[child] > _con[parent])*/
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) >> 1;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(int parent)
		{
			Compare com;
			size_t child = 2 * parent + 1;
			while (child < _con.size())
			{
				/*if (child + 1 < _con.size() && _con[child + 1] < _con[child])*/
				if (child + 1 < _con.size() && com(_con[child + 1], _con[child]))
				{
					child++;
				}
				/*if (_con[child] > _con[parent])*/
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}
		//向下调整算法
		Container _con;
	};
}