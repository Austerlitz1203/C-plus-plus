#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
using namespace std;



//class Stack
//{
//public:
//	Stack(int size=4)
//	{
//		int* tmp = (int*)malloc(sizeof(int)*size);
//		if (!tmp)
//		{
//			perror("malloc fail::");
//			exit(-1);
//		}
//		_a = tmp;
//		_size = 0;
//		_capacity = 4;
//	}
//
//	// Ҫ�¿��ٿռ䣬����ǰ��ֽڵ�ǳ��������ô����ǰ��Ķ���a��b ���ָ��ָ�����ͬһ��ռ�
//	// ���ȣ�bѹջ����ջ ��Ӱ�� a  �� ��Σ����ε��������������ظ�free ͬһ��ռ䣬����
//	Stack(const Stack& st)
//	{
//		int* tmp = (int*)malloc(sizeof(int) * st._capacity);
//		if (tmp == nullptr)
//		{
//			perror("mallocfail::");
//			exit(-1);
//		}
//		_a = tmp;
//		memcpy(_a, st._a, sizeof(int) * st._size);
//		_size = st._size;
//		_capacity = st._capacity;
//	}
//
//
//	~Stack()
//	{
//		if(_a) free(_a);
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//
//
//
//class Date
//{
//public:
//
//	Date(int year = 2023, int month = 2, int day = 3)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Stack s;  // �Զ������ͣ����������ʱ����Ҫ����Stack �Ŀ�������
//};
//
//
//int main()
//{
//	// �������� �� ��ֵ����  ������Ĭ�����ɵĿ�����ɣ�
//	// 1. �����������ͣ���ɰ��ֽڵ�ֵ������
//	// 2. �����Զ������ͣ��������� �������� �� ��ֵ����
//
//	Date d1(2002,12,3);
//	Date d2 = d1; 
//
//
//	return 0;
//}






class Date
{
public:

	Date(int year = 2023, int month = 2, int day = 3)
	{
		_year = year;
		_month = month;
		_day = day;
	}


	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && (_month = d._month) && _day<d._day)
			return true;
		return false;

	}

	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	// ����д����ʵ�� d1=d2 ��������� d1=d2=d3 �أ�����Ҫ���÷���ֵ�� ʵ���ϣ� d2=d3�᷵��һ��ֵ
	//void operator=(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	// �������ֵ��Date ���ͣ���ô��Ҫ����һ�£����鷳����������
	Date& operator=(const Date& d)
	{
		// d1=d1 ������Ҫ��������������������������⣬���Թ�������
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}



	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}



private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2023, 2, 3);
	Date d2;
	Date d3 = d1; // �������죬��Ϊ d3 ��û�п��ٿռ䣬���������������пռ�Ķ���֮����е�
	d2 = d1;      // ��ֵ���أ�Ҫ��ѭ����˳�򣬷��򷴹�����
	d1.Print();
	d2.Print();
	d3.Print();

	return 0;
}