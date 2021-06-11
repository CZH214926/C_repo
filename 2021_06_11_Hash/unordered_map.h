#pragma once
#include "HashTable.h"

namespace czhS
{
	template<class K, class V, class hash = Hash<K>>
	class unordered_map
	{

		struct MapKOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename Open::HashTable<K, pair<const K, V>, MapKOfT, hash>::Iterator iterator;
		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return	_ht.End();
		}
		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		Open::HashTable<K, pair<const K, V>, MapKOfT, hash> _ht;
	};

	void test_unordered_map()
	{
	    czh::unordered_map<string, string> dict;
		dict["sort"] = "ÅÅÐò";
		dict["hash"] = "¹þÏ£";

		for (auto& e : dict)
		{
			cout << e.first << ":"<<e.second <<endl;
		}
	}
}
