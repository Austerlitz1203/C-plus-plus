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

	bool Date::operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool Date::operator!=(const Date& d)
	{
		return !(*this == d);
	}

	bool Date::operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && (_month = d._month) && _day < d._day)
			return true;
		return false;

	}

	bool Date::operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool Date::operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool Date::operator>=(const Date& d)
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



	void Date::Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}

// d1+=d2+=d3����������Ȼ�ǲ��еģ���Ϊ d2+=d3 ���ص���һ���������ڣ�������int ���͵�
// ���ǣ�Ҫ֧�� d1 = d2 += 100 ��Ҫ֧��������ֵ
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 13)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

// + ���� += �ȽϺã��������Լ��ٿ�������
// ��Ϊ + ������ζ���Ҫ��������ģ���� += ����+ ����ô+= ҲҪ��������
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

// ���ú���++ ��ʱ�򣬱������Զ���һ�� int ���͵Ĳ���
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}