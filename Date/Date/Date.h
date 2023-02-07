#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

class Date
{
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out,const Date& d);

public:
	int GetMonthDay(int year, int month);
	Date(int year = 2023, int month = 2, int day = 3);
	//Date(const Date& d);
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	Date& operator=(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator++();    // ǰ��++
	Date operator++(int);  // ����++ ��int ����ֻ�Ǻ�ǰ��++ ����
	Date& operator-=(int day);
	Date operator-(int day);
	int operator-(const Date& d)const;
	void operator<<(ostream& out);


	void Print()const;


private:
	int _year;
	int _month;
	int _day;
};

//istream& operator>>(istream& in, Date& d);
//ostream& operator<<(ostream& out, const Date& d);


// ʹ����������
inline ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}