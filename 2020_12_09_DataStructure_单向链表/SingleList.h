#pragma once

#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>

//�ڵ��ڵ���������
typedef int SingleListDataType;
//������ڵ�����
typedef struct SingleListNode
{
	SingleListDataType data;
	struct SingleListNode* next;
}SLNode;


//1�������ڵ�
SLNode* BuySListNode(SingleListDataType x);
//2����ӡ����
void SListPrint(SLNode* phead);
//3��β��
void SListPushBack(SLNode** pphead, SingleListDataType x);
//4��βɾ
void SListPopBack(SLNode** pphead);
//5��ͷ��
void SListPushFront(SLNode** pphead, SingleListDataType x);
//6��ͷɾ
void SListPopFront(SLNode** pphead);
//7����posλ�ú����
void SListInsertAfter(SLNode* phead, SingleListDataType x);

//8����posλ�ú�ɾ��
void SListEraseAfter(SLNode* pos);

//9������
SLNode* SListFind(SLNode* phead, SingleListDataType x);
