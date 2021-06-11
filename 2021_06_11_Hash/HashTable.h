#pragma once

// 闭散列方法 -- 线性探测
// set<K>->HashTable<K, K>
// map<K, V>->HashTable<K, pair<K, V>>

template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

// 特化
template<>
struct Hash < string >
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			//hash += ch;
			hash = hash * 131 + ch;
		}

		return hash;
	}
};

static size_t GetNextPrime(size_t prime)
{
	static const int PRIMECOUNT = 28;
	static const size_t primeList[PRIMECOUNT] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}

	return primeList[i];
}


namespace Close
{

	enum State
	{
		EXIST,
		EMPTY,
		DELETE,
	};

	template<class T>
	struct HashNode
	{
		State _state = EMPTY; // 状态
		T _t;
	};

	template<class K, class T, class HashFunc = Hash<K>>
	class HashTable
	{
	public:
		bool Insert(const T& t)
		{
			// 负载因子>0.7就增容
			if (_tables.size() == 0 || _size * 10 / _tables.size() == 7)
			{
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				size_t newsize = GetNextPrime(_tables.size());

				// 
				//vector<HashNode<T>> newtables;
				//newtables.resize(newsize);

				//for (size_t i = 0; i < _tables.size(); ++i)
				//{
				//	if (_tables[i]._state == EXIST)
				//	{
				//		// 弹性探测找在新表的位置
				//	}
				//}

				//newtables.swap(_tables);

				// 遍历旧表，数据插入newht
				HashTable<K, T, HashFunc> newht;
				newht._tables.resize(newsize);
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
					{
						// 复用冲突时探测的逻辑
						newht.Insert(e._t);
					}
				}

				_tables.swap(newht._tables);
			}

			HashNode<T>* ret = Find(t);
			if (ret)
				return false;

			HashFunc hf;

			size_t start = hf(t) % _tables.size();
			// 线性探测，找一个空位置
			size_t index = start;
			size_t i = 1;
			while (_tables[index]._state == EXIST)
			{
				index = start + i;
				index %= _tables.size();

				++i;
			}

			_tables[index]._t = t;
			_tables[index]._state = EXIST;
			_size++;

			return true;
		}

		HashNode<T>* Find(const K& key)
		{
			HashFunc hf;

			size_t start = hf(key) % _tables.size();

			// 线性探测，找一个空位置
			size_t index = start;
			size_t i = 1;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._t == key
					&& _tables[index]._state == EXIST)
				{
					return &_tables[index];
				}

				index = start + i;
				index %= _tables.size();

				++i;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashNode<T>* ret = Find(key);
			if (ret == false)
			{
				return false;
			}
			else
			{
				// 伪删除法
				ret->_state = DELETE;
				return true;
			}
		}

	private:
		//T* _table;
		//size_t _size;
		//size_t _capacity;
		vector<HashNode<T>> _tables;
		size_t	  _size = 0; // 有效数据个数
	};

	struct Date
	{

	};

	void TestHashTable()
	{
		HashTable<int, int> ht;
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(16);
		ht.Insert(17);
		ht.Insert(25);
		ht.Insert(35);
		ht.Insert(45);
		ht.Insert(55);

		struct StrHash
		{
			size_t operator()(const string& s)
			{
				size_t hash = 0;
				for (auto ch : s)
				{
					hash += ch;
				}

				return hash;
			}
		};

		//HashTable<string, string, StrHash> strht;
		HashTable<string, string> strht;
		strht.Insert("sort");
		strht.Insert("insert");

		// 严格来说，只要K的类型不支持取模，就要配一个仿函数才能用
		HashTable<Date, Date> dateht;

		// 
		Hash<string> strhf;
		cout << strhf("abcd") << endl;
		cout << strhf("acbd") << endl;
		cout << strhf("aadd") << endl;
	}
}


// 开散列
// 哈希桶
namespace Open
{
	template<class T>
	struct HashLinkNode
	{
		T _t;
		HashLinkNode<T>* _next;

		HashLinkNode(const T& t)
			:_t(t)
			, _next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class hash>
	class HashTable;

	template<class K, class T,class Ref, class Ptr, class KeyOfT, class hash>
	struct HashIterator
	{
		typedef HashIterator<K, T, Ref, Ptr, KeyOfT, hash> Self;
		typedef HashLinkNode<T> Node;
		Node* _node;
		HashTable<K, T, KeyOfT, hash>* _pht;

		HashIterator(Node* node, HashTable<K, T, KeyOfT, hash>* pht)
			:_node(node)
			, _pht(pht)
		{}

		Ref operator*()
		{
			return _node->_t;
		}

		Ptr operator->()
		{
			return &(_node->_t);
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		// ++it
		Self operator++()
		{
			// 1、当前桶还有数据，继续走
			// 2、当前桶没有数据，跳到下一个桶，从第一个开始
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				// 找到下一个桶
				size_t index = _pht->HashFunc(kot(_node->_t), _pht->_tables.size());
				++index;
				while (index < _pht->_tables.size())
				{
					if (_pht->_tables[index])
					{
						_node = _pht->_tables[index];
						break;
					}
					else
					{
						++index;
					}
				}

				if (index == _pht->_tables.size())
				{
					// 没有找到下一个桶
					_node = nullptr;
				}
			}

			return *this;
		}

	};


	template<class K, class T, class KeyOfT, class hash = Hash<K>>
	class HashTable
	{
		typedef HashLinkNode<T> Node;
		friend struct HashIterator < K, T, T&, T*, KeyOfT, hash > ;
	public:
		typedef HashIterator<K, T, T&, T*, KeyOfT, hash> Iterator;
		typedef HashIterator<K, T, const T&, const T*, KeyOfT, hash> ConstIterator;

		//friend Iterator;


		Iterator Begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i])
				{
					return Iterator(_tables[i], this);
				}
			}

			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		size_t HashFunc(const K& key, size_t n)
		{
			hash hf; 
			size_t ki = hf(key);
			return ki % n;
		}

		pair<Iterator, bool> Insert(const T& t)
		{
			KeyOfT kot;
			// 负载因子 == 1时增容
			if (_size == _tables.size())
			{
				size_t newsize = GetNextPrime(_tables.size());
				//HashTable<K, T, KeyOfT, hash> newht;
				vector<Node*> newtables;
				newtables.resize(newsize, nullptr);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 旧表中节点直接取下来挂到新表
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = HashFunc(kot(cur->_t), newtables.size());
						// 头插
						cur->_next = newtables[index];
						newtables[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				newtables.swap(_tables);
			}


			size_t index = HashFunc(kot(t), _tables.size());

			// 查找t在在不在
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_t) == kot(t))
					return make_pair(Iterator(cur, this), false);

				cur = cur->_next;
			}

			// 头插到链表桶
			Node* newnode = new Node(t);
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			return make_pair(Iterator(newnode, this), true);
		}

		Iterator Find(const K& key)
		{
			size_t index = HashFunc(kot(t), _tables.size());

			// 查找t在在不在
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_t) == kot(t))
					return iterator(cur, this);

				cur = cur->_next;
			}

			return End();
		}

		bool Erase(const K& key)
		{
			size_t index = HashFunc(kot(t), _tables.size());

			// 查找t在在不在
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_t) == kot(t))
				{
					// 删除
					if (prev == nullptr)
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}

			}

			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _size = 0; // 有效数据的个数
	};


}