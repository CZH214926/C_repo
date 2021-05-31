#pragma once

enum Colour
{
	RED,
	BLACK
};


template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	enum Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	// ...

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);

			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		cur = new Node(kv); // RED
		if (parent->_kv.first < kv.first)
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

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool _CheckRedCol(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (root->_col == RED)
		{
			Node* parent = root->_parent;
			if (parent->_col == RED)
			{
				cout << "违反规则2：存在连续的红色节点" << endl;
				return false;
			}
		}

		return _CheckRedCol(root->_left) && _CheckRedCol(root->_right);
	}

	bool _CheckBlackNum(Node* root, int blackNum, int trueNum)
	{
		if (root == nullptr)
		{
			// 当走到NULL时， blackNum 这条路径黑色节点的数量
			return trueNum == blackNum;
		}

		if (root->_col == BLACK)
		{
			blackNum++;
		}

		return  _CheckBlackNum(root->_left, blackNum, trueNum)
			&& _CheckBlackNum(root->_right, blackNum, trueNum);
	}

	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			cout << "违反规则1：根节点是红色的"<<endl;
			return false;
		}

		int trueNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++trueNum;
			}
			cur = cur->_left;
		}

		int blackNum = 0;
		return _CheckRedCol(_root)
			&& _CheckBlackNum(_root, blackNum, trueNum);
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