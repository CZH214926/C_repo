#include "SingleList.h"

//1�������ڵ�
SLNode* BuySListNode(SingleListDataType x)
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//2����ӡ����
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
//3��β��
void SListPushBack(SLNode** pphead, SingleListDataType x)
{
	SLNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//�ҵ�β��
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
//4��βɾ
void SListPopBack(SLNode** pphead)
{
	//1������Ϊ��
	//2������ֻ��һ���ڵ�
	//3��������һ�����ϵĽڵ�
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
		//�ҵ�β�ڵ��ͷŵ�������β�ڵ��ǰһ���ڵ㣬pre.next = NULL;
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

//5��ͷ��
void SListPushFront(SLNode** pphead, SingleListDataType x)
{

	//����Ϊ��
	//����ǿ�
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
//6��ͷɾ
void SListPopFront(SLNode** pphead)
{
	//����Ϊ��ֱ�ӷ���
	if (*pphead == NULL)
	{
		return;
	}//����ǿ�һ���ڵ����ڵ㶼����
	else
	{
		SLNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}


}
//7����posλ�ú����
void SListInsertAfter(SLNode* pos, SingleListDataType x)
{
	assert(pos);
	SLNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;

}
//8����posλ�ú�ɾ��
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

//9������
SLNode* SListFind(SLNode* phead, SingleListDataType x)
{
	
		//��������
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