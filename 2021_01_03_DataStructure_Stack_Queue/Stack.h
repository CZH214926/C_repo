#pragma once
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>


typedef int StackDataType;

typedef struct Stack
{
	StackDataType* _a;
	int _top;
	int _capacity;
}Stack;
//��ʼ��ջ
void StackInit(Stack* pst);
//����ջ
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst, StackDataType x);
//��ջ
void StackPop(Stack* pst);
//��ȡջ�����ݸ���
int StackSize(Stack* pst);
//�ж�ջ�Ƿ�Ϊ�գ��շ���1���ǿշ���0
int StackEmpty(Stack* pst);
//��ȡջ������
StackDataType StackTop(Stack* pst);
