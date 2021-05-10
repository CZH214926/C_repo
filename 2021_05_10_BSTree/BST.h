#pragma once

// key模型的二叉搜索树
//template<class K>
//struct BSTreeNode{
//	K _val;
//	struct BSTreeNode<K>* _left;
//	struct BSTreeNode<K>* _right;
//	BSTreeNode(const K& val) :_val(val), _left(nullptr), _right(nullptr){}
//};
//
//template<class K> //key
//class BSTree{
//	typedef BSTreeNode<K> Node;
//public:
//	bool insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (key > cur->_val)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (key < cur->_val)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;//目前的BST,不允许有重复的值
//			}
//		}
//		Node* node = new Node(key);
//		if (key > parent->_val)
//		{
//			parent->_right = node;
//		}
//		else
//		{
//			parent->_left = node;
//		}
//		return true;
//	}
//	//中序遍历
//	void _Inorder(Node* root)
//	{
//		if (root == nullptr) return;
//		_Inorder(root->_left);
//		cout << root->_val << " ";
//		_Inorder(root->_right);
//	}
//	void Inorder()
//	{
//		_Inorder(_root);
//		cout << endl;
//	}
//	const Node* Find(const K& key) const 
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (key > cur->_val)
//			{
//				cur = cur->_right;
//			}
//			else if (key < cur->_val)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return  nullptr;
//	}
//	// 重点理解
//	bool Erase(const K& key)
//	{
//		// 叶子节点
//		// 单孩子结点
//		// 双孩字的结点
//
//		//先找到待删除的结点和其父结点
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (key > cur->_val)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (key < cur->_val)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				//此时已经找到了 key 所在的结点，准备删除
//				// 左为空,右为空，左右都不为空
//				if (cur->_left == nullptr)
//				{
//					//极端情况 要删除的结点是BST的根节点
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					//类比左为空的情况
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//					delete cur;
//				}
//				else
//				{
//					// 两个孩子的结点
//					// 找到 cur 右树的最左结点(最小)，直接用其值覆盖cur的结点然后删除右树的最左结点
//					Node* smParent = cur;
//					Node* subMin = cur->_right;
//					while (subMin->_left)
//					{
//						smParent = subMin;
//						subMin = subMin->_left;
//					}
//					cur->_val = subMin->_val;
//					//subMin一定是左为空的结点,现在覆盖完，待删除的结点就是subMIN
//					if (subMin == smParent->_left)
//					{
//						smParent->_left = subMin->_right;
//					}
//					else
//					{
//						smParent->_right = subMin->_right;
//					}
//					delete subMin;
//				}
//				return true;
//			}
//		}
//		return false;
//	}
//private:
//	Node* _root = nullptr;//根节点
//};

// key - value 模型的二叉搜索树
template<class K, class V>
struct BSTreeNode{
	const K _key;
	V _value;

	struct BSTreeNode<K,V>* _left;
	struct BSTreeNode<K,V>* _right;

	BSTreeNode(const K& key, const V& value) 
		:_key(key)
		,_value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V> //key
class BSTree{
	typedef BSTreeNode<K,V> Node;
public:
	bool insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;//目前的BST,不允许有重复的值
			}
		}
		Node* node = new Node(key, value);
		if (key > parent->_key)
		{
			parent->_right = node;
		}
		else
		{
			parent->_left = node;
		}
		return true;
	}
	//中序遍历
	void _Inorder(Node* root)
	{
		if (root == nullptr) return;
		_Inorder(root->_left);
		cout << root->_key << ":" << root->_value <<endl;
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	Node* Find(const K& key) const
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return  nullptr;
	}
	// 重点理解
	//bool Erase(const K& key)
	//{
	//	// 叶子节点
	//	// 单孩子结点
	//	// 双孩字的结点

	//	//先找到待删除的结点和其父结点
	//	Node* parent = nullptr;
	//	Node* cur = _root;
	//	while (cur)
	//	{
	//		if (key > cur->_val)
	//		{
	//			parent = cur;
	//			cur = cur->_right;
	//		}
	//		else if (key < cur->_val)
	//		{
	//			parent = cur;
	//			cur = cur->_left;
	//		}
	//		else
	//		{
	//			//此时已经找到了 key 所在的结点，准备删除
	//			// 左为空,右为空，左右都不为空
	//			if (cur->_left == nullptr)
	//			{
	//				//极端情况 要删除的结点是BST的根节点
	//				if (cur == _root)
	//				{
	//					_root = cur->_right;
	//				}
	//				else
	//				{
	//					if (cur == parent->_left)
	//					{
	//						parent->_left = cur->_right;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_right;
	//					}
	//				}
	//				delete cur;
	//			}
	//			else if (cur->_right == nullptr)
	//			{
	//				//类比左为空的情况
	//				if (cur == _root)
	//				{
	//					_root = cur->_left;
	//				}
	//				else
	//				{
	//					if (cur == parent->_left)
	//					{
	//						parent->_left = cur->_left;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_left;
	//					}
	//				}
	//				delete cur;
	//			}
	//			else
	//			{
	//				// 两个孩子的结点
	//				// 找到 cur 右树的最左结点(最小)，直接用其值覆盖cur的结点然后删除右树的最左结点
	//				Node* smParent = cur;
	//				Node* subMin = cur->_right;
	//				while (subMin->_left)
	//				{
	//					smParent = subMin;
	//					subMin = subMin->_left;
	//				}
	//				cur->_val = subMin->_val;
	//				//subMin一定是左为空的结点,现在覆盖完，待删除的结点就是subMIN
	//				if (subMin == smParent->_left)
	//				{
	//					smParent->_left = subMin->_right;
	//				}
	//				else
	//				{
	//					smParent->_right = subMin->_right;
	//				}
	//				delete subMin;
	//			}
	//			return true;
	//		}
	//	}
	//	return false;
	//}
private:
	Node* _root = nullptr;//根节点
};


