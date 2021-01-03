#include "Stack.h"

//初始化栈
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (StackDataType*)malloc(sizeof(StackDataType)* 4);
	pst->_top = 0;
	pst->_capacity = 4;
}
//销毁栈
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}
//入栈
void StackPush(Stack* pst, StackDataType x)
{
	assert(pst);
	//判断是否需要扩容
	if (pst->_capacity == pst->_top)
	{
		pst->_capacity *= 2;
		StackDataType* tmp = (StackDataType*)realloc(pst->_a, sizeof(StackDataType)*pst->_capacity);
		if (tmp)
		{
			pst->_a = tmp;
		}
		else
		{
			printf("内存申请失败！");
			exit(-1);
		}
	}

	pst->_a[pst->_top] = x;
	pst->_top++;

}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	pst->_top--;

}
//获取栈的数据个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//判断栈是否为空，空返回1，非空返回0
int StackEmpty(Stack* pst)
{
	assert(pst);
	//return !pst->_top;
	return pst->_top == 0 ? 1 : 0;

}
//获取栈顶数据
StackDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top - 1];
}
