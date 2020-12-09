#include "SingleList.h"

void test01()
{
	SLNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPrint(pList);

	SListPushFront(&pList, 23);
	SListPushFront(&pList, 24);

	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);

	SListPrint(pList);

	SListPushFront(&pList, 6);
	SListPushFront(&pList, 7);

	SLNode* pos = SListFind(pList, 6);
	SListPrint(pList);

	if (pos)
	{
		SListEraseAfter(pos);

	}
	
	SListPrint(pList);

	
}
int main()
{
	test01();

	system("pause");
	return 0;
}