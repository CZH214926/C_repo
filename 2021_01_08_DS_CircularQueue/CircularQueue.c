//设计循环队列
typedef struct {
    int* _arr;  //循环队列的内部的数组
    int _front;//循环队列首的下标
    int _rear; //循环队列尾加1的下标
    int _k;     //循环队列的长度

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
      MyCircularQueue* mcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
      mcq->_arr = (int*)malloc(sizeof(int)*(k+1));//多开一个位置
      mcq->_front=mcq->_rear=0;
      mcq->_k = k;
      return mcq;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
      return obj->_front==obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
     return (obj->_rear+1)%(obj->_k+1)==obj->_front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
      //如果队列是满的就不能再入数据了
       if(myCircularQueueIsFull(obj))
       {
           return false;
       }
       obj->_arr[obj->_rear]=value;
       obj->_rear++;
       obj->_rear%=(obj->_k+1);
       return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
   if(myCircularQueueIsEmpty(obj))
   {
       return false;
   }
   obj->_front++;
   obj->_front%=(obj->_k+1);
   return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
   if(myCircularQueueIsEmpty(obj))
   {
       return -1;
   }
   return obj->_arr[obj->_front];
}
int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
       return -1;
    }
    int tail = obj->_rear-1;
    if(tail == -1)
    {
        tail = obj->_k;
        //此时rear = 0;rear所在下标的位置要一直是空的，此时tail就是
        //下标为k的位置
    }
    return obj->_arr[tail];
}
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/