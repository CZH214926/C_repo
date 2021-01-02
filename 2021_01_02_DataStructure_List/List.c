#include "List.h"
//C语言中除了静态变量和全局变量不初始化会有初始值，其他的是随机值，随机值会带来
//问题
ListNode* BuyListNode(ListDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	if (cur != pHead)
	{
		while (cur != pHead)
		{
			printf("%d ", cur->val);
			cur = cur->next;
		}
		printf("\n");
	}
	else
	{
		printf("NULL");
		printf("\n");
	}

}
void ListInit0(ListNode** ppHead)
{
	*ppHead = BuyListNode(0);
	(*ppHead)->next = *ppHead;
	(*ppHead)->prev = *ppHead;
}
ListNode* ListInit1()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(ListNode* pHead, ListDataType x)
{
	assert(pHead);
	//ListNode* tail = pHead->prev;
	//ListNode* newNode = BuyListNode(x);
	//// pHead tail newNode
	//tail->next = newNode;
	//newNode->prev = tail;
	//newNode->next = pHead;
	//pHead->prev = newNode;
	ListInsert(pHead, x);

}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	//ListNode* tail = pHead->prev;
	//ListNode* tailPrev = tail->prev;
	////pHead tail tailPrev
	//pHead->prev = tailPrev;
	//tailPrev->next = pHead;
	//free(tail);
	//tail = NULL;//置空tail防止野指针，因为tail是局部变量，不置空也不会有影响
	////当时要养成好的习惯
	ListErase(pHead->prev);
}
void ListPushFront(ListNode* pHead, ListDataType x)
{
	assert(pHead);
	ListNode* newNode = BuyListNode(x);
	//ListNode* first = pHead->next;
	////phead  newNode first 
	//pHead->next = newNode;
	//newNode->prev = pHead;
	//newNode->next = first;
	//first->prev = newNode;
	ListInsert(pHead->next, x);//代码复用
}
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	//ListNode* first = pHead->next;
	//ListNode* second = first->next;
	////pHead first second
	//pHead->next = second;
	//second->prev = pHead;
	//free(first);
	//first = NULL;
	ListErase(pHead->next);
	
}
ListNode* ListFind(ListNode* pHead, ListDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, ListDataType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);
	ListNode* posPrev = pos->prev;
	//posPrev newNode pos
	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}
void ListClear(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
}
void ListDestory(ListNode** ppHead)
{
	assert(*ppHead);
	ListClear(*ppHead);
	free(*ppHead);
	*ppHead = NULL;
}
