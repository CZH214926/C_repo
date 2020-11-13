#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
/*
   最小公倍数等于(a*b)/最大公约数
   只要求出最大公约数，最小公倍数也就迎刃而解
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
	printf("请输入两个数字:\n");
	scanf("%d %d", &x, &y);
	int ret = x*y / GetGCD(x, y);
	printf("%d与%d的最小公倍数为%d:\n", x, y, ret);


	system("pause");
	return 0;
}