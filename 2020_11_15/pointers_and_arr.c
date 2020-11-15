#include<stdio.h>
#include<windows.h>

int main()
{
	////一维数组
	//int a[] = { 1, 2, 3, 4 };
	////数组大小：16个字节
	//printf("%d\n", sizeof(a));
	////int* 大小为4字节，64位平台下：8字节
	//printf("%d\n", sizeof(a+0));
	////对数组名解引用，就是数组的第一个元素：int类型大小：4字节
	//printf("%d\n", sizeof(*a));
	////&a[1]===>为地址，类型为int*,大小：4个字节
	//printf("%d\n", sizeof(a+1));
	////4个字节
	//printf("%d\n", sizeof(a[1]));
	////对数组名取地址，代表整个数组的地址，
	////和数组首元素的地址在数值上相同，但是类型不同
	//printf("%d\n", sizeof(&a));
	////sizeof(arr)===>代表整个数组的大小：16个字节
	//printf("%d\n", sizeof(*&a));
	////数组指针，只要是指针类型，大小均为4或者8字节
	//printf("%d\n", sizeof(&a+1));//4
	//printf("%d\n", sizeof(&a[0]));//4
	//printf("%d\n", sizeof(&a[0]+1));//4

	//printf("*************************************************************\n");
	//printf("字符数组：\n");
	////字符数组
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//6
	//printf("%d\n", sizeof(arr+0));//4/8
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4/8
	//printf("%d\n", sizeof(&arr+1));//4/8
	//printf("%d\n", sizeof(&arr[0]+1));//4/8

	//printf("********************************\n");
	//printf("%d\n", strlen(arr));//>=6
	//printf("%d\n", strlen(arr+0));//>=6
	////printf("%d\n", strlen(*arr));//报错：实参和形参的类型不匹配strlen(const char* str)报错
	////printf("%d\n", strlen(arr[1]));//同上
	//printf("%d\n", strlen(&arr));//数组指针
	//printf("%d\n", strlen(&arr+1));//数组指针+1
	//printf("%d\n", strlen(&arr[0]+1));//>=5
	//

	//printf("*********************************\n");
	//char arr1[] = "abcdef";
	//printf("%d\n", sizeof(arr1));//7个字节，因为还有'\0'
	//printf("%d\n", sizeof(arr1+0));//arr+0为指向字符a的指针，大小为4/8
	//printf("%d\n", sizeof(*arr1));//1
	//printf("%d\n", sizeof(arr1[1]));//1
	//printf("%d\n", sizeof(&arr1));//4/8
	//printf("%d\n", sizeof(&arr1+1));//4/8
	//printf("%d\n", sizeof(&arr1[0]+1));//4/8
	//printf("****************************");

	//printf("%d\n", strlen(arr1));
	//printf("%d\n", strlen(arr1+0));
	//printf("%d\n", strlen(*arr1));
	//printf("%d\n", strlen(arr1[1]));
	//printf("%d\n", strlen(&arr1));
	//printf("%d\n", strlen(&arr1+1));
	//printf("%d\n", strlen(&arr1[0]+1));
	//
	//char *p = "abcdef";
	//printf("%d\n", sizeof(p));
	//printf("%d\n", sizeof(p+1));
	//printf("%d\n", sizeof(*p));
	//printf("%d\n", sizeof(p[0]));
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", sizeof(&p+1));
	//printf("%d\n", sizeof(&p[0]+1));

	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p+1));
	//printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p+1));
	//printf("%d\n", strlen(&p[0]+1));

	//二维数组
	int arr2[3][4] = { 0 };
	//二维数组可以看成是一维数组，数组中的元素为一维数组
	//arr2[0]可以看作一维数组名
	printf("%d\n", sizeof(arr2) );//48
	printf("%d\n", sizeof(arr2[0][0]) );//4
	printf("%d\n", sizeof(arr2[0]) );//16
	printf("%d\n", sizeof(arr2[0]+1) );//4，第二个一维数组的第二个元素的地址
	printf("%d\n", sizeof(*(arr2[0]+1)) );//4，第二个一维数组
	printf("%d\n", sizeof(arr2+1));//4，第二个元素-->第二个一维数组的地址
	printf("%d\n", sizeof(*(arr2+1)) );//16，第二个一维数组
	printf("%d\n", sizeof(&arr2[0]+1) );//4，第二个一维数组的地址
	printf("%d\n", sizeof(*(&arr2[0] + 1)) );//16
	printf("%d\n", sizeof(*arr2));//16，第一个一维数组
	printf("%d\n", sizeof(arr2[3]));//16
	/*
	   总结：
	   只有sizeof(数组名)
	       &数组名
	   这两种情况数组名表示整个数组，除此之外所有的数组名都代表
	   首元素的地址，这个首元素是广义的首元素，比如二维数组的首元素。
	*/
	system("pause");
	return 0;
}