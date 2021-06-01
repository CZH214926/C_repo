#pragma once

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _t;

	enum Colour _col;

	RBTreeNode(const T& t)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _t(t)
		, _col(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeIterator<T, Ref, Ptr> Self;
	typedef RBTreeNode<T> Node;
	Node* _node;
	RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_t;
	}

	Ptr operator->()
	{
		return &(_node->_t);
	}

	// ++it
	Self operator++()
	{
		// 中序的下一个
		if (_node->_right)
		{
			// 右树的最左节点
			Node* cur = _node->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			// 右为空，_node所在的子树已经访问完了，
			// 沿着路径往跟走，找孩子不是父亲的右的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				// 直到 parent == nullptr，或者parent->right != cur此时的parent是下一个
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}
	Self operator--()
	{
		if (_node->_left)
		{
			Node* cur = _node->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	bool operator!=(const Self s) const
	{
		return _node != s._node;
	}
};


// set<K>    -> RBTree<K, K>
// map<K, V> -> RBTree<K,pair<const K, V>>
template<class K, class T, class KeyOfT>
struct RBTree
{
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return Iterator(cur);
	}

	Iterator End()
	{
		return Iterator(nullptr);
	}

	typedef RBTreeNode<T> Node;

	//bool Find(const K& k);
	pair<Node*, bool> Insert(const T& t)
	{
		KeyOfT koft;

		if (_root == nullptr)
		{
			_root = new Node(t);

			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_t) < koft(t))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (koft(cur->_t) > koft(t))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		cur = new Node(t); // RED
		if (koft(parent->_t) < koft(t))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		Node* newnode = cur;

		// 
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				// 情况1：u存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else //  情况2+3：u不存在或存在且为黑
				{
					//        g
					//      p
					//   c
					//
					if (cur == parent->_left)  // 
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//        g
						//      p
						//         c
						//
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else // grandfather->_right == parent
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else //  情况2+3：u不存在或存在且为黑
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}


		_root->_col = BLACK;
		return make_pair(newnode, true);
	}


	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		};
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;

		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
		}

		subR->_parent = parentParent;
	}

private:
	Node* _root = nullptr;
};


//void TestRBTree()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15};
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 16, 3, 7, 11, 9, 26, 18, 14, 15};
//	RBTree<int, int> t;
//
//	for (auto e : a)
//	{
//		if (e == 18)
//		{
//			int i = 0;
//		}
//
//		t.Insert(make_pair(e, e));
//		cout << e << ":";
//		cout << t.IsBalance() << endl;
//	}
//
//	t.InOrder();
//
//	cout << t.IsBalance() << endl;
//}


