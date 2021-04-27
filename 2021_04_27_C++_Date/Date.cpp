#include "Date.h"


Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year > 0 &&
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month)))
	{
		cout << "���ڷǷ�" << endl;
	}
}
void Date::Print(){
	cout << _year <<"-"<< _month<<"-" << _day << endl;
}
int Date::GetMonthDay(int year, int month)
{
	static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = daysArray[month];
	if (
		month == 2 
		&&
		((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		)
	{
		days = 29;
	}
	return days;
}
Date::Date(const Date& d){
	//(Date* this,const Date& d)
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}
Date::~Date(){
	//cout << "��������" << endl;
}
Date& Date::operator=(const Date& d){
	if (this != &d){
		_year  = d._year;
		_month = d._month;
		_day   = d._day;
	}
	return *this;
}
//d += 10
Date& Date::operator+=(int day){
	if (day < 0){
		return *this -= -day;
	}
	
	_day += day;
	while (_day > GetMonthDay(_year, _month)){
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13){
			_year++;
			_month = 1;
		}
	}
	return *this;
}
//d + 10
Date Date::operator+(int day){
	Date ret(*this);
	//�ÿ������캯����һ��ret,�����������ӷ�
	ret += day;
	return ret;//���ؾֲ����������԰ѷ������Ͷ�Ϊ����Ŷ
}
//d -= 10
Date& Date::operator-=(int day){
	if (day < 0){
		
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0){
		_month--;
		
		if (_month == 0){
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
//d - 10
Date Date:: operator-(int day){
	Date ret(*this);
	ret -= day;
	return ret;
}

//++d
Date& Date::operator++(){
	*this += 1;
	return *this;
}
//d++
Date Date:: operator++(int){
	Date ret(*this);
	*this += 1;
	return ret;
}

//--d
Date& Date:: operator--(){
	*this -= 1;
	return *this;
}
//d--
Date Date:: operator--(int){
	Date ret(*this);
	*this -= 1;
	return ret;

}
bool Date::operator>(const Date& d){
	if (_year > d._year){
		return true;
	}
	else if (_year == d._year){
		if (_month > d._month){
			return true;
		}
		else if (_month == d._month){
			if (_day > d._day){
				return true;
			}
		}
	}
	return false;
}
bool Date :: operator==(const Date& d){
	return _year == d._year && _month == d._month && _day == d._day;
}
// !=���������
bool Date :: operator!=(const Date& d){
	return !(*this==d);
}
// >=���������
bool Date:: operator>=(const Date& d){
	return *this > d || *this == d;
}
// < ���������
bool Date:: operator<(const Date& d){
	return !(*this >= d);
}
bool Date :: operator<=(const Date& d){
	return !(*this > d);
}


// ����-���� �ǳ������˼·����������ĺ���
int Date:: operator-(const Date& d){
	//*this �� d �Ƚ�
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d){
		max = d;
		min = *this;
		int flag = -1;
	}
	int n = 0;
	while (min != max){
		n++;
		min++;
	}
	return n;
}