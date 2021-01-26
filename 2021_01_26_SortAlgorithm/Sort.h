#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <assert.h>

//һ����������
//1��ֱ�Ӳ�������
void InsertSort(int* arr, int n);
//2���������ֱ�Ӳ�������---ϣ������
void ShellSort(int* arr, int n);

//����ѡ������
//1��
//1.1ֱ��ѡ������ --һ��ѡ������
void SelectSort1(int* arr, int n);
//1.2ֱ��ѡ������ ---һ��ѡһ����
void SelectSort2(int* arr, int n);
//2�������������ѡ������ ------- ������
void HeapSort(int* arr, int n);

//ð������
void BubbleSort(int* arr, int n);

//���ŵݹ�汾
//��ѡ��key��ʱ����ѡ����λ����������λ�����ǲ���ȷ���ģ�����Ҫ�����Ż���
//˫ָ�뷨
int PartSort1(int* arr, int begin, int end);
//�ڿӷ�
int PartSort2(int* arr, int begin, int end);
//ǰ��ָ�뷨
int PartSort3(int* arr, int begin, int end);
//����������
void QuickSort(int* arr, int left, int right);

//���ŷǵݹ�
void QuickSortNonR(int* arr, int left, int right);

//����������ۺ���������õģ���C��׼���C++���е������㷨һ����õ����Ż����QuickSort
//���������ʱ�临�Ӷ��ǣ�O(N*logN),�ռ临�Ӷ��ǣ�O(logN).
// �鲢����ݹ�ʵ��
//ʱ�临�Ӷ�O(N*logN)
void MergeSort(int* arr, int n);
//�鲢����ǵݹ�ʵ��
void MergeSortNonR(int* arr, int n);

//��������
void CountSort(int* arr, int n);
