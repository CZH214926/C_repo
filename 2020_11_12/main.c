#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int Add(int x, int y){
	return x + y;
}
int Sub(int x, int y){
	return x - y;
}
int Mul(int x, int y){
	return x * y;
}
int Div(int x, int y){
	if (0 == y){
		printf("erro:div zero!\n");
		return -1;
	}
	return x / y;
}
void Menu(){
	printf("*****************************\n");
	printf("****1.Add     2.Sub *********\n");
	printf("****3.Mul     4.Div**********\n");
	printf("****5.Exit         **********\n");
}

#define NUM 5

int main()
{
	/*
	  函数指针数组的应用---转移表
	*/

	/*
	  函数指针数组，数组里面放的是函数指针，而函数指针用函数名就可以表示，
	  当然也可以 “&函数名”，但是少写个&何乐而不为呢。
	  要求这里的函数返回值和形参列表都完全一样
	*/
	int(*f[NUM])(int, int) = {NULL, Add, Sub, Mul, Div };
	printf("请输入你想要的计算器：\n");
	int quit = 0;
	while (!quit)
	{
		Menu();
		int select = 0;
		printf("请输入你想要的计算器:");
		scanf("%d", &select);
		if (select<1 || select>5)
		{
			printf("输入错误请重新输入：\n");
			continue;
		}
		if (5 == select)
		{
			break;
		}
		int x = 0, y = 0;
		printf("请输入两个数字：\n");
		scanf("%d %d", &x, &y);

		int ret = f[select](x, y);//Add(x,y)--->已经做了解引用

		printf("最后的结果为:%d\n",ret);

	}


	system("pause");
	return 0;
}