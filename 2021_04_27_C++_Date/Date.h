#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class Date{
public:
	
	void Print();
	int GetMonthDay(int year,int month);
	//默认构造(全缺省)
	Date(int year = 1996, int month = 11, int day = 1);
	//拷贝构造
	Date(const Date& d);
	//析构函数
	~Date();
	//赋值运算符重载
	Date& operator=(const Date& d);
	//以上4个是默认的4个成员函数

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
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator>=(const Date& d);
	// <运算符重载
	bool operator<(const Date& d);
	// <=运算符重载
	bool operator<=(const Date& d);
	// !=运算符重载
	bool operator!=(const Date& d);

	// 日期-日期
	int operator-(const Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};