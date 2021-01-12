#include "Heap.h"
//����һ����ȫ����������˳��洢�����飩�ȽϺ�
//���ڽ�����������
void Swap(HeapDataType* n1, HeapDataType* n2)
{
	HeapDataType temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
//���µ����㷨___����Ҫ�ˣ��������������topk�����Լ������������Ļ���
//���µ������������������һ����a[parent]<a[child],��һ���ǴӶѶ����������ȫ���Ƚ���
void AdjustDown(HeapDataType* a, int n, int root)
{
	//�����±�ĳ�ʼ��
	int parent = root;
	int child = parent * 2 + 1;
	//ѭ�����µ���������Сֵ���������ֵ�����Ѷ���
	while (child < n)
	{
		//ѡ�����Һ����н�С�ĺ��ӣ���Ϊchild��child+1 < n��֤�±겻��Խ��
		if (child+1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		//���ױȺ���С���߽���λ��,�����µ������ӵ�λ��
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//����parent child
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//������ >= ���׵�ʱ������С�ѵ�����������ѭ���ڿΣ�����ͻ���ѭ��
		}
	}
}
//���ϵ����㷨
//����HeapPush��
void AdjustUp(HeapDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//����
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//�ѵĳ�ʼ�����ڲ��жѵĴ���
void HeapInit(Heap* php, HeapDataType* a, int n)
{
	HeapDataType* temp = (HeapDataType*)malloc(sizeof(HeapDataType)*n);
	if (temp)
	{
		php->arr = temp;
		
	}
	else
	{
		printf("�ڴ�����ʧ�ܣ�");
		exit(-1);
	}
	//�������������鿽����malloc�����Ŀռ䣬���������ĶѵĴ�����ɾ�����������ݵȲ���
	memcpy(php->arr, a, sizeof(HeapDataType)*n);
	php->size = n;
	php->capacity = n;

	//�ѿ������������飬�����ɶ�
	//�ӵ�����һ����Ҷ�ӽڵ���й���(ֱ�Ӱ����黭��һ����ȫ����������ֱ����ͼ�õ���һ��
	//��Ҷ�ӽڵ���±꣩
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->arr, php->size, i);
	}
}
//������
void HeapSort(int* a, int n)
{
	//������ĵ�һ�����ǹ�����,�����ѵ�ʱ�临�Ӷ���O(n),��ʱ��С��
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//��������򣬹������
	//����ǽ��򣬹���С��
	//�Ƿ��ŵģ���ΪҪ�����һ�����н���
	int end = n - 1;
	while (end>0)
	{
		//�ѶѶ�����С������󣩺����ĵ�Ԫ�ؽ�����Ȼ���0��n-2�������µ���
		//�Ѵ�С���δ󣩵�Ԫ��Ҳѡ������ֱ��ʣ���һ�������������
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//���ٶ�
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//�ѵĲ�������
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
			printf("����ʧ�ܣ�\n");
			exit(-1);
		}
	}
	php->arr[php->size++] = x;
	AdjustUp(php->arr, php->size, php->size - 1);
}

//�ѵ�ɾ������,Ҫɾ���Ѷ�������
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php->arr, php->size, 0);
}

//��ȡ�Ѷ�����
HeapDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	return php->arr[0];
}