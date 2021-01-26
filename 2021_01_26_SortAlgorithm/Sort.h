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

//快排递归版本
//在选择key的时候尽量选择中位数，但是中位数又是不能确定的，所以要进行优化。
//双指针法
int PartSort1(int* arr, int begin, int end);
//挖坑法
int PartSort2(int* arr, int begin, int end);
//前后指针法
int PartSort3(int* arr, int begin, int end);
//快排主程序
void QuickSort(int* arr, int left, int right);

//快排非递归
void QuickSortNonR(int* arr, int left, int right);

//快速排序的综合性能是最好的，在C标准库和C++库中的排序算法一般采用的是优化后的QuickSort
//快速排序的时间复杂度是：O(N*logN),空间复杂度是：O(logN).
// 归并排序递归实现
//时间复杂度O(N*logN)
void MergeSort(int* arr, int n);
//归并排序非递归实现
void MergeSortNonR(int* arr, int n);

//计数排序
void CountSort(int* arr, int n);
