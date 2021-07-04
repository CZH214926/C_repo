#pragma once
#include "Common.h"

// ��������ڴ�ص�ȱ�ݣ�1���ڴ���Ƭ���⣬���ڴ�������ô�취�ϲ�
  //                     2��ֻ����Զ����Ķ�������
template<class T>
class ObjectPool
{
protected:
	char* _memory = nullptr;         // һ����������ϵͳ����Ĵ���ڴ�
	size_t   _leftSize = 0;             // һ��������ʣ��ռ�Ĵ�С
	void* _freeList = nullptr;       // ��������ͷ�����ӻ��յ�С���ڴ�
public:
	~ObjectPool()
	{
		// �����������ﲻ�����ͷţ���Ϊ�ͷ�Ҫ�����ͷţ����������������Ǻܶ��С�ڴ�

	}
	// Ϊ�����ӳ���Ŀɶ��������������
	void*& NextObj(void* obj)
	{
		return *((void**)obj);
	}
	T* New()
	{
		T* obj = nullptr;
		if (_freeList)
		{
			//
			obj = (T*)_freeList;
			// ͷɾ�����ͷɾ�ܹ���
			//_freeList = *((void**)_freeList);
			_freeList = NextObj(_freeList);
		}
		else
		{
			if (_leftSize < GetItemSize())
			{
				_leftSize = 1024 * 100;
				_memory = (char*)malloc(_leftSize);// ������Ի���mmap/brk
				if (_memory == nullptr)
				{
					throw std::bad_alloc();
				}
			}
			// ȡһ��T�Ĵ�С
			obj = (T*)_memory;
			_memory += GetItemSize();
			_leftSize -= GetItemSize();
		}
		new(obj)T;      // ʹ�ö�λnew����������Ŀռ���Դ�ĳ�ʼ��
		return obj;
	}
	void Delete(T* obj)
	{
		// �ѻ��յ��ڴ���е���Դ������
		// ���ڴ��ͷ�嵽����������
		// ȡ��odj��ͷ4/8���ֽڣ�����ͷ��
		obj->~T();// ��ʾ�����������������ڴ���е���Դ
		//*((int*)obj) = (int)_freeList;
		//*((void**)obj) = _freeList;
		NextObj(obj) = _freeList;
		_freeList = obj;
	}
private:
	// ��Դ���ObjectPool<char>�����
	static size_t GetItemSize()
	{
		if (sizeof(T) > sizeof(T*))
		{
			return sizeof(T);
		}
		else
		{
			return sizeof(T*);
		}
	}

};
struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode()
		:_val(0),
		_left(nullptr),
		_right(nullptr)
	{}
};

void TestObjectPool()
{
	/*ObjectPool<TreeNode> TNPool;
	std::vector<TreeNode*> v;
	for (size_t i = 0; i < 100; ++i)
	{
		TreeNode* node = TNPool.New();
		cout << node << endl;
		v.push_back(node);
	}
	for (auto e : v)
	{
		TNPool.Delete(e);
	}*/
	/*ObjectPool<TreeNode> tnPool;
	TreeNode* node1 = tnPool.New();
	TreeNode* node2 = tnPool.New();
	TreeNode* node3 = tnPool.New();
	TreeNode* node4 = tnPool.New();
	cout << node1 << endl;
	cout << node2 << endl;
	cout << node3 << endl;
	cout << node4 << endl;
	tnPool.Delete(node1);
	tnPool.Delete(node4);

	TreeNode* node10 = tnPool.New();
	cout << node10 << endl;

	TreeNode* node11 = tnPool.New();
	cout << node11 << endl;*/
	// �򵥲�������
	size_t begin1 = clock();
	std::vector<TreeNode*> v1;
	for (int i = 0; i < 100000; ++i)
	{
		v1.push_back(new TreeNode);
	}
	for (int i = 0; i < 100000; ++i)
	{
		delete v1[i];
	}
	v1.clear();

	for (int i = 0; i < 100000; ++i)
	{
		v1.push_back(new TreeNode);
	}

	for (int i = 0; i < 100000; ++i)
	{
		delete v1[i];
	}
	v1.clear();
	size_t end1 = clock();

	ObjectPool<TreeNode> tnPool;
	size_t begin2 = clock();
	std::vector<TreeNode*> v2;
	for (int i = 0; i < 100000; ++i)
	{
		v2.push_back(tnPool.New());
	}
	for (int i = 0; i < 100000; ++i)
	{
		tnPool.Delete(v2[i]);
	}
	v2.clear();

	for (int i = 0; i < 100000; ++i)
	{
		v2.push_back(tnPool.New());
	}
	for (int i = 0; i < 100000; ++i)
	{
		tnPool.Delete(v2[i]);
	}
	v2.clear();

	size_t end2 = clock();

	cout << "new and delete : " << end1 - begin1 << "ms" << endl;
	cout << "ObjectPool New and Delete : " << end2 - begin2 << "ms" << endl;
}