#include "Sort.h"
#include "Stack.h"
void Swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
//插入排序
void InsertSort(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n - 1; i++)
	{
		//[0,end]  end+1
		//单趟排序
		int end = i;
		int tmp = arr[end + 1];//先保存因为一会移动数据的时候会把end+1的位置覆盖掉
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
//希尔排序
//希尔排序是插入排序的优化，是把数组变得越来越接近有序，
//最后用插入排序让数组变得彻底有序
void ShellSort(int* arr, int n)
{
	//1、gap>1是预排序，让数组接近有序
	//2、gap==1 ，等于直接插入排序，保证有序
	assert(arr);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//+1保证了gap一定是1
		//gap = 1的时候相当于直接插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

// 冒泡排序
void BubbleSort(int* arr, int n)
{
	assert(arr);
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (arr[i-1] > arr[i])
			{
				Swap(&arr[i-1], &arr[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}

		end--;
	}
}
void AdjustDown(int* arr, int n, int root)
{
	assert(arr);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			//迭代
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	assert(arr);
	//排升序，构建个大堆，构建大堆要写一个向下调整算法
	//把数组想象成逻辑结构为完全二叉树
	//从第一个非叶子节点开始调整
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	//此时数组已经为一个大堆
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);

	}

}

//1、直接选择排序 ---升级版每次选两个数一个最大的，一个最小的                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                vvvvvvvvvvvvvvv
void SelectSort1(int* arr, int n)
{
	int begin = 0, end = n - 1;

	//在[begin,end]中最大数和最小数
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
		}
		Swap(&arr[begin], &arr[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
	}
}

void SelectSort2(int* arr, int n)
{
	assert(arr);
	//[0,end]中找到一个最大的数，和数组最后的元素交换
	int end = n - 1;
	while (end > 0)
	{
		int maxi = 0;
		for (int i = 1; i <= end; i++)
	    {
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
	    }
		//程序走到这里选出一个最大的数
		//交换最大的数和最后的数
		Swap(&arr[maxi], &arr[end]);
		end--;
	}
	
}
//单趟排序
//可以用三数取中法进行选择key的优化
int GetMidIndex(int* arr, int begin, int end)
{
	assert(arr);
	int mid = (begin + end) / 2;
	if (arr[begin] < arr[mid])
	{
		if (arr[end] < arr[begin])
		{
			return begin;
		}
		else if (arr[end] > arr[mid])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (arr[end] > arr[begin])
		{
			return begin;
		}
		else if (arr[end] < arr[mid])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
}
//左右指针法
int PartSort1(int* arr, int begin, int end)
{
	assert(arr);
	//三数选中优化
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	int keyIndex = end;
	while (begin < end)
	{
		//左边找比key大的值
		while (begin < end && arr[begin] <= arr[keyIndex])
		{
			begin++;
		}
		//右边找比key小的值
		while (begin < end && arr[end] >= arr[keyIndex])
		{
			end--;
		}
		Swap(&arr[begin], &arr[end]);
	}
	int div = begin;
	Swap(&arr[div], &arr[keyIndex]);
	return div;
}
//挖坑法(挖坑法和双指针法相似，但是前后指针法不太一样)
int PartSort2(int* arr, int begin, int end)
{
	assert(arr);
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	
	//选出key作为坑
	int key = arr[end];
	while (begin < end)
	{
		//排升序从左开始找比key大的数，直接放到坑里。
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}
		arr[end] = arr[begin];
		//begin的坑(位置空出来了)等待从右向左找的比key小的数填上

		while (begin < end && arr[end] >= key)
		{
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = key;
	return begin;
}
//前后指针法
int PartSort3(int* arr, int begin, int end)
{
	assert(arr);
	int prev = begin - 1;
	int cur = begin;
	//还是要进行三数选中进行优化
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	int keyIndex = end;

	while (cur < end)
	{
		if (arr[cur] < arr[keyIndex] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[++prev], &arr[keyIndex]);

	return prev;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//小区间优化，当区间长度<10,区间内元素已经接近有序，可以使用插入排序进行优化
	
	if (right - left > 10)
	{
		int div = PartSort2(arr, left, right);
		QuickSort(arr, left, div - 1);
		QuickSort(arr, div + 1, right);
	}
	else
	{
		InsertSort(arr + left, right - left + 1);
	}
}

void MergeArr(int* arr, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1;
	int right = end2;
	//保存begin1和end2是为了最后拷数据的时候有首尾下标

	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}
	//走到这里较短的区间肯定处理完了，把较长区间剩下的有序数据放到tmp中
	//因为不知道哪个区间是先处理完的，所以两个区间都拷贝一下
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
	//把tmp的数据拷贝到原数组
	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}
void _MergeSort(int* arr,int left, int right,int* tmp)
{
	  //不断拆分直到不能再拆分
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	//[left,mid][mid+1,right]
	//这个递归过程是拆分的过程
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	//这是把两个有序的区间合并成一个有序的区间的过程,即归并过程
	 MergeArr(arr, left, mid, mid + 1, right, tmp);
}

// 归并排序递归实现
void MergeSort(int* arr, int n)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//归并排序非递归实现(这个需要再重新看一下)
void MergeSortNonR(int* arr, int n)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			//合并时只有第一组，第二组不存在就不需要合并
			if (begin2 >= n)
			{
				break;
			}
			//如果第二组只有部分数据需要修正end2的边界为n-1
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			MergeArr(arr, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	free(tmp);
}

//快排非递归
//过程和二叉树的递归遍历相似
//把要操作的区间下标存在栈中
void QuickSortNonR(int* arr, int left, int right)
{
	assert(arr);
	Stack st;
	StackInit(&st);
	//非递归代码
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartSort2(arr, begin, end);

		//[begin, div-1]  div  [div+1, end]
		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}

	StackDestory(&st);
}

//计数排序
//计数排序在数据分布密集，最大最小值的差距不是很大的时候的效率很高
void CountSort(int* arr, int n)
{
	assert(arr);
	//遍历数组找到最大值和最小值
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0, sizeof(int)*range);
	//arr[i]-min是countArr中的下标
	//在countArr数组中统计出arr数组中数字出现的次数
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}
	
	//把countArr中的数据对照着复制给arr
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArr[j]--)
		arr[index++] = j + min;
	}
	free(countArr);
}