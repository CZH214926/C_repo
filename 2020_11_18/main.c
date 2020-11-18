#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int findRound(const char * src, char * find)
{
	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
	strcpy(tmp, src); //先拷贝一遍
	strcat(tmp, src); //再连接一遍
	return strstr(tmp, find) != NULL; //看看找不找得到
}
#if 0
int main()
{
	int ret = findRound("AABCD", "BCDAA");
	printf("%d\n", ret);

	system("pause");
	return 0;
}
#endif
/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/
//局部逆序字符串
void reverse_part(char *str, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
//左旋任意个字符
void left_round(char *str, int k){
	int len = strlen(str);
	int pos = k%len;
	reverse_part(str, 0, pos - 1);
	reverse_part(str, pos, len - 1);
	reverse_part(str, 0, len - 1);
}
//右旋任意个字符
void right_round(char* str, int k){
	int len = strlen(str);
	int pos = k%len;
	reverse_part(str, 0, len - pos - 1);
	reverse_part(str, len-pos, len - 1);
	reverse_part(str, 0, len - 1);
}

int main()
{
	char str[] = "chenzhihao";

	left_round(str, 4);
	printf("%s\n", str);

	right_round(str, 3);
	printf("%s\n", str);

	system("pause");
	return 0;
}