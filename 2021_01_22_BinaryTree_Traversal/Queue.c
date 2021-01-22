#include "Queue.h"

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
		//要先保存你要释放节点的下一个节点，否则你就找不到next了
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
void QueuePush(Queue* pq,QueueDataType x)
{
	//断言pq不能为空，
	assert(pq);
	//
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("内存申请失败！");
		exit(-1);
	}
	
		newNode->data = x;
		newNode->_next = NULL;
	//以上操作都为申请一个新的节点并把x给这个节点
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail=newNode;//一个节点都没有，别忘记tail，否则
		                              //tail一直为空，程序崩了
	}
	else
	{
		//newNode链接到尾后面，并更新尾指针的位置
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