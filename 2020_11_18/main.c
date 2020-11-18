#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int findRound(const char * src, char * find)
{
	char tmp[256] = { 0 }; //��һ�������ռ佫ԭ�ַ�����������ԭ�ַ���
	strcpy(tmp, src); //�ȿ���һ��
	strcat(tmp, src); //������һ��
	return strstr(tmp, find) != NULL; //�����Ҳ��ҵõ�
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
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*/
//�ֲ������ַ���
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
//����������ַ�
void left_round(char *str, int k){
	int len = strlen(str);
	int pos = k%len;
	reverse_part(str, 0, pos - 1);
	reverse_part(str, pos, len - 1);
	reverse_part(str, 0, len - 1);
}
//����������ַ�
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