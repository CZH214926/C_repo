#include "Heap.h"
//堆是一种完全二叉树，用顺序存储（数组）比较好
//用于交换两个数据
void Swap(HeapDataType* n1, HeapDataType* n2)
{
	HeapDataType temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
//向下调整算法___老重要了，这是理解堆排序和topk问题以及堆这里相关题的基础
//向下调整结束的情况有两个一个是a[parent]<a[child],另一个是从堆顶到数组结束全部比较完
void AdjustDown(HeapDataType* a, int n, int root)
{
	//父子下标的初始化
	int parent = root;
	int child = parent * 2 + 1;
	//循环向下调整，把最小值（或者最大值浮到堆顶）
	while (child < n)
	{
		//选出左右孩子中较小的孩子，作为child，child+1 < n保证下标不能越界
		if (child+1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		//父亲比孩子小二者交换位置,并更新迭代孩子的位置
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//迭代parent child
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//当孩子 >= 父亲的时候，满足小堆的条件，跳出循环节课，否则就会死循环
		}
	}
}
//向上调整算法
//用在HeapPush中
void AdjustUp(HeapDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//迭代
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//堆的初始化，内部有堆的创建
void HeapInit(Heap* php, HeapDataType* a, int n)
{
	HeapDataType* temp = (HeapDataType*)malloc(sizeof(HeapDataType)*n);
	if (temp)
	{
		php->arr = temp;
		
	}
	else
	{
		printf("内存申请失败！");
		exit(-1);
	}
	//将传进来的数组拷贝给malloc出来的空间，用来后续的堆的创建，删除，插入数据等操作
	memcpy(php->arr, a, sizeof(HeapDataType)*n);
	php->size = n;
	php->capacity = n;

	//把拷贝进来的数组，构建成堆
	//从倒数第一个非叶子节点进行构建(直接把数组画成一个完全二叉树可以直接由图得到第一个
	//非叶子节点的下标）
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->arr, php->size, i);
	}
}
//堆排序
void HeapSort(int* a, int n)
{
	//堆排序的第一步就是构建堆,构建堆的时间复杂度是O(n),此时是小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//如果是升序，构建大堆
	//如果是降序，构建小堆
	//是反着的，因为要和最后一个进行交换
	int end = n - 1;
	while (end>0)
	{
		//把堆顶（最小或者最大）和最后的的元素交换，然后从0到n-2继续向下调整
		//把次小（次大）的元素也选出来，直到剩最后一个，堆排序完成
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//销毁堆
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//堆的插入数据
void HeapPush(Heap* php, HeapDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		php->capacity *= 2;
		HeapDataType* tmp = (HeapDataType*)realloc(php->arr, sizeof(HeapDataType)*php->capacity);
		if (tmp)
		{
			php->arr = tmp;
		}
		else
		{
			printf("扩容失败！\n");
			exit(-1);
		}
	}
	php->arr[php->size++] = x;
	AdjustUp(php->arr, php->size, php->size - 1);
}

//堆的删除数据,要删除堆顶的数据
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php->arr, php->size, 0);
}

//获取堆顶数据
HeapDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	return php->arr[0];
}