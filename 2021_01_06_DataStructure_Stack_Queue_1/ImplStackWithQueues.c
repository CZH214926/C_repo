//用队列实现栈

#include <stdio.h>
#include<assert.h>
#include <stdlib.h>
//队列：底层用无头单向链表实现
typedef int QueueDataType;
//队列中的单链表的节点
typedef struct QueueNode 
{
	struct QueueNode* _next;
	QueueDataType data;
} QueueNode;
//队列
typedef struct Queue 
{
	QueueNode* _head;
	QueueNode* _tail;
} Queue;

//声明

//队列初始化
void QueueInit(Queue* pq);
//队列销毁
void QueueDestory(Queue* pq);
//数据入队列
void QueuePush(Queue* pq,QueueDataType x);
//数据出队列
void QueuePop(Queue* pq);
//获取队头数据
QueueDataType QueueFront(Queue* pq);
//获取队尾数据
QueueDataType QueueBack(Queue* pq);
//判断队列是否为空，1是空队列，0不是
int QueueEmpty(Queue* pq);
//获取队列中的元素个数
int QueueSize(Queue* pq);

//定义
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
void QueuePush(Queue* pq,QueueDataType x)
{
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("内存申请失败！");
		exit(-1);
	}
	
		newNode->data = x;
		newNode->_next = NULL;
	
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail=newNode;//一个节点都没有，别忘记tail，否则
		                              //tail一直为空，程序崩了
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}

}
void QueuePop(Queue* pq)
{
	
	assert(pq);
	assert(pq->_head);
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	//头删，要注意队列只有一个节点的情况，tail会成野指针
	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}
QueueDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->data;
}
QueueDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);
	return pq->_tail->data;
}

//1是空队列，0不是
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
	//return !pq->_head;
}
int QueueSize(Queue* pq)
{
	//这是一个O(n)的接口
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_head;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

typedef struct {
       Queue q1;
       Queue q2;
} MyStack;

//用两个队列实现栈

/** Initialize your data structure here. */

MyStack* myStackCreate() {
   MyStack* st = (MyStack*)malloc(sizeof(MyStack));
   QueueInit(&st->q1);
   QueueInit(&st->q2);
   return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
         //入栈，就往不为空的队列里面入，如果栈中两个队列都为空，往哪里入都无所谓了
         if(!QueueEmpty(&obj->q1))
         {
             QueuePush(&obj->q1,x);
         }
         else
         {
             QueuePush(&obj->q2,x);
         }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
      //出数据
      //一定有一个数列是不为空的，因为题里面说了
      //此时不知道谁为空，要写的代码，要包含全部的情况
    //1、处理空队列和非空队列
    Queue* empty = &obj->q1;
    Queue* nonEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        empty = &obj->q2;
        nonEmpty = &obj->q1;
    }
    //2、把非空队列中的数据移动到空队列中直到非空队列只剩一个数据
    while(QueueSize(nonEmpty)>1)
    {
        //把非空队列的数据一个一个push到空队列
        QueuePush(empty,QueueFront(nonEmpty));
        //从非空队列中pop掉这个数据
        QueuePop(nonEmpty);
    }
    //3、循环完非空队列中还有一个数据，把这个数据返回并pop掉
    int top = QueueFront(nonEmpty);
    QueuePop(nonEmpty);
    return top;  
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	   //栈顶元素其实就是栈中两个队列中非空队列的尾元素
       if(!QueueEmpty(&obj->q1))
       {
           return QueueBack(&obj->q1);
       }
       else 
       {
           return  QueueBack(&obj->q2);
       }
       
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	//栈中两个队列都为空才证明栈为空
     return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
     QueueDestory(&obj->q1);
     QueueDestory(&obj->q2);
     free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/