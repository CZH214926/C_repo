#pragma once
#include "RBTree.hpp"

namespace czh
{
	template<class K, class V>
	class map
	{
		struct MapKOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, MapKOfT>::Iterator iterator;
		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V());
			return ret.first->second;
		}
		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
	private:
		RBTree<K, pair<const K, V>, MapKOfT> _t;
	};

	void test_map()
	{
		map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(2, 1));
		m.insert(make_pair(3, 1));

	}
}
