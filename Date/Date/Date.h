#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	Date(int year = 2023, int month = 2, int day = 3);
	//Date(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	Date& operator=(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator++();    // 前置++
	Date operator++(int);  // 后置++ ，int 参数只是和前置++ 区分

	void Print();


private:
	int _year;
	int _month;
	int _day;
};