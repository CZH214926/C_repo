#pragma once
#include <stdio.h>
#include<assert.h>
#include <windows.h>
#include <stdlib.h>

//二叉树的结点声明
struct BinaryTreeNode;
//队列：底层用无头单向链表实现
typedef struct BinaryTreeNode* QueueDataType;
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



