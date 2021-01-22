#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <assert.h>

//一、插入排序
//1、直接插入排序
void InsertSort(int* arr, int n);
//2、升级版的直接插入排序---希尔排序
void ShellSort(int* arr, int n);

//二、选择排序
//1、
//1.1直接选择排序 --一次选两个数
void SelectSort1(int* arr, int n);
//1.2直接选择排序 ---一次选一个数
void SelectSort2(int* arr, int n);
//2、超级升级版的选择排序 ------- 堆排序
void HeapSort(int* arr, int n);

//冒泡排序
void BubbleSort(int* arr, int n);