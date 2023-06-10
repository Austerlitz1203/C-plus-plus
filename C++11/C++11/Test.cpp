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
//	// 左值引用给左值取别名
//	int& ref1 = a;
//
//	// 左值引用给右值取别名
//	// int& ref2 = (a + b);
//	const int& ref2 = (a + b);
//
//	// 右值引用给右值取别名
//	int&& ref3 = (a + b);
//
//	// 右值引用给move后左值取别名
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

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// 移动构造
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;
			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
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




// 左值引用：直接减少拷贝。1、左值引用传参  2、传引用返回。（函数内的局部对象，不能用引用返回）
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



void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

// 万能引用(引用折叠)：既可以引用左值，也可以引用右值
template<typename T>
void PerfectForward(T&& t)
{
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
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
//	// 强制生成移动构造和移动赋值
//	Person(Person&& p) = default;
//	Person& operator=(Person&& p) = default;
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//private:
//	simulate::string _name; // 自定义类型
//	int _age = 1;		   // 内置类型
//};
//
//int main()
//{
//	Person s1("张三", 18);
//	Person s2 = s1;
//	Person s3 = std::move(s1);  // 自定义类型，调用给自己的移动构造
//	cout << endl << endl;
//	Person s4;
//	s4 = std::move(s2);  // 移动赋值，默认生成的调用自定义类型的移动赋值（由于 string 未实现，所以调用赋值重载）
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

	// 一个构造函数可以复用其他构造函数
	Person(const char* name)
		:Person(name, 18) // 委托构造
	{}

private:
	simulate::string _name; // 自定义类型
	int _age = 1;		   // 内置类型
};



//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// 如何解析出可变参数包呢？
//	// 不能这么做，语法不支持
//	//for (int i = 0; i < sizeof...(args); i++)
//	//{
//	//	cout << args[i] << " ";
//	//}
//	cout << endl;
//}

//int main()
//{
//	Person s1("张三");
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
//// 编译器编译推演生成了一下代码
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

// STL容器的插入接口都有一个emplace系列
int main()
{
	// 深拷贝的类
	std::list<simulate::string> mylist;
	// 没区别
	/*bit::string s1("1111");
	mylist.push_back(s1);
	mylist.emplace_back(s1);

	cout << endl;
	bit::string s2("2222");
	mylist.push_back(move(s1));
	mylist.emplace_back(move(s2));*/

	// 开始有区别
	//cout << endl;
	//mylist.push_back("3333");   // 构造匿名对象 + 移动构造
	//mylist.emplace_back("3333");// 直接构造

	// 浅拷贝的类
	// 没区别
	std::list<Date> list2;
	Date d1(2023, 5, 28);
	list2.push_back(d1);
	list2.emplace_back(d1);

	cout << endl;
	Date d2(2023, 5, 28);
	list2.push_back(move(d1));
	list2.emplace_back(move(d2));

	// 有区别
	cout << "=========================" << endl;
	list2.push_back(Date(2023, 5, 28));
	list2.push_back({ 2023, 5, 28 });

	cout << endl;
	list2.emplace_back(Date(2023, 5, 28)); // 构造+移动构造
	list2.emplace_back(2023, 5, 28);       // 直接构造


	return 0;
}