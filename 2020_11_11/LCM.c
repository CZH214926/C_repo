#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
/*
   ��С����������(a*b)/���Լ��
   ֻҪ������Լ������С������Ҳ��ӭ�ж���
*/
int GetGCD(int m, int n){
	
	int c = 0;
	while (c = m%n)
	{
		m = n;
		n = c;
	}
	return n;
}
int main()
{
	int x = 0, y = 0;
	printf("��������������:\n");
	scanf("%d %d", &x, &y);
	int ret = x*y / GetGCD(x, y);
	printf("%d��%d����С������Ϊ%d:\n", x, y, ret);


	system("pause");
	return 0;
}