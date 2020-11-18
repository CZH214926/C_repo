#include<stdio.h>
#include<windows.h>
//ð������===>����
void BubbleSort(int arr[], int size)
{
	int temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			return;
		}
	}
}
//���ֲ���====>���ش�����Ԫ�ص��±�
int BinSerach(int arr[], int size, int num){
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right){
		mid = left + (right - left) / 2;
		if (num < arr[mid])
		{
			right = mid - 1;
		}
		else if (num>arr[mid])
		{
			left = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
//��������Ԫ��
void print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++){
		printf("arr[%d]=%d\n", i, *(arr + i));
		//printf("arr[%d]=%d\n", i, arr[i]);
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 9, 8, 7, 6, 5, 4,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��\n");
	print_arr(arr, size);
	BubbleSort(arr, size);
	printf("�����\n");
	print_arr(arr, size);
	int num = 5;
	int res = BinSerach(arr, size, num);
	if (res != -1){
		printf("%d���±�Ϊ��%d\n",num, res);
	}
	else{
		printf("��������%d\n", num);
	}

	system("pause");
	return 0;
}