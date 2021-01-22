#include "Sort.h"

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