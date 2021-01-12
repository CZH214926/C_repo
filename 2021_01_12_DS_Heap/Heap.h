#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* arr;
	int size;
	int capacity;
} Heap;

//�ѵĳ�ʼ�����ڲ��жѵĴ���
void HeapInit(Heap* php, HeapDataType* a, int n);
//�ѵ�����
void HeapDestory(Heap* php);
//�ѵĲ�������
void HeapPush(Heap* php, HeapDataType x);
//�ѵ�ɾ������
void HeapPop(Heap* php);
//��ȡ�Ѷ�����
HeapDataType HeapTop(Heap* php);
//�Դ���������ڵ����ݽ��ж�����
void HeapSort(int* a, int n);