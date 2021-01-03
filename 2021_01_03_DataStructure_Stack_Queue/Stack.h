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
//初始化栈
void StackInit(Stack* pst);
//销毁栈
void StackDestory(Stack* pst);
//入栈
void StackPush(Stack* pst, StackDataType x);
//出栈
void StackPop(Stack* pst);
//获取栈的数据个数
int StackSize(Stack* pst);
//判断栈是否为空，空返回1，非空返回0
int StackEmpty(Stack* pst);
//获取栈顶数据
StackDataType StackTop(Stack* pst);
