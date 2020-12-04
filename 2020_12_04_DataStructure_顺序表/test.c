#include "SeqList.h"

void test01(){
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 66);
	SLPushBack(&s, 5);
	SLPushBack(&s, 55);
	SLPushBack(&s, 7);
	SLPushBack(&s, 88);
	SLPushBack(&s, 11);

	SLPrint(&s);

	SLSort(&s);

	SLPrint(&s);

	
	printf("元素11的下标为:%d\n", SLFind(&s, 11));
	
}
int main()
{
	test01();

	system("pause");
	return 0;
}