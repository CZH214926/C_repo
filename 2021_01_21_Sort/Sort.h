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