#pragma once
#include <utility>
#include <assert.h>
#include <queue>

using std::pair;

// AVL���Ľ�㶨��
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K,V>* _right;
	AVLTreeNode<K,V>* _parent;  // ʹ���������ķ�ʽ�ȽϷ���
	pair<K, V> _kv;             // ������pair����
	int _bf;                     // ƽ������(�������߶�-�������߶�)balance factor
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
	AVLTree() = default; // C++11�÷���Ĭ�ϵĹ��캯��
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
		// ��������
	}
	// �����㣬���ڲ��漰ƽ�����ӵĵ��ں���ת�����ص����գ�
	pair<Node*, bool> insert(const pair<K, V>& kv)
	{
		// 1������ 2���޸�ƽ������ 3��abs(_bf) == 2,Ҫ��ת��֤ƽ��
		// ����ǵ�һ�β�����ִ�������߼�
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		// �����ʱ�����Ѿ��н����Ѱ��Ҫ�����λ��
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
				// ֤����ʱ���Ѿ�����
				return make_pair(cur, false);
			}
		}
		//��ʱ cur == nullptr;
		 cur = new Node(kv);
		// ��ʱ��Ҫ�����뵽parent��������
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			// �����˳������Һ��ӻ���˫�׹�ϵ��Ҫά��
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		
		// �����ڸ���ƽ�����ӵ�ʱ��cur��Ҫ�ƶ��������ȱ����²������ָ��
		Node* newnode = cur;
		
		// ����ƽ�����ӣ������ƽ�����ӵı仯
		// 1���������������parent���ң���parent->_bf++;
		// 2���������������parent������parent->_bf--;
		// 3������ƽ�����Ӻ�
		//  a��parent->_bf==0;˵��û����ǰparent->_bf == -1����1�����ڱ��0��˵����
		// �����Ǳ߸������ˣ�����Ӱ���ϲ����ȣ���ʱ���½�����break;
		 // b��parent->_bf == 1����-1,˵��parent���������ĸ߶ȱ��ˣ�����һ����ӦӰ��
		// ��������
		// c��parent->_bf == 2���� -2 ,˵��parent�������Ѿ���ƽ�⣬��Ҫ����ת����
		while (parent)
		{
			// ����ƽ������
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			// ���ƽ������
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				// ���������ȸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				// ��ʼ��ת����
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
		// ��ת�����ƽ������
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
		// ��ת�����ƽ������
		subR->_bf = parent->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		// ����ƽ������
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
		// ��¼��ת֮ǰ��subRL��ƽ�����ӣ���ΪsubRL����Ϊ���յĸ��ڵ��
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);

		// ��ת�꣬����ƽ������
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
		// ���Եݹ���Ҳ�����ò��������˼�������ж��ٲ�߶Ⱦ��Ƕ���
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
			cout << "ƽ�������쳣 ��" << root->_kv.first << endl;
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
		// ��BST�Ĳ�����һ����
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
	bool Erase(const K& key);// ��insert��Ҫ���ӵ���˼·����
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
