#include<stdio.h>
#include<windows.h>

int main()
{
	////һά����
	//int a[] = { 1, 2, 3, 4 };
	////�����С��16���ֽ�
	//printf("%d\n", sizeof(a));
	////int* ��СΪ4�ֽڣ�64λƽ̨�£�8�ֽ�
	//printf("%d\n", sizeof(a+0));
	////�������������ã���������ĵ�һ��Ԫ�أ�int���ʹ�С��4�ֽ�
	//printf("%d\n", sizeof(*a));
	////&a[1]===>Ϊ��ַ������Ϊint*,��С��4���ֽ�
	//printf("%d\n", sizeof(a+1));
	////4���ֽ�
	//printf("%d\n", sizeof(a[1]));
	////��������ȡ��ַ��������������ĵ�ַ��
	////��������Ԫ�صĵ�ַ����ֵ����ͬ���������Ͳ�ͬ
	//printf("%d\n", sizeof(&a));
	////sizeof(arr)===>������������Ĵ�С��16���ֽ�
	//printf("%d\n", sizeof(*&a));
	////����ָ�룬ֻҪ��ָ�����ͣ���С��Ϊ4����8�ֽ�
	//printf("%d\n", sizeof(&a+1));//4
	//printf("%d\n", sizeof(&a[0]));//4
	//printf("%d\n", sizeof(&a[0]+1));//4

	//printf("*************************************************************\n");
	//printf("�ַ����飺\n");
	////�ַ�����
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
	////printf("%d\n", strlen(*arr));//����ʵ�κ��βε����Ͳ�ƥ��strlen(const char* str)����
	////printf("%d\n", strlen(arr[1]));//ͬ��
	//printf("%d\n", strlen(&arr));//����ָ��
	//printf("%d\n", strlen(&arr+1));//����ָ��+1
	//printf("%d\n", strlen(&arr[0]+1));//>=5
	//

	//printf("*********************************\n");
	//char arr1[] = "abcdef";
	//printf("%d\n", sizeof(arr1));//7���ֽڣ���Ϊ����'\0'
	//printf("%d\n", sizeof(arr1+0));//arr+0Ϊָ���ַ�a��ָ�룬��СΪ4/8
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

	//��ά����
	int arr2[3][4] = { 0 };
	//��ά������Կ�����һά���飬�����е�Ԫ��Ϊһά����
	//arr2[0]���Կ���һά������
	printf("%d\n", sizeof(arr2) );//48
	printf("%d\n", sizeof(arr2[0][0]) );//4
	printf("%d\n", sizeof(arr2[0]) );//16
	printf("%d\n", sizeof(arr2[0]+1) );//4���ڶ���һά����ĵڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*(arr2[0]+1)) );//4���ڶ���һά����
	printf("%d\n", sizeof(arr2+1));//4���ڶ���Ԫ��-->�ڶ���һά����ĵ�ַ
	printf("%d\n", sizeof(*(arr2+1)) );//16���ڶ���һά����
	printf("%d\n", sizeof(&arr2[0]+1) );//4���ڶ���һά����ĵ�ַ
	printf("%d\n", sizeof(*(&arr2[0] + 1)) );//16
	printf("%d\n", sizeof(*arr2));//16����һ��һά����
	printf("%d\n", sizeof(arr2[3]));//16
	/*
	   �ܽ᣺
	   ֻ��sizeof(������)
	       &������
	   �����������������ʾ�������飬����֮�����е�������������
	   ��Ԫ�صĵ�ַ�������Ԫ���ǹ������Ԫ�أ������ά�������Ԫ�ء�
	*/
	system("pause");
	return 0;
}