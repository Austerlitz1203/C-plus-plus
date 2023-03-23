#include<iostream>
#include<array>
#include <vector>
using namespace std;

//#define N 20
//类型模板参数
//非类型模板参数 -- 整形常量
template<class T, int N = 20>
class Array
{
public:

private:
	T _a[N];
};

//template<class T, double N = 20.2>
//template<class T, int N = 20.2>  // 只能是整形，否则会出错
//void func1(const T& a)
//{
//	//N = 10;
//}

template<class T, bool flag = true>
void func2(const T& a)
{
	//N = 10;
}

//int main()
//{
//	//Array<int> a0;		    
//	//Array<int, 10> a1;		
//	//Array<double, 20> a2;	
//	//func1(1);
//	//func2(1);
//
//	int arr[10];
//	array<int, 10> a1;
//	a1[5]++;
//
//	// 数组是 抽查 越界写
//	arr[10];
//	//arr[10] = 1;
//	arr[15] = 1;
//
//	// array，读写全面检查
//	//a1[10];
//	//a1[15] = 1;
//
//	// 但是可以直接用 vector，array略显多余
//	vector<int> v(10, 0);
//	//v[10];
//
//	return 0;
//}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};


// 函数模板 -- 参数匹配
template<class T>
bool Less(T left, T right)
{
	return left < right;
}

// 模板特化 -- 某些类型特殊化处理
// 全特化
template<>
bool Less<Date*>(Date* left, Date* right)
{
	return *left < *right;
}

// 偏特化——参数进一步的限制
template<class T>
bool Less(T* left, T* right)
{
	return *left < *right;
}

// 这是重载
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}


//int main()
//{
//	cout << Less(1, 2) << endl;   
//
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; 
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl;  
//
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less(p3, p4) << endl;  
//
//	return 0;
//}



template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

template<>
class Data<int*, char*>
{
public:
	Data() { cout << "Data<int*, char*>" << endl; }
private:
	int _d1;
	char _d2;
};

// 偏特化
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1 = T1(), const T2& d2 = T2())
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}

private:
	const T1& _d1;
	const T2& _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2*>
{
public:
	Data(const T1& d1 = T1())

	{
		cout << "Data<T1&, T2*>" << endl;
	}
};



//int main()
//{
//	Data<int, int> d1;
//	Data<int*, char*> d2;
//	Data<int*, int> d3;
//	Data<double, int> d4;
//
//	Data<int*, int*> d5;
//
//	Data<int&, char&> d6;
//	Data<int&, char*> d7;
//
//	return 0;
//}




// 模板不可以分离编译

#include "Func.h"
//template<class T>
//T Add(const T& left, const T& right);
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}

void func();

int main()
{
	Add(1, 2);
	Add(1.0, 2.0); // call func(0xdadada)

	func(); // call func(?)

	return 0;
}
