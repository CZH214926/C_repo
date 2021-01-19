#include "SeqList.h"

//��ʼ����̬ѭ���
void SLInit(SL* psl){
	psl->array = (SLDataType*)(malloc(sizeof(SLDataType)* 4));
	if (psl->array == NULL){
		printf("malloc error!");
		exit(-1);
	}
	psl->capacity = 4;
	psl->size = 0;
	
}
//����
void SLExpandCapacity(SL* psl){
	if (psl->size >= psl->capacity){
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SLDataType)*psl->capacity);
		if (psl->array == NULL){
			printf("����ʧ�ܣ�\n");
			exit(-1);
		}
	}
}
//��ӡ��̬˳����е�����
void SLPrint(SL* psl){
	assert(psl);
	for (int i = 0; i < psl->size; i++){
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
//β��
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	//������˾�Ҫ���ݣ�2��
	SLExpandCapacity(psl);


	psl->array[psl->size] = x;
	psl->size++;
}

/*������ͷ���������ݻ�����β���������ݣ���Ҫ���ǵ�����������ȥ����*/
//βɾ
void SLPopBack(SL* psl){
	assert(psl);
	psl->size--;
}
//ͷ��
void SLPushFront(SL* psl, SLDataType x){
	assert(psl);
	//������˾�Ҫ���ݣ�2��
	SLExpandCapacity(psl);
	int end = psl->size - 1;
	//��β�������ƶ�����
	while (end >= 0){
		
		psl->array[end + 1] = psl->array[end];
		end--;
	}
	psl->array[0] = x;
	psl->size++;
}
//ͷɾ
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
//����λ�ò���
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
//����λ��ɾ��
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
//˳�������
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