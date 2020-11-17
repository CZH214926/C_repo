#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)

int MyStrlen(const char* str)
{
	const char *end = str;
	while (*end){
		end++;
	}
	return end - str;
}
int main()
{
	//char *name = "chenzhihao";
	//printf("len = %d\n", MyStrlen(name));
	////strlen的返回值是unsigned int
	//const char* str1 = "c";
	//const char* str2 = "zhi";
	//if (strlen(str1) - strlen(str2) > 0){
	//	printf("str1>str2\n");
	//}
	//else{
	//	printf("str1>str2\n");
	//}
	///*
	//  strlen的返回值为无符号整数，所以只要str1和str1不同，最后的结果肯定是大于0的
	//*/


	//char str3[20];
	//char str4[20];
	//strcpy(str3, "chen zhi hao");
	//strcpy(str4, "nianxin");
	//strncat(str3, str4,2);
	//puts(str3);

	//strncmp
	//char str[5] = "chen";//字符串自己带\0
	//printf("%s\n", str);
	/*har str[][5] = { "R2D2", "C3P0", "R2A6" ,"Ra"};
	for (int i = 0; i < 4; i++)
	{
		if (strncmp(str[i], "R2", 2) <0 )
		{
			printf("found %s\n", str[i]);
		}
	}*/

	//子串查找strstr
	//char str[] = "This is a simple string";//在栈中开辟，字符串内容可以改变
	//char* pstr = strstr(str, "simple");
	//printf("%s\n", pstr);
	//printf("%s\n", str);
	//strncpy(pstr, "This is a", 9);
	//printf("%s\n", pstr);


	//char str1[] = "chen";
	//char* str2 = strcpy(str1, "zhi");
	//printf("%s\n", str2);
	//printf("%s\n", str1);
	/*char str[] = "chenzhihao";
	const char *str1 = "dalanqiu";
	strncat(str, str1,strlen(str1));*/

	/*char str[] = "-This, is a sample string.";
	char *pch;
	
	pch = strtok(str, " -.,");
	while (pch != NULL){
		printf("%s\n", pch);
		pch = strtok(NULL, " -.,");
	}
	*/

	/*for (int i = 0; i < 10; i++){
		printf("%d===>%s\n", i, strerror(i));
		}*/


	//char *p = "zhangpengwei@bitedu.tech";
	//const char* seq = ".@";
	//char str[30];
	//char *substr = NULL;//用来指向每次接收每次切割所得的字符串
	////p指向的字符串在字符常量区，不可改变，所以拷贝一份放到str里
	////
	//strcpy(str, p);

	//for (substr = strtok(str, seq); substr != NULL; substr = strtok(NULL, seq))
	//{
	//	printf("%s\n", substr);
	//}
	/*const char *src = "world!";
	char dst1[17] = "hello aaaaaaaaaa";
	char dst2[] = "hello aaaaaaaaaa";
	printf("%d\n", sizeof(dst1));
	printf("%d\n", sizeof(dst2));
	printf("%s\n", dst1);*/


	char str[] = "This is a simple string";
	char *pch;
	pch = strstr(str, "simple");
	printf("%s\n", pch);


	system("pause");
	return 0;
}