#include "Sort.h"

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void TestInsertSort()
{
	int arr[] = { 9, 7, 3, 4, 5, 6, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	InsertSort(arr, size);
	PrintArr(arr, size);
}
void TestShellSort()
{
	int arr[] = { 9, 7, 3, 4, 5, 6, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	ShellSort(arr, size);
	PrintArr(arr, size);
}
void TestBubbleSort()
{
	int arr[] = { 9, 7, 3, 4, 5, 6, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	BubbleSort(arr, size);
	PrintArr(arr, size);
}
void TestSelectSort1()
{
	int arr[] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	SelectSort1(arr, size);
	PrintArr(arr, size);
}
void TestSelectSort2()
{
	int arr[] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	SelectSort2(arr, size);
	PrintArr(arr, size);
}
void TestHeapSort()
{
	int arr[] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	HeapSort(arr, size);
	PrintArr(arr, size);
}
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}



	int begin2 = clock();
	InsertSort(a2, N);
	int end2 = clock();



	int begin4 = clock();
	ShellSort(a4, N);
	int end4 = clock();


	printf("InsertSort:%d ms\n", end2 - begin2);
	printf("ShellSort :%d ms\n", end4 - begin4);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main()
{

	//TestOP();
	//TestBubbleSort();
	//TestSelectSort2();
	TestHeapSort();
	system("pause");
	return 0;
}