#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//�ṹ����ڴ����
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
//�ṹ��Ƕ��
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
//�������������жϵ�ǰ������Ĵ�С�˴洢
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
		printf("С�˻�����\n");
	}
	else{
		printf("��˻�����\n");
	}
	printf("%d�ֽ�\n", sizeof(union Un2));
	printf("%d�ֽ�\n", sizeof(s1_));
	printf("%d�ֽ�\n", sizeof(s2_));
	printf("%d�ֽ�\n", sizeof(s3_));
	printf("%d�ֽ�\n", sizeof(struct s4));

	
	system("pause");
	return 0;
}