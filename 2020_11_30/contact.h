#ifndef _CONTACT_H_
#define _CONTACT_H_

#pragma warning(disable:4996)

#include<stdio.h>
#include<windows.h>
#include<assert.h>
#define SAVE_FILE "save.txt"

#define SIZE 128
#define NUM 1
#define INC_SIZE 1

//��ϵ�˽ṹ��
typedef struct person{
	char name[SIZE/4];
	char sex;
	int age;
	char tel[SIZE/6];
	char addr[SIZE];
} person_t;

//ͨѶ¼�ṹ��
typedef struct contact{
	int cap;//ͨѶ¼������
	int size;//ͨѶ¼�Ѿ����ڵ�����
	person_t persons[0];//��������
} contact_t;

void Menu();
contact_t* InitContact();
void AddPerson(contact_t** ct);
void ShowContact(contact_t* t);
void DelPerson(contact_t* ct);
void Clear(contact_t* ct);
void SaveContact(contact_t* ct);
#endif