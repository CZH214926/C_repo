#pragma once

// ��ɢ�з��� -- ����̽��
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

// �ػ�
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
		State _state = EMPTY; // ״̬
		T _t;
	};

	template<class K, class T, class HashFunc = Hash<K>>
	class HashTable
	{
	public:
		bool Insert(const T& t)
		{
			// ��������>0.7������
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
				//		// ����̽�������±��λ��
				//	}
				//}

				//newtables.swap(_tables);

				// �����ɱ����ݲ���newht
				HashTable<K, T, HashFunc> newht;
				newht._tables.resize(newsize);
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
					{
						// ���ó�ͻʱ̽����߼�
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
			// ����̽�⣬��һ����λ��
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

			// ����̽�⣬��һ����λ��
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
				// αɾ����
				ret->_state = DELETE;
				return true;
			}
		}

	private:
		//T* _table;
		//size_t _size;
		//size_t _capacity;
		vector<HashNode<T>> _tables;
		size_t	  _size = 0; // ��Ч���ݸ���
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

		// �ϸ���˵��ֻҪK�����Ͳ�֧��ȡģ����Ҫ��һ���º���������
		HashTable<Date, Date> dateht;

		// 
		Hash<string> strhf;
		cout << strhf("abcd") << endl;
		cout << strhf("acbd") << endl;
		cout << strhf("aadd") << endl;
	}
}


// ��ɢ��
// ��ϣͰ
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

	// ǰ������
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
			// 1����ǰͰ�������ݣ�������
			// 2����ǰͰû�����ݣ�������һ��Ͱ���ӵ�һ����ʼ
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				// �ҵ���һ��Ͱ
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
					// û���ҵ���һ��Ͱ
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
			// �������� == 1ʱ����
			if (_size == _tables.size())
			{
				size_t newsize = GetNextPrime(_tables.size());
				//HashTable<K, T, KeyOfT, hash> newht;
				vector<Node*> newtables;
				newtables.resize(newsize, nullptr);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					// �ɱ��нڵ�ֱ��ȡ�����ҵ��±�
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = HashFunc(kot(cur->_t), newtables.size());
						// ͷ��
						cur->_next = newtables[index];
						newtables[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				newtables.swap(_tables);
			}


			size_t index = HashFunc(kot(t), _tables.size());

			// ����t���ڲ���
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_t) == kot(t))
					return make_pair(Iterator(cur, this), false);

				cur = cur->_next;
			}

			// ͷ�嵽����Ͱ
			Node* newnode = new Node(t);
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			return make_pair(Iterator(newnode, this), true);
		}

		Iterator Find(const K& key)
		{
			size_t index = HashFunc(kot(t), _tables.size());

			// ����t���ڲ���
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

			// ����t���ڲ���
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_t) == kot(t))
				{
					// ɾ��
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
		size_t _size = 0; // ��Ч���ݵĸ���
	};


}