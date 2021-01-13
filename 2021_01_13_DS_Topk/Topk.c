/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //topk����
 //˼·������С��ǰK��������ǰk�����Ĵ�ѣ��ӵ�k+1������ʼ�ͶѶ������ݱȽϱȶѶ�С�ľ��滻�Ѷ������ݣ�ֱ�������е����ݶ�������
 //�������������ݾ�����С��ǰK�����Ѷ������ݾ��ǵ�k�����ݡ�
 //ͬ�������������ǰK�������ǽ�С��
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
       //1����ǰk�����Ĵ��
       *returnSize = k;
       if(k==0)
       {
           return NULL;
       }
       int* retArr = (int*)malloc(sizeof(int)*k);
       //��ԭʼ������ǰk�����Ž�retArr��
       for(int i = 0;i<k;i++)
       {
           retArr[i] = arr[i];
       }
       //�����
       for(int i = (k-1-1)/2;i>=0;i--)
       {
           AdjustDown(retArr,k,i);
       }
       //2������Ѻ�ʼ��ԭʼ�����е����ݽ��бȽ�
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