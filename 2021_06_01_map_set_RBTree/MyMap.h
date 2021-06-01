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
		pair<RBTreeNode<pair<const K, V>>*, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
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
