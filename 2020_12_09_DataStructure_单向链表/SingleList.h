#pragma once

#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>

//节点内的数据类型
typedef int SingleListDataType;
//单链表节点类型
typedef struct SingleListNode
{
	SingleListDataType data;
	struct SingleListNode* next;
}SLNode;


//1、新增节点
SLNode* BuySListNode(SingleListDataType x);
//2、打印链表
void SListPrint(SLNode* phead);
//3、尾插
void SListPushBack(SLNode** pphead, SingleListDataType x);
//4、尾删
void SListPopBack(SLNode** pphead);
//5、头插
void SListPushFront(SLNode** pphead, SingleListDataType x);
//6、头删
void SListPopFront(SLNode** pphead);
//7、在pos位置后插入
void SListInsertAfter(SLNode* phead, SingleListDataType x);

//8、在pos位置后删除
void SListEraseAfter(SLNode* pos);

//9、查找
SLNode* SListFind(SLNode* phead, SingleListDataType x);
