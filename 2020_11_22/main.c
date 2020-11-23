#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//结构体的内存对齐
typedef struct s1
{
	char c1;
	int i;
	char c2;
} s1_;
typedef struct s2
{
	char c1;
	char c2;
	int i;
} s2_;
typedef struct s3
{
	double c1;
	char c2;
	int i;
} s3_;
//结构体嵌套
struct s4
{
	char c1;
	struct s3 _s3;
	double d;
};
union Un2
{
	short c[7];
	int i;
};
//可以利用联合判断当前计算机的大小端存储
union Un1
{
	char c;
	int i;
};

int main()
{
	union Un1 un;
	un.i = 1;
	int ret = un.c;
	if (1 == ret){
		printf("小端机器！\n");
	}
	else{
		printf("大端机器！\n");
	}
	printf("%d字节\n", sizeof(union Un2));
	printf("%d字节\n", sizeof(s1_));
	printf("%d字节\n", sizeof(s2_));
	printf("%d字节\n", sizeof(s3_));
	printf("%d字节\n", sizeof(struct s4));

	
	system("pause");
	return 0;
}