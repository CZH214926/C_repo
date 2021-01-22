#pragma once
#include <stdio.h>
#include<assert.h>
#include <windows.h>
#include <stdlib.h>

//�������Ľ������
struct BinaryTreeNode;
//���У��ײ�����ͷ��������ʵ��
typedef struct BinaryTreeNode* QueueDataType;
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



