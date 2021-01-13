/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //topk问题
 //思路：求最小的前K个数，建前k个数的大堆，从第k+1个数开始和堆顶的数据比较比堆顶小的就替换堆顶的数据，直到把所有的数据都遍历完
 //这个堆里面的数据就是最小的前K个，堆顶的数据就是第k个数据。
 //同理如果是求最大的前K个数，是建小堆
void  AdjustDown(int* arr,int n,int root)
{
    int parent = root;
    int child = 2*parent +1;
    while(child<n)
    {
        if(child+1<n && arr[child+1]>arr[child])
        {
            child++;
        }
        if(arr[child]>arr[parent])
        {
            int tmp = arr[child];
            arr[child] = arr[parent];
            arr[parent]=tmp;
            parent = child;
            child = 2*parent+1;
        }
        else
        {
            break;
        }
    }
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
       //1、建前k个数的大堆
       *returnSize = k;
       if(k==0)
       {
           return NULL;
       }
       int* retArr = (int*)malloc(sizeof(int)*k);
       //把原始数据中前k个数放进retArr中
       for(int i = 0;i<k;i++)
       {
           retArr[i] = arr[i];
       }
       //建大堆
       for(int i = (k-1-1)/2;i>=0;i--)
       {
           AdjustDown(retArr,k,i);
       }
       //2、建完堆后开始和原始数组中的数据进行比较
       for(int i = k;i<arrSize;i++)
       {
           if(arr[i]<retArr[0])
           {
               retArr[0]=arr[i];
               AdjustDown(retArr,k,0);
           }
       }
       return retArr;
}