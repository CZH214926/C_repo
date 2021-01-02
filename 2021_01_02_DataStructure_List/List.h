#pragma once
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>

typedef int ListDataType;
//双向循环带头循环链表的节点   带的头节点是哨兵位的头节点
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
ListNode* ListFind(ListNode* pHead, ListDataType x);//此方法可以为Insert Erase服务
void ListInsert(ListNode* pos, ListDataType x);//在pos前面插入
void ListErase(ListNode* pos);
