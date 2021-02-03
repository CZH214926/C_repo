#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class Date{
public:
	
	void Print();
	int GetMonthDay(int year,int month);
	//Ĭ�Ϲ���(ȫȱʡ)
	Date(int year = 1996, int month = 11, int day = 1);
	//��������
	Date(const Date& d);
	//��������
	~Date();
	//��ֵ���������
	Date& operator=(const Date& d);
	//����4����Ĭ�ϵ�4����Ա����

	//d += 10
	Date& operator+=(int day);
	//d + 10
	Date operator+(int day);
	//d -= 10
	Date& operator-=(int day);
	//d - 10
	Date operator-(int day);
	//++d
	Date& operator++();
	//d++
	Date operator++(int);
	//--d
	Date& operator--();
	//d--
	Date operator--(int);
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator>=(const Date& d);
	// <���������
	bool operator<(const Date& d);
	// <=���������
	bool operator<=(const Date& d);
	// !=���������
	bool operator!=(const Date& d);

	// ����-����
	int operator-(const Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};