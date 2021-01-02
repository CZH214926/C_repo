#pragma once
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>

typedef int ListDataType;
//˫��ѭ����ͷѭ������Ľڵ�   ����ͷ�ڵ����ڱ�λ��ͷ�ڵ�
typedef struct ListNode
{
	struct ListNode* prev;
	ListDataType val;
	struct ListNode* next;
} ListNode;

ListNode* BuyListNode();
void ListInit0(ListNode** ppHead);
ListNode* ListInit1();
void ListDestory(ListNode** ppHead);
void ListClear(ListNode* pHead);
void ListPrint(ListNode* pHead);
void ListPushBack(ListNode* pHead, ListDataType x);
void ListPopBack(ListNode* pHead);
void ListPushFront(ListNode* pHead, ListDataType x);
void ListPopFront(ListNode* pHead);
ListNode* ListFind(ListNode* pHead, ListDataType x);//�˷�������ΪInsert Erase����
void ListInsert(ListNode* pos, ListDataType x);//��posǰ�����
void ListErase(ListNode* pos);
