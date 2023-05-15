#include"HashTable.h"
#include"UnorderedMap.h"
#include"UnorderedSet.h"

void unordered_set_test1()
{
	simulate_unorderedset::unordered_set<int> s;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		s.insert(rand() + i);
	}

	for (auto a : s)
	{
		cout << a << " ";
	}
	cout << endl<<endl;

	simulate_unorderedset::unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 100;
		cout << *it <<endl;
		++it;
	}

	cout << endl << endl;

	simulate_unorderedset::unordered_set<int>::const_iterator it1 = s.begin();
	while (it1 != s.end())
	{
		//*it1 = 100;
		cout << *it1 << " ";
		++it1;
	}

	cout << endl << endl;

	simulate_unorderedset::unordered_set<int>::const_iterator it2 = s.begin();
	int cnt = 90;
	while (cnt--)
	{
		++it2;
	}

	cnt = 90;
	while (cnt--)
	{
		--it2;
	}
	
	while (it2 != s.end())
	{
		cout << *it2 << endl;
		++it2;
	}
	cout << endl << endl;

	simulate_unorderedset::unordered_set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << (*rit) << " ";
		++rit;
	}

	cout << endl << endl;


}


void unordered_map_test1()
{
	simulate_unorderedmap::unordered_map<int,int> m;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		m.insert(make_pair(rand()+i,rand()));
	}

	for (auto& a : m)
	{
		cout << a.first << ":" << a.second << endl;
	}


}


void unordered_map_test2()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶", "Àæ" };
	simulate_unorderedmap::unordered_map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	simulate_unorderedmap::unordered_map<string, int>::iterator it = countMap.begin();
	while (it != countMap.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}


	simulate_unorderedmap::unordered_map<string, int>::const_iterator it1 = countMap.begin();
	while (it1 != countMap.end())
	{
		cout << (*it1).first << ":" << (*it1).second << endl;
		++it1;
	}
}



class Date
{
	friend struct HashDate;
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

	bool operator==(const Date& d) const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

struct HashDate
{
	size_t operator()(const Date& d)
	{
		size_t hash = 0;
		hash += d._year;
		hash *= 31;

		hash += d._month;
		hash *= 31;

		hash += d._day;
		hash *= 31;

		return hash;
	}
};


void unordered_map_test3()
{
	Date d1(2023, 3, 13);
	Date d2(2023, 3, 13);
	Date d3(2023, 3, 12);
	Date d4(2023, 3, 11);
	Date d5(2023, 3, 12);
	Date d6(2023, 3, 13);

	Date a[] = { d1, d2, d3, d4, d5, d6 };

	simulate_unorderedmap::unordered_map<Date, int, HashDate> countMap;
	for (auto e : a)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

int main()
{
	unordered_set_test1();

	//unordered_map_test1();

	//unordered_map_test2();

	//unordered_map_test3();
	return 0;
}