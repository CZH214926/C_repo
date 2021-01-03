#include "Stack.h"

//��ʼ��ջ
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (StackDataType*)malloc(sizeof(StackDataType)* 4);
	pst->_top = 0;
	pst->_capacity = 4;
}
//����ջ
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}
//��ջ
void StackPush(Stack* pst, StackDataType x)
{
	assert(pst);
	//�ж��Ƿ���Ҫ����
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
			printf("�ڴ�����ʧ�ܣ�");
			exit(-1);
		}
	}

	pst->_a[pst->_top] = x;
	pst->_top++;

}
//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	pst->_top--;

}
//��ȡջ�����ݸ���
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//�ж�ջ�Ƿ�Ϊ�գ��շ���1���ǿշ���0
int StackEmpty(Stack* pst)
{
	assert(pst);
	//return !pst->_top;
	return pst->_top == 0 ? 1 : 0;

}
//��ȡջ������
StackDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top - 1];
}
