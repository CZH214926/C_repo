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
	  ����ָ�������Ӧ��---ת�Ʊ�
	*/

	/*
	  ����ָ�����飬��������ŵ��Ǻ���ָ�룬������ָ���ú������Ϳ��Ա�ʾ��
	  ��ȻҲ���� ��&����������������д��&���ֶ���Ϊ�ء�
	  Ҫ������ĺ�������ֵ���β��б���ȫһ��
	*/
	int(*f[NUM])(int, int) = {NULL, Add, Sub, Mul, Div };
	printf("����������Ҫ�ļ�������\n");
	int quit = 0;
	while (!quit)
	{
		Menu();
		int select = 0;
		printf("����������Ҫ�ļ�����:");
		scanf("%d", &select);
		if (select<1 || select>5)
		{
			printf("����������������룺\n");
			continue;
		}
		if (5 == select)
		{
			break;
		}
		int x = 0, y = 0;
		printf("�������������֣�\n");
		scanf("%d %d", &x, &y);

		int ret = f[select](x, y);//Add(x,y)--->�Ѿ����˽�����

		printf("���Ľ��Ϊ:%d\n",ret);

	}


	system("pause");
	return 0;
}