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
//	// 要新开辟空间，如果是按字节的浅拷贝，那么拷贝前后的对象a、b 里的指针指向的是同一块空间
//	// 首先，b压栈、出栈 会影响 a  ； 其次，两次调用析构函数，重复free 同一块空间，崩溃
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
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Stack s;  // 自定义类型，拷贝构造的时候需要调用Stack 的拷贝构造
//};
//
//
//int main()
//{
//	// 拷贝构造 和 赋值重载  编译器默认生成的可以完成：
//	// 1. 对于内置类型，完成按字节的值拷贝。
//	// 2. 对于自定义类型，调用它的 拷贝构造 和 赋值重载
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

	// 这样写可以实现 d1=d2 ，但是如果 d1=d2=d3 呢？所以要设置返回值， 实际上， d2=d3会返回一个值
	//void operator=(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	// 如果返回值是Date 类型，那么就要拷贝一下，很麻烦，所以引用
	Date& operator=(const Date& d)
	{
		// d1=d1 ，不需要拷贝，而且如果是深拷贝，会出问题，所以过滤这种
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
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
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
	Date d3 = d1; // 拷贝构造，因为 d3 并没有开辟空间，复制重载是两个有空间的对象之间进行的
	d2 = d1;      // 赋值重载，要遵循左右顺序，否则反过来了
	d1.Print();
	d2.Print();
	d3.Print();

	return 0;
}