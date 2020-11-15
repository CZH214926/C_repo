#include<stdio.h>
#include<windows.h>
#include<assert.h>
//ģ��ʵ��qsort(��ð�������˼��)
//�漰�ص�������
//�ص���������ͨ������ָ����õĺ���������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ������
//�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�������һ��ص�������Ҫ����Ա
//�Լ�ʵ�֡�����qsort���ǵ��͵Ļص�������Ӧ��

/*
   arr:����������
   num:�����������е�Ԫ�ظ���
   size:�����������е�Ԫ�����͵Ĵ�С
   comp:����ָ��--->Ҫ�Զ���ıȽϺ���
   int(*comp)(const void*, const void*)��
   �βε����壺����������������������Ԫ�صĵ�ַ
*/
int CompInt(const void* x_, const void* y_)
{
	int *n1 = (int*)(x_);
	int *n2 = (int*)(y_);
	//����
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
	char *e = (char*)arr;//������һ���ֽ�Ϊ��λ���в�����Ҳ����˵��������ֻ�õ���
	                     //char��һ���ֽڴ�С�����������������������ǲ����ġ�
	for (int i = 0; i < num - 1; i++){
		int flag = 1;
		for (int j = 0; j < num - 1 - i; j++){
			if (comp(e+j*size,e+(j+1)*size)>0){
				//ִ�н����߼�
				flag = 0;
				swap(e+j*size,e+(j+1)*size,size);
			}
		}
		if (flag){
			break;
		}
	}
}

//��ӡָ������
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
	//ָ������
	//char* str[] = { "aaa", "ddd", "ccc", "bbb" };
	int arr[] = { 99, 11, 22, 66, 55, 44 };
	//int num = sizeof(str) / sizeof(str[0]);
	int num1 = sizeof(arr) / sizeof(arr[0]);
	int size = sizeof(char*);
	printf("����ǰ��\n");
	//PrintStr(arr, num1);
	PrintInt(arr, num1);
	my_qsort(arr, num1, size,CompInt);
	printf("�����\n");
	PrintInt(arr, num1);
	//PrintStr(arr, num1);

	system("pause");
	return 0;
}