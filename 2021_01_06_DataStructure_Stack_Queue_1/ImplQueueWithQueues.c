//��ջʵ�ֶ���


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int StackDataType;
//��̬������ջ
//�ײ�ʵ��������
typedef struct Stack
{
	StackDataType* _a;//������
	int _top;         //ջ��
	int _capacity;    //ջ������
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


//����Ϊ����������Ϊ����
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
	pst->_a = NULL;//��ֹҰָ��
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
	assert(pst->_top > 0);//ջ��û�������ǲ��ܳ�ջ��
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
	//��֡ջ��û�����ݣ����ܻ�ȡ
	assert(pst->_top > 0);
	return pst->_a[pst->_top - 1];
}


typedef struct {
   Stack _pushST;
   Stack _popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* mq = ( MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&mq->_pushST);
    StackInit(&mq->_popST);
    return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
     StackPush(&obj->_pushST,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
      int front = myQueuePeek(obj);
      StackPop(&obj->_popST);
      return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
      //��MyQueue�е�_popST�е�ջ������ȡ�������أ�Ҫ��_popSTΪ�գ����_pushST�е�����ȫ���ƶ���_popST��
      if(!StackEmpty(&obj->_popST))
      {
          return StackTop(&obj->_popST);
      }
      else
      {
          while(!StackEmpty(&obj->_pushST))
          {
              StackPush(&obj->_popST,StackTop(&obj->_pushST));
              StackPop(&obj->_pushST);
          }
          return StackTop(&obj->_popST);
      }
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
        return StackEmpty(&obj->_pushST) && StackEmpty(&obj->_popST);
}

void myQueueFree(MyQueue* obj) {
       StackDestory(&obj->_pushST);
       StackDestory(&obj->_popST);
       free(obj);//�����Ұָ���õ��õ���ȥ����
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/