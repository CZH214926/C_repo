#include "Sort.h"

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