#pragma once
#include "Common.h"

// 这个简易内存池的缺陷：1、内存碎片问题，把内存切碎了么办法合并
  //                     2、只能针对定长的对象问题
template<class T>
class ObjectPool
{
protected:
	char* _memory = nullptr;         // 一级缓存中向系统申请的大块内存
	size_t   _leftSize = 0;             // 一级缓存中剩余空间的大小
	void* _freeList = nullptr;       // 自由链表头，连接回收的小块内存
public:
	~ObjectPool()
	{
		// 自由链表这里不可以释放，因为释放要整块释放，而自由链表这里是很多块小内存

	}
	// 为了增加程序的可读性增加这个函数
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
			// 头删，这个头删很诡异
			//_freeList = *((void**)_freeList);
			_freeList = NextObj(_freeList);
		}
		else
		{
			if (_leftSize < GetItemSize())
			{
				_leftSize = 1024 * 100;
				_memory = (char*)malloc(_leftSize);// 这里可以换成mmap/brk
				if (_memory == nullptr)
				{
					throw std::bad_alloc();
				}
			}
			// 取一个T的大小
			obj = (T*)_memory;
			_memory += GetItemSize();
			_leftSize -= GetItemSize();
		}
		new(obj)T;      // 使用定位new对申请出来的空间资源的初始化
		return obj;
	}
	void Delete(T* obj)
	{
		// 把回收的内存块中的资源析构掉
		// 把内存块头插到自由链表中
		// 取到odj中头4/8个字节，进行头插
		obj->~T();// 显示调用析构函数清理内存块中的资源
		//*((int*)obj) = (int)_freeList;
		//*((void**)obj) = _freeList;
		NextObj(obj) = _freeList;
		_freeList = obj;
	}
private:
	// 针对处理ObjectPool<char>的情况
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
	// 简单测试性能
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