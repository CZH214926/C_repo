#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<string.h>
//��һ��Ӣ���ÿ���������ã���㲻���á�
//�ַ�������ĺ���
void reverse_str(char* left, char* right)
{

	assert(left && right);//���ָ��ǿ�
	while (left < right)
	{
		int temp = *right;
		*right = *left;
		*left = temp;
		left++;
		right--;
	}
}
int main()
{
	char str[100] = {0};
	printf("�����룺\n");
	fgets(str, sizeof(str)-1, stdin);
	str[strlen(str) - 1] = '\0';
	char* begin = str;
	char* end = str; 
	while (*end!='\0')
	{
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		reverse_str(begin, end - 1);
		if (*end != '\0')
		{
			end++;
		}
		begin = end;
	}
	reverse_str(str, str + strlen(str) - 1);
	printf("%s\n", str);
	
	

	system("pause");
	return 0;
}