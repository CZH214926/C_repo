//用栈实现队列


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int StackDataType;
//动态增长的栈
//底层实现是数组
typedef struct Stack
{
	StackDataType* _a;//数组名
	int _top;         //栈顶
	int _capacity;    //栈的容量
}Stack;
//初始化栈
void StackInit(Stack* pst);
//销毁栈
void StackDestory(Stack* pst);
//入栈
void StackPush(Stack* pst, StackDataType x);
//出栈
void StackPop(Stack* pst);
//获取栈的数据个数
int StackSize(Stack* pst);
//判断栈是否为空，空返回1，非空返回0
int StackEmpty(Stack* pst);
//获取栈顶数据
StackDataType StackTop(Stack* pst);


//以上为声明，以下为定义
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
	pst->_a = NULL;//防止野指针
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
	assert(pst->_top > 0);//栈里没有数据是不能出栈的
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
	//空帧栈顶没有数据，不能获取
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
      //把MyQueue中的_popST中的栈顶数据取出并返回，要是_popST为空，则把_pushST中的数据全部移动到_popST里
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
       free(obj);//外面的野指针让调用的人去处理
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