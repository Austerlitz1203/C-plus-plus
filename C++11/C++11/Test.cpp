#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<assert.h>

using namespace std;



//int main()
//{
//	int a = 0;
//	int b = 1;
//	int* p = &a;
//
//	a + b;
//
//	// ��ֵ���ø���ֵȡ����
//	int& ref1 = a;
//
//	// ��ֵ���ø���ֵȡ����
//	// int& ref2 = (a + b);
//	const int& ref2 = (a + b);
//
//	// ��ֵ���ø���ֵȡ����
//	int&& ref3 = (a + b);
//
//	// ��ֵ���ø�move����ֵȡ����
//	//int&& ref4 = a;
//	int&& ref4 = move(a);
//
//	return 0;
//}




void func(int& a)
{
	cout << "void func(int& a)" << endl;
}

void func(int&& a)
{
	cout << "void func(int&& a)" << endl;
}

//int main()
//{
//	int a = 0;
//	int b = 1;
//	func(a);
//	func(a + b);
//}



namespace simulate
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string operator+(char ch)
		{
			string tmp(*this);
			tmp += ch;
			return tmp;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};

	simulate::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		simulate::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}



//int main()
//{
//	simulate::string s1("hello world");
//
//	simulate::string ret1 = s1;
//	simulate::string ret2 = (s1+'!');
//
//	simulate::string ret3 = move(s1);
//
//	return 0;
//}




// ��ֵ���ã�ֱ�Ӽ��ٿ�����1����ֵ���ô���  2�������÷��ء��������ڵľֲ����󣬲��������÷��أ�
#include"List.h"
//int main()
//{
//	simulate::list<simulate::string> lt;
//
//	/*simulate::string s1("hello world");
//	lt.push_back(s1);
//	lt.push_back(move(s1));*/
//
//	lt.push_back(simulate::string("hello world"));
//	lt.push_back("hello world");
//
//	return 0;
//}



void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

// ��������(�����۵�)���ȿ���������ֵ��Ҳ����������ֵ
template<typename T>
void PerfectForward(T&& t)
{
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);		      // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	int&& rr1 = 10;
//	cout << &rr1 << endl;
//	rr1++;
//
//	/*string s1("hello world");
//	string s2("hello world");
//	string s3 = s1 + s2;*/
//
//
//
//	simulate::list<simulate::string> lt;
//	
//	simulate::string s1("hello world");
//	lt.push_back(s1);
//	
//	lt.push_back(simulate::string("hello world"));
//	lt.push_back("hello world");
//
//
//	return 0;
//}





//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	Person(const Person& p)
//		:_name(p._name)
//		,_age(p._age)
//	{}
//
//	Person& operator=(const Person& p)
//	{
//		if(this != &p)
//		{
//			_name = p._name;
//			_age = p._age;
//		}
//		return *this;
//	}
//
//	// ǿ�������ƶ�������ƶ���ֵ
//	Person(Person&& p) = default;
//	Person& operator=(Person&& p) = default;
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//private:
//	simulate::string _name; // �Զ�������
//	int _age = 1;		   // ��������
//};
//
//int main()
//{
//	Person s1("����", 18);
//	Person s2 = s1;
//	Person s3 = std::move(s1);  // �Զ������ͣ����ø��Լ����ƶ�����
//	cout << endl << endl;
//	Person s4;
//	s4 = std::move(s2);  // �ƶ���ֵ��Ĭ�����ɵĵ����Զ������͵��ƶ���ֵ������ string δʵ�֣����Ե��ø�ֵ���أ�
//
//	return 0;
//}






class Person
{
public:
	Person(const char* name, int age)
		:_name(name)
		, _age(age)
	{}

	// һ�����캯�����Ը����������캯��
	Person(const char* name)
		:Person(name, 18) // ί�й���
	{}

private:
	simulate::string _name; // �Զ�������
	int _age = 1;		   // ��������
};



//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// ��ν������ɱ�������أ�
//	// ������ô�����﷨��֧��
//	//for (int i = 0; i < sizeof...(args); i++)
//	//{
//	//	cout << args[i] << " ";
//	//}
//	cout << endl;
//}

//int main()
//{
//	Person s1("����");
//
//	ShowList();
//	ShowList('x');
//	ShowList('x', 'y');
//	ShowList('x', 1);
//
//	return 0;
//}






//template <class T, class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	cout << __FUNCTION__ << "(" << sizeof...(args) <<")" << endl;
//
//	//cout << val << " ";
//	ShowList(args...);
//}
//
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}









//template <class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//
//	return 0;
//}
//
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}
//
//// ��������������������һ�´���
////void ShowList(char a1, char a2, std::string a3)
////{
////	int arr[] = { PrintArg(a1),PrintArg(a2),PrintArg(a3) };
////	cout << endl;
////}
//
//int main()
//{
//	ShowList(1, 'A', std::string("sort"));
//
//	//ShowList(1, 2, 3);
//	//ShowList(1);
//
//	return 0;
//}




#include "Date.h"

// STL�����Ĳ���ӿڶ���һ��emplaceϵ��
int main()
{
	// �������
	std::list<simulate::string> mylist;
	// û����
	/*bit::string s1("1111");
	mylist.push_back(s1);
	mylist.emplace_back(s1);

	cout << endl;
	bit::string s2("2222");
	mylist.push_back(move(s1));
	mylist.emplace_back(move(s2));*/

	// ��ʼ������
	//cout << endl;
	//mylist.push_back("3333");   // ������������ + �ƶ�����
	//mylist.emplace_back("3333");// ֱ�ӹ���

	// ǳ��������
	// û����
	std::list<Date> list2;
	Date d1(2023, 5, 28);
	list2.push_back(d1);
	list2.emplace_back(d1);

	cout << endl;
	Date d2(2023, 5, 28);
	list2.push_back(move(d1));
	list2.emplace_back(move(d2));

	// ������
	cout << "=========================" << endl;
	list2.push_back(Date(2023, 5, 28));
	list2.push_back({ 2023, 5, 28 });

	cout << endl;
	list2.emplace_back(Date(2023, 5, 28)); // ����+�ƶ�����
	list2.emplace_back(2023, 5, 28);       // ֱ�ӹ���


	return 0;
}