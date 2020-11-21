#include<stdio.h>
#include<assert.h>
#include<windows.h>
/*
   �⺯��ģ��ʵ��
*/

/*
  һ���ַ�����Ч���ȣ�strlen ģ��ʵ��
*/
//����һ��������
size_t my_strlen_1(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;	
	}
	return count;
}
//�ݹ�
size_t my_strlen_2(const char * str)
{
	if (*str == '\0'){
		return 0;
	}
	else{
		return 1 + my_strlen_2(str + 1);
	}
}
//ָ��-ָ��ķ�ʽ
size_t my_strlen_3(const char *str)
{
	const char *p = str;
	while (*p){
		p++;
	}
	return p - str;
}
/*
  ���� ģ��ʵ��strcpy
 */
char *my_strcpy(char *dest, const char* src)
{
	assert(dest && src);
	char *ret = dest;
	while (*dest = *src){
		dest++;
		src++;
	}
	return ret;
}
/*
  ����ģ��ʵ��strcat
*/
char *my_strcat(char* dest, const char* src){
	assert(dest&&src);
	char *ret = dest;
	while (*dest){
		dest++;
	}
	while (*dest = *src){
		dest++;
		src++;
	}
	return ret;
}
/*
  ģ��ʵ��strcmp
*/
int my_strcmp(const char * src, const char *dest){
	int ret = 0;
	assert(src != NULL);
	assert(dest != NULL);
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dest) && *dest)
	{
		src++;
		dest++;
	}
	if (ret > 0){
		return 1;
	}
	if (ret < 0){
		return -1;
	}
	return ret;

}

struct Stu{
	char name[32];
	int age;
};
/* 
   ģ��ʵ��memcpy
*/
void * my_memcpy(void * dst, const void *src, size_t num)
{
	assert(dst && src);
	char *_dst = (char *)dst;
	char *_src = (const char*)src;
	while (num){
		*_dst = *_src;
		_src++;
		_dst++;
		num--;
	}
}
/*
   ģ��ʵ��memmove
*/
void * my_memmove(void * dst, const void *src, size_t num)
{
	assert(dst && src);
	char *_dst = (char *)dst;
	char *_src = (const char*)src;

	if (_dst > _src && _dst < _src + num)
	{
		//�������󿽱�
		_dst = _dst + num - 1;
		_src = _src + num - 1;
		while (num){
			*_dst = *_src;
			_src--;
			_dst--;
			num--;
		}
	}
	else{
		//�������ҿ���
		while (num){
			*_dst = *_src;
			_src++;
			_dst++;
			num--;
		}

	}
	
}
int main()
{
	//const char *str = "chenzhihao";
	//int res1 = my_strlen_1(str);
	//printf("my_strlen_1::myname_length = %d\n", res1);
	//int res2 = my_strlen_2(str);
	//printf("my_strlen_2::myname_length = %d\n", res2);
	//int res3 = my_strlen_3(str);
	//printf("my_strlen_3::myname_length = %d\n", res3);

	//char dest[] = "aaaaaaaaaaaaa";
	///*char *res = my_strcpy(dest, str);
	//printf("%s\n", res);*/
	////char *dest1 = "aaaaaaa";
	//char *res4 = my_strcat(dest, str);
	//printf("%s\n", res4);

	/*struct Stu stu_tom = { "tom", 21 };
	struct Stu stu_tom_copy;
	memcpy(&stu_tom_copy, &stu_tom, sizeof(stu_tom));


	const char *src = "abcd1234";
	char dst[16];
	memcpy(dst, src, strlen(src)+1);
	puts(dst);*/

	int a[] = { 1, 2, 3, 4, 5 };
	int b[10] = { 0 };
	my_memcpy(b, a, sizeof(a));

	system("pause");
	return 0;
}