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

//堆的初始化，内部有堆的创建
void HeapInit(Heap* php, HeapDataType* a, int n);
//堆的销毁
void HeapDestory(Heap* php);
//堆的插入数据
void HeapPush(Heap* php, HeapDataType x);
//堆的删除数据
void HeapPop(Heap* php);
//获取堆顶数据
HeapDataType HeapTop(Heap* php);
//对传入的数组内的数据进行堆排序
void HeapSort(int* a, int n);