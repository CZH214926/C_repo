#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

int CompInt(const void* x, const void* y){
	int* n1 = (int*)(x);
	int* n2 = (int*)(y);
	if (*n1 > *n2){
		return 1;
	}
	else if (*n1 < *n2){
		return -1;
	}
	else{
		return 0;
	}
}
void PrintArr(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	printf("\n");
}
PrintStr(char* str[], int  num){
	for (int i = 0; i < num; i++){
		printf("%s\n", str[i]);
	}
	printf("\n");
}
int CompStr(const void* x, const void* y){
	char* s1 = *(char**)(x);
    char* s2 = *(char**)(y);
	return strcmp(s1, s2);
}
int main()
{
	/*
	   最强指针辨析，不接收反驳
	*/
	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char** cp[] = { c + 3, c + 2, c + 1, c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);


	system("pause");
	return 0;
}