#pragma once
#include <utility>
#include <assert.h>
#include <queue>

using std::pair;

// AVL树的结点定义
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K,V>* _right;
	AVLTreeNode<K,V>* _parent;  // 使用三叉链的方式比较方便
	pair<K, V> _kv;             // 数据是pair类型
	int _bf;                     // 平衡因子(右子树高度-左子树高度)balance factor
	AVLTreeNode(const pair<K, V>& kv = pair<K,V>())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
private:
	Node* _root = nullptr;
private:
	void CreateHead()
	{
		_root = new Node;
	}
public:
	AVLTree() = default; // C++11用法用默认的构造函数
	template<class InputInerator>
	AVLTree(InputInerator first, InputInerator last)
	{
		CreateHead();
		while (first != last)
		{
			insert(*first);
			++first;
		}
	}
	AVLTree(const AVLTree<K, V>& avltree)
	{
		CreateHead();
		AVLTree<K, V> tmp(avltree.begin(), avltree.end());
		swap(_root, avltree._root);
	}
	AVLTree<K, V>& operator=(AVLTree<K, V> t)
	{
		swap(_root, t._root);
		return *this;
	}
	virtual~AVLTree()
	{
		// 析构函数
	}
	// 插入结点，，内部涉及平衡因子的调节和旋转树（重点掌握）
	pair<Node*, bool> insert(const pair<K, V>& kv)
	{
		// 1、插入 2、修改平衡因子 3、abs(_bf) == 2,要旋转保证平衡
		// 如果是第一次插入则执行以下逻辑
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		// 如果此时树中已经有结点则寻找要插入的位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur; 
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 证明此时树已经存在
				return make_pair(cur, false);
			}
		}
		//此时 cur == nullptr;
		 cur = new Node(kv);
		// 此时还要看插入到parent的左还是右
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			// 别忘了除了左右孩子还有双亲关系需要维持
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		
		// 后面在更新平衡因子的时候cur需要移动，所以先保存新插入结点的指针
		Node* newnode = cur;
		
		// 更新平衡因子，并检测平衡因子的变化
		// 1、新增结点连接在parent的右，则parent->_bf++;
		// 2、新增结点连接在parent的左，则parent->_bf--;
		// 3、更新平衡因子后
		//  a、parent->_bf==0;说明没更新前parent->_bf == -1或者1，现在变成0，说明把
		// 矮的那边给填上了，不会影响上层祖先，此时更新结束。break;
		 // b、parent->_bf == 1或者-1,说明parent所在子树的高度变了，对上一层有应影响
		// 继续更新
		// c、parent->_bf == 2或者 -2 ,说明parent的子树已经不平衡，需要做旋转处理
		while (parent)
		{
			// 更新平衡因子
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			// 检测平衡因子
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				// 继续向祖先更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				// 开始旋转调节
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else // cur->_bf == 1
					{
						RotateLR(parent);
					}
				}
				else // parent->_bf == 2
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else // cur->_bf == -1
					{
						RotateRL(parent);
					}
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return make_pair(newnode, true);
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* parentParent = parent->_parent;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

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
		}
		// 旋转完更新平衡因子
		parent->_bf = subL->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* parentParent = parent->_parent;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
				//subR->_parent = parentParent;
			}
			else
			{
				parentParent->_right = subR;
				//subR->_parent = parentParent;
			}
			subR->_parent = parentParent;
		}
		// 旋转完更新平衡因子
		subR->_bf = parent->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		// 调节平衡因子
		if (bf == -1)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			subL->_bf = subLR->_bf = parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		// 记录旋转之前的subRL的平衡因子，因为subRL是作为最终的根节点的
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);

		// 旋转完，调节平衡因子
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if(bf == 0)  // bf == 0
		{
			subR->_bf = parent->_bf = subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	int _Height(Node* root)
	{
		// 可以递归求也可以用层序遍历的思想来求，有多少层高度就是多少
		if (root == nullptr)
			return 0;
			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);
			return 1 + max(leftH, rightH);
			/*if (root == nullptr)
				return 0;
				queue<Node*> que;
				que.push(root);
				int depth = 0;
				while (!que.empty())
				{
				size_t levelSize = que.size();
				for (size_t i = 0; i < levelSize; i++)
				{
				Node* front = que.front();
				que.pop();
				if (front->_left)
				que.push(front->_left);
				if (front->_right)
				que.push(front->_right);
				}
				depth++;
				}
				return depth;*/
	}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "平衡因子异常 ：" << root->_kv.first << endl;
		}
		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);			
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	Node* Find(const K& key)
	{
		// 跟BST的查找是一样的
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_kv.first)
			{
				cur = cur->_right;
			}
			else if (key < cur->_left)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool operator[](const K& key)
	{
		pair<Node*, bool> ret = insert(k, V());
		return ret.first->second;
	}
	bool Erase(const K& key);// 比insert还要复杂但是思路相似
	void InOrder()
	{
		_InOrder(_root);
		cout << "\n";
	}
	void _InOrder(Node* root)
	{
		if (!root)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}
};
