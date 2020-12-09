#include "SingleList.h"

//1、新增节点
SLNode* BuySListNode(SingleListDataType x)
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//2、打印链表
void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//3、尾插
void SListPushBack(SLNode** pphead, SingleListDataType x)
{
	SLNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//找到尾巴
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
//4、尾删
void SListPopBack(SLNode** pphead)
{
	//1、链表为空
	//2、链表只有一个节点
	//3、链表有一个以上的节点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找到尾节点释放掉，还有尾节点的前一个节点，pre.next = NULL;
		SLNode* tail = *pphead;
		SLNode* pre = NULL;
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		pre->next = NULL;
	}
}

//5、头插
void SListPushFront(SLNode** pphead, SingleListDataType x)
{

	//链表为空
	//链表非空
	SLNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else{
		newNode->next = *pphead;
		*pphead = newNode;
	}

}
//6、头删
void SListPopFront(SLNode** pphead)
{
	//链表为空直接返回
	if (*pphead == NULL)
	{
		return;
	}//链表非空一个节点多个节点都可以
	else
	{
		SLNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}


}
//7、在pos位置后插入
void SListInsertAfter(SLNode* pos, SingleListDataType x)
{
	assert(pos);
	SLNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;

}
//8、在pos位置后删除
void SListEraseAfter(SLNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SLNode* next = pos->next;
		SLNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}

//9、查找
SLNode* SListFind(SLNode* phead, SingleListDataType x)
{
	
		//遍历链表
		SLNode* cur = phead;
		while (cur)
		{
			if (cur->data == x)
			{
				return cur;
			}
			cur = cur->next;
		}

		return NULL;
}