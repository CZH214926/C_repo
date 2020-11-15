#include<stdio.h>
#include<windows.h>
#include<assert.h>
//模拟实现qsort(用冒泡排序的思想)
//涉及回调函数：
//回调函数就是通过函数指针调用的函数。如果把函数的指针（地址）作为参数传递给另一个函数
//当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。一般回调函数需要程序员
//自己实现。比如qsort就是典型的回调函数的应用

/*
   arr:待排序序列
   num:待排序序列中的元素个数
   size:待排序序列中的元素类型的大小
   comp:函数指针--->要自定义的比较函数
   int(*comp)(const void*, const void*)：
   形参的意义：待排序数据序列任意两个元素的地址
*/
int CompInt(const void* x_, const void* y_)
{
	int *n1 = (int*)(x_);
	int *n2 = (int*)(y_);
	//升序
	if (*n1 > *n2){
		return 1;
	}
	else if (*n1 < *n2){
		return -1;
	}
	else{
		return 0;
	}
}
int CompStr(const void* x_, const void* y_)
{
	
	char *s1 = *(char**)(x_);
	char *s2 = *(char**)(y_);
	return strcmp(s1, s2);
}
void swap(char* src, char* dst, int size)
{
	while (size)
	{
		char temp = *src;
		*src = *dst;
		*dst = temp;
		size--;
		src++;
		dst++;
	}
}
void my_qsort(void *arr, int num, int size, int(*comp)(const void*, const void*))
{
	assert(arr && comp);
	char *e = (char*)arr;//想让以一个字节为单位进行操作，也就是说这里面我只用到了
	                     //char是一个字节大小的特征，至于它的类型我们不关心。
	for (int i = 0; i < num - 1; i++){
		int flag = 1;
		for (int j = 0; j < num - 1 - i; j++){
			if (comp(e+j*size,e+(j+1)*size)>0){
				//执行交换逻辑
				flag = 0;
				swap(e+j*size,e+(j+1)*size,size);
			}
		}
		if (flag){
			break;
		}
	}
}

//打印指针数组
void PrintStr(char** str, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("str[%d]=%s\n", i,*(str + i));
	}
}
void PrintInt(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
}
int main()
{
	//指针数组
	//char* str[] = { "aaa", "ddd", "ccc", "bbb" };
	int arr[] = { 99, 11, 22, 66, 55, 44 };
	//int num = sizeof(str) / sizeof(str[0]);
	int num1 = sizeof(arr) / sizeof(arr[0]);
	int size = sizeof(char*);
	printf("排序前：\n");
	//PrintStr(arr, num1);
	PrintInt(arr, num1);
	my_qsort(arr, num1, size,CompInt);
	printf("排序后：\n");
	PrintInt(arr, num1);
	//PrintStr(arr, num1);

	system("pause");
	return 0;
}