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
		//Ҫ�ȱ�����Ҫ�ͷŽڵ����һ���ڵ㣬��������Ҳ���next��
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
void QueuePush(Queue* pq,QueueDataType x)
{
	//����pq����Ϊ�գ�
	assert(pq);
	//
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("�ڴ�����ʧ�ܣ�");
		exit(-1);
	}
	
		newNode->data = x;
		newNode->_next = NULL;
	//���ϲ�����Ϊ����һ���µĽڵ㲢��x������ڵ�
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail=newNode;//һ���ڵ㶼û�У�������tail������
		                              //tailһֱΪ�գ��������
	}
	else
	{
		//newNode���ӵ�β���棬������βָ���λ��
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