//�ö���ʵ��ջ

#include <stdio.h>
#include<assert.h>
#include <stdlib.h>
//���У��ײ�����ͷ��������ʵ��
typedef int QueueDataType;
//�����еĵ�����Ľڵ�
typedef struct QueueNode 
{
	struct QueueNode* _next;
	QueueDataType data;
} QueueNode;
//����
typedef struct Queue 
{
	QueueNode* _head;
	QueueNode* _tail;
} Queue;

//����

//���г�ʼ��
void QueueInit(Queue* pq);
//��������
void QueueDestory(Queue* pq);
//���������
void QueuePush(Queue* pq,QueueDataType x);
//���ݳ�����
void QueuePop(Queue* pq);
//��ȡ��ͷ����
QueueDataType QueueFront(Queue* pq);
//��ȡ��β����
QueueDataType QueueBack(Queue* pq);
//�ж϶����Ƿ�Ϊ�գ�1�ǿն��У�0����
int QueueEmpty(Queue* pq);
//��ȡ�����е�Ԫ�ظ���
int QueueSize(Queue* pq);

//����
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
		printf("�ڴ�����ʧ�ܣ�");
		exit(-1);
	}
	
		newNode->data = x;
		newNode->_next = NULL;
	
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail=newNode;//һ���ڵ㶼û�У�������tail������
		                              //tailһֱΪ�գ��������
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
	//ͷɾ��Ҫע�����ֻ��һ���ڵ�������tail���Ұָ��
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

//1�ǿն��У�0����
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
	//return !pq->_head;
}
int QueueSize(Queue* pq)
{
	//����һ��O(n)�Ľӿ�
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

//����������ʵ��ջ

/** Initialize your data structure here. */

MyStack* myStackCreate() {
   MyStack* st = (MyStack*)malloc(sizeof(MyStack));
   QueueInit(&st->q1);
   QueueInit(&st->q2);
   return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
         //��ջ��������Ϊ�յĶ��������룬���ջ���������ж�Ϊ�գ��������붼����ν��
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
      //������
      //һ����һ�������ǲ�Ϊ�յģ���Ϊ������˵��
      //��ʱ��֪��˭Ϊ�գ�Ҫд�Ĵ��룬Ҫ����ȫ�������
    //1������ն��кͷǿն���
    Queue* empty = &obj->q1;
    Queue* nonEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        empty = &obj->q2;
        nonEmpty = &obj->q1;
    }
    //2���ѷǿն����е������ƶ����ն�����ֱ���ǿն���ֻʣһ������
    while(QueueSize(nonEmpty)>1)
    {
        //�ѷǿն��е�����һ��һ��push���ն���
        QueuePush(empty,QueueFront(nonEmpty));
        //�ӷǿն�����pop���������
        QueuePop(nonEmpty);
    }
    //3��ѭ����ǿն����л���һ�����ݣ���������ݷ��ز�pop��
    int top = QueueFront(nonEmpty);
    QueuePop(nonEmpty);
    return top;  
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	   //ջ��Ԫ����ʵ����ջ�����������зǿն��е�βԪ��
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
	//ջ���������ж�Ϊ�ղ�֤��ջΪ��
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