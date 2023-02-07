#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

	Date::Date(int year,int month, int day)
	{
		assert(month > 0 && month < 13);
		_year = year;
		_month = month;
		_day = day;

	}


	//Date::Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	bool Date::operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool Date::operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	bool Date::operator<(const Date& d)const
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && (_month == d._month) && _day < d._day)
			return true;
     	return false;
	}

	bool Date::operator<=(const Date& d)const
	{
		return *this < d || *this == d;
	}

	bool Date::operator>(const Date& d)const
	{
		return !(*this <= d);
	}

	bool Date::operator>=(const Date& d)const
	{
		return !(*this < d);
	}

	Date& Date::operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}



	void Date::Print()const
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}

// d1+=d2+=d3，这样子显然是不行的，因为 d2+=d3 返回的是一个具体日期，而不是int 类型的
// 但是，要支持 d1 = d2 += 100 ，要支持连续赋值
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

// + 复用 += 比较好，这样可以减少拷贝构造
// 因为 + 无论如何都是要拷贝构造的，如果 += 复用+ ，那么+= 也要拷贝构造
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}


Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 调用后置++ 的时候，编译器自动传一个 int 类型的参数
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month -= 1;
		if (_month == 0)
		{
			_year -= 1;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

int Date::operator-(const Date& d)const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int ret = 0;
	while (max != min)
	{
		++min;
		++ret;
	}
	return ret*flag;

}

void Date::operator<<(ostream& out)
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}


// 全局 , 但是无法访问 Date 里面的 private 成员变量
// 两个办法： 1. 设置成public ，不可取。   2. 友元类，可以。
//ostream& operator<<(ostream& out, const Date& d)
//{
//	cout<< d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}