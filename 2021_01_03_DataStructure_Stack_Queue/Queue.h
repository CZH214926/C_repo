#pragma once
#include <stdio.h>
#include<assert.h>
#include <windows.h>
#include <stdlib.h>


typedef int QueueDataType;

typedef struct QueueNode 
{
	struct QueueNode* _next;
	QueueDataType data;
} QueueNode;

typedef struct Queue 
{
	QueueNode* _head;
	QueueNode* _tail;
} Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq,QueueDataType x);
void QueuePop(Queue* pq);
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBack(Queue* pq);

//1是空队列，0不是
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);



