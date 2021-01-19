#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>

#define N 10
typedef int SLDataType;
//静态顺序表
//typedef struct SeqList{
//	SLDataType array[N];//定长数组
//	size_t size;//有效数据个数
//}SeqListS;

//动态顺序表
typedef struct SeqList{
	SLDataType * array;
	size_t size;
	size_t capacity;
}SL;
//初始化动态循序表
void SLInit(SL* psl);
//打印顺序表
void SLPrint(SL* psl);
//扩容
void SLExpandCapacity(SL* psl);
//尾插
void SLPushBack(SL* psl, SLDataType x);
//尾删
void SLPopBack(SL* psl);
//头插
void SLPushFront(SL* psl, SLDataType x);
//头删
void SLPopFront(SL* psl);
//任意位置插入
void SLInsert(SL* psl, size_t pos, SLDataType x);
//任意位置删除
void SLErase(SL* psl, size_t pos);
//顺序表销毁
void SLDestory(SL* psl);
//循序表查找
int SLFind(SL* psl, SLDataType x);
//顺序表排序---冒泡
void SLSort(SL* psl);
#endif