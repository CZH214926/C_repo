#pragma once

// keyģ�͵Ķ���������
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
//				return false;//Ŀǰ��BST,���������ظ���ֵ
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
//	//�������
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
//	// �ص����
//	bool Erase(const K& key)
//	{
//		// Ҷ�ӽڵ�
//		// �����ӽ��
//		// ˫���ֵĽ��
//
//		//���ҵ���ɾ���Ľ����丸���
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
//				//��ʱ�Ѿ��ҵ��� key ���ڵĽ�㣬׼��ɾ��
//				// ��Ϊ��,��Ϊ�գ����Ҷ���Ϊ��
//				if (cur->_left == nullptr)
//				{
//					//������� Ҫɾ���Ľ����BST�ĸ��ڵ�
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
//					//�����Ϊ�յ����
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
//					// �������ӵĽ��
//					// �ҵ� cur ������������(��С)��ֱ������ֵ����cur�Ľ��Ȼ��ɾ��������������
//					Node* smParent = cur;
//					Node* subMin = cur->_right;
//					while (subMin->_left)
//					{
//						smParent = subMin;
//						subMin = subMin->_left;
//					}
//					cur->_val = subMin->_val;
//					//subMinһ������Ϊ�յĽ��,���ڸ����꣬��ɾ���Ľ�����subMIN
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
//	Node* _root = nullptr;//���ڵ�
//};

// key - value ģ�͵Ķ���������
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
				return false;//Ŀǰ��BST,���������ظ���ֵ
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
	//�������
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
	// �ص����
	//bool Erase(const K& key)
	//{
	//	// Ҷ�ӽڵ�
	//	// �����ӽ��
	//	// ˫���ֵĽ��

	//	//���ҵ���ɾ���Ľ����丸���
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
	//			//��ʱ�Ѿ��ҵ��� key ���ڵĽ�㣬׼��ɾ��
	//			// ��Ϊ��,��Ϊ�գ����Ҷ���Ϊ��
	//			if (cur->_left == nullptr)
	//			{
	//				//������� Ҫɾ���Ľ����BST�ĸ��ڵ�
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
	//				//�����Ϊ�յ����
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
	//				// �������ӵĽ��
	//				// �ҵ� cur ������������(��С)��ֱ������ֵ����cur�Ľ��Ȼ��ɾ��������������
	//				Node* smParent = cur;
	//				Node* subMin = cur->_right;
	//				while (subMin->_left)
	//				{
	//					smParent = subMin;
	//					subMin = subMin->_left;
	//				}
	//				cur->_val = subMin->_val;
	//				//subMinһ������Ϊ�յĽ��,���ڸ����꣬��ɾ���Ľ�����subMIN
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
	Node* _root = nullptr;//���ڵ�
};


