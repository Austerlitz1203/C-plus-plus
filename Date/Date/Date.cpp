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
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}

// d1+=d2+=d3����������Ȼ�ǲ��еģ���Ϊ d2+=d3 ���ص���һ���������ڣ�������int ���͵�
// ���ǣ�Ҫ֧�� d1 = d2 += 100 ��Ҫ֧��������ֵ
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
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}


// ȫ�� , �����޷����� Date ����� private ��Ա����
// �����취�� 1. ���ó�public ������ȡ��   2. ��Ԫ�࣬���ԡ�
//ostream& operator<<(ostream& out, const Date& d)
//{
//	cout<< d._year << "��" << d._month << "��" << d._day << "��" << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}