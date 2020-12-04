#include "SeqList.h"

//初始化动态循序表
void SLInit(SL* psl){
	psl->array = (SLDataType*)(malloc(sizeof(SLDataType)* 4));
	if (psl->array == NULL){
		printf("malloc error!");
		exit(-1);
	}
	psl->capacity = 4;
	psl->size = 0;
	
}
//扩容
void SLExpandCapacity(SL* psl){
	if (psl->size >= psl->capacity){
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SLDataType)*psl->capacity);
		if (psl->array == NULL){
			printf("扩容失败！\n");
			exit(-1);
		}
	}
}
//打印动态顺序表中的数据
void SLPrint(SL* psl){
	assert(psl);
	for (int i = 0; i < psl->size; i++){
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
//尾插
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	//如果满了就要增容，2倍
	SLExpandCapacity(psl);


	psl->array[psl->size] = x;
	psl->size++;
}

/*无论在头部插入数据还是在尾部插入数据，都要考虑当容量不够，去扩容*/
//尾删
void SLPopBack(SL* psl){
	assert(psl);
	psl->size--;
}
//头插
void SLPushFront(SL* psl, SLDataType x){
	assert(psl);
	//如果满了就要增容，2倍
	SLExpandCapacity(psl);
	int end = psl->size - 1;
	//从尾部向右移动数据
	while (end >= 0){
		
		psl->array[end + 1] = psl->array[end];
		end--;
	}
	psl->array[0] = x;
	psl->size++;
}
//头删
void SLPopFront(SL* psl){
	assert(psl);
	int start = 0;
	while (start < psl->size - 1)
	{
		psl->array[start] = psl->array[start + 1];
		start++;
	}
	psl->size--;
}
//任意位置插入
void SLInsert(SL* psl, size_t pos, SLDataType x){
	assert(psl);
	int end = psl->size - 1;
	while (end >= pos){
		psl->array[end + 1] = psl->array[end];
		end--;
	}
	psl->array[pos] = x;
	psl->size++;
}
//任意位置删除
void SLErase(SL* psl, size_t pos){
	assert(psl);
	while (pos < psl->size - 1){
		psl->array[pos] = psl->array[pos + 1];
		pos++;
	}
	psl->size--;
}

void SLDestory(SL* psl){
	assert(psl);
	psl->size = 0;
}

int SLFind(SL* psl, SLDataType x){
	assert(psl);
	int start = 0;
	int end = psl->size - 1;
	int mid = 0;
	while (start <= end){
		mid = start + ((end - start) >> 1);
		if (x > psl->array[mid]){
			start = mid + 1;
		}
		else if (x < psl->array[mid]){
			end = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
//顺序表排序
void SLSort(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				SLDataType temp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = temp;
				flag = 0;
				
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}