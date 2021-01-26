#include "Sort.h"
#include "Stack.h"
void Swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
//��������
void InsertSort(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n - 1; i++)
	{
		//[0,end]  end+1
		//��������
		int end = i;
		int tmp = arr[end + 1];//�ȱ�����Ϊһ���ƶ����ݵ�ʱ����end+1��λ�ø��ǵ�
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
//ϣ������
//ϣ�������ǲ���������Ż����ǰ�������Խ��Խ�ӽ�����
//����ò��������������ó�������
void ShellSort(int* arr, int n)
{
	//1��gap>1��Ԥ����������ӽ�����
	//2��gap==1 ������ֱ�Ӳ������򣬱�֤����
	assert(arr);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//+1��֤��gapһ����1
		//gap = 1��ʱ���൱��ֱ�Ӳ�������
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

// ð������
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
			//����
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
	//�����򣬹�������ѣ��������Ҫдһ�����µ����㷨
	//������������߼��ṹΪ��ȫ������
	//�ӵ�һ����Ҷ�ӽڵ㿪ʼ����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	//��ʱ�����Ѿ�Ϊһ�����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);

	}

}

//1��ֱ��ѡ������ ---������ÿ��ѡ������һ�����ģ�һ����С��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                vvvvvvvvvvvvvvv
void SelectSort1(int* arr, int n)
{
	int begin = 0, end = n - 1;

	//��[begin,end]�����������С��
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
	//[0,end]���ҵ�һ��������������������Ԫ�ؽ���
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
		//�����ߵ�����ѡ��һ��������
		//������������������
		Swap(&arr[maxi], &arr[end]);
		end--;
	}
	
}
//��������
//����������ȡ�з�����ѡ��key���Ż�
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
//����ָ�뷨
int PartSort1(int* arr, int begin, int end)
{
	assert(arr);
	//����ѡ���Ż�
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	int keyIndex = end;
	while (begin < end)
	{
		//����ұ�key���ֵ
		while (begin < end && arr[begin] <= arr[keyIndex])
		{
			begin++;
		}
		//�ұ��ұ�keyС��ֵ
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
//�ڿӷ�(�ڿӷ���˫ָ�뷨���ƣ�����ǰ��ָ�뷨��̫һ��)
int PartSort2(int* arr, int begin, int end)
{
	assert(arr);
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	
	//ѡ��key��Ϊ��
	int key = arr[end];
	while (begin < end)
	{
		//���������ʼ�ұ�key�������ֱ�ӷŵ����
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}
		arr[end] = arr[begin];
		//begin�Ŀ�(λ�ÿճ�����)�ȴ����������ҵı�keyС��������

		while (begin < end && arr[end] >= key)
		{
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = key;
	return begin;
}
//ǰ��ָ�뷨
int PartSort3(int* arr, int begin, int end)
{
	assert(arr);
	int prev = begin - 1;
	int cur = begin;
	//����Ҫ��������ѡ�н����Ż�
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
	//С�����Ż��������䳤��<10,������Ԫ���Ѿ��ӽ����򣬿���ʹ�ò�����������Ż�
	
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
	//����begin1��end2��Ϊ��������ݵ�ʱ������β�±�

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
	//�ߵ�����϶̵�����϶��������ˣ��ѽϳ�����ʣ�µ��������ݷŵ�tmp��
	//��Ϊ��֪���ĸ��������ȴ�����ģ������������䶼����һ��
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
	//��tmp�����ݿ�����ԭ����
	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}
void _MergeSort(int* arr,int left, int right,int* tmp)
{
	  //���ϲ��ֱ�������ٲ��
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	//[left,mid][mid+1,right]
	//����ݹ�����ǲ�ֵĹ���
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	//���ǰ��������������ϲ���һ�����������Ĺ���,���鲢����
	 MergeArr(arr, left, mid, mid + 1, right, tmp);
}

// �鲢����ݹ�ʵ��
void MergeSort(int* arr, int n)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//�鲢����ǵݹ�ʵ��(�����Ҫ�����¿�һ��)
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
			//�ϲ�ʱֻ�е�һ�飬�ڶ��鲻���ھͲ���Ҫ�ϲ�
			if (begin2 >= n)
			{
				break;
			}
			//����ڶ���ֻ�в���������Ҫ����end2�ı߽�Ϊn-1
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

//���ŷǵݹ�
//���̺Ͷ������ĵݹ��������
//��Ҫ�����������±����ջ��
void QuickSortNonR(int* arr, int left, int right)
{
	assert(arr);
	Stack st;
	StackInit(&st);
	//�ǵݹ����
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

//��������
//�������������ݷֲ��ܼ��������Сֵ�Ĳ�಻�Ǻܴ��ʱ���Ч�ʺܸ�
void CountSort(int* arr, int n)
{
	assert(arr);
	//���������ҵ����ֵ����Сֵ
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
	//arr[i]-min��countArr�е��±�
	//��countArr������ͳ�Ƴ�arr���������ֳ��ֵĴ���
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}
	
	//��countArr�е����ݶ����Ÿ��Ƹ�arr
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArr[j]--)
		arr[index++] = j + min;
	}
	free(countArr);
}