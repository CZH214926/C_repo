#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>

#define N 10
typedef int SLDataType;
//��̬˳���
//typedef struct SeqList{
//	SLDataType array[N];//��������
//	size_t size;//��Ч���ݸ���
//}SeqListS;

//��̬˳���
typedef struct SeqList{
	SLDataType * array;
	size_t size;
	size_t capacity;
}SL;
//��ʼ����̬ѭ���
void SLInit(SL* psl);
//��ӡ˳���
void SLPrint(SL* psl);
//����
void SLExpandCapacity(SL* psl);
//β��
void SLPushBack(SL* psl, SLDataType x);
//βɾ
void SLPopBack(SL* psl);
//ͷ��
void SLPushFront(SL* psl, SLDataType x);
//ͷɾ
void SLPopFront(SL* psl);
//����λ�ò���
void SLInsert(SL* psl, size_t pos, SLDataType x);
//����λ��ɾ��
void SLErase(SL* psl, size_t pos);
//˳�������
void SLDestory(SL* psl);
//ѭ������
int SLFind(SL* psl, SLDataType x);
//˳�������---ð��
void SLSort(SL* psl);
#endif