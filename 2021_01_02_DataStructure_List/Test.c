#include "List.h"

void TestList01()
{
	/*ListNode* pHead = NULL;
	ListInit0(&pHead);*/

	ListNode* pHead = ListInit1();
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);


	ListPrint(pHead);

	ListPopFront(pHead);

	ListPrint(pHead);

	ListDestory(&pHead);
}

int main()
{
	TestList01();
	system("pause");
	return 0;
}