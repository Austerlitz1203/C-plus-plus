#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<assert.h>
#include<algorithm>
#include<thread>

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
//int main()
//{
//	// 深拷贝的类
//	std::list<simulate::string> mylist;
//	// 没区别
//	/*bit::string s1("1111");
//	mylist.push_back(s1);
//	mylist.emplace_back(s1);
//
//	cout << endl;
//	bit::string s2("2222");
//	mylist.push_back(move(s1));
//	mylist.emplace_back(move(s2));*/
//
//	// 开始有区别
//	//cout << endl;
//	//mylist.push_back("3333");   // 构造匿名对象 + 移动构造
//	//mylist.emplace_back("3333");// 直接构造
//
//	// 浅拷贝的类
//	// 没区别
//	std::list<Date> list2;
//	Date d1(2023, 5, 28);
//	list2.push_back(d1);
//	list2.emplace_back(d1);
//
//	cout << endl;
//	Date d2(2023, 5, 28);
//	list2.push_back(move(d1));
//	list2.emplace_back(move(d2));
//
//	// 有区别
//	cout << "=========================" << endl;
//	list2.push_back(Date(2023, 5, 28));
//	list2.push_back({ 2023, 5, 28 });
//
//	cout << endl;
//	list2.emplace_back(Date(2023, 5, 28)); // 构造+移动构造
//	list2.emplace_back(2023, 5, 28);       // 直接构造
//
//
//	return 0;
//}




struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};



//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	for (auto &a : v)
//	{
//		cout << a._name <<":"<<a._price << endl;
//	}
//	cout << "---------------------------" << endl;
//
//	// <
//	sort(v.begin(), v.end(), ComparePriceLess());
//
//	for (auto& a : v)
//	{
//		cout << a._name << ":" << a._price << endl;
//	}
//
//	cout << "---------------------------" << endl;
//	// >
//	sort(v.begin(), v.end(), ComparePriceGreater());
//
//	for (auto& a : v)
//	{
//		cout << a._name << ":" << a._price << endl;
//	}
//
//
//
//	// lambda 表达式
//	auto add1 = [](int x, int y)->int {return x + y; };
//
//	//cout << [](int x, int y)->int {return x + y; }(1, 2) << endl;
//	cout << add1(1, 2) << endl;
//
//	auto add2 = [](int x, int y) 
//	{
//		return x + y;
//	};
//
//	cout << add2(1, 2) << endl;
//
//
//	return 0;
//}




//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//
//	auto priceLess = [](const Goods& g1, const Goods& g2)->bool {return g1._price < g2._price; };
//	sort(v.begin(), v.end(), priceLess);
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {
//		return g1._price > g2._price; 
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {
//		return g1._evaluate < g2._evaluate;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {
//		return g1._evaluate > g2._evaluate;
//		});
//}




//int main()
//{
//	int x = 0, y = 1;
//	int m = 0, n = 1;
//
//	auto swap1 = [](int& rx, int& ry)
//	{
//		int tmp = rx;
//		rx = ry;
//		ry = tmp;
//	};
//
//	swap1(x, y);
//	cout << x << " "<< y << endl;
//
//	// 传值捕捉
//	/*auto swap2 = [x, y]() mutable 
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap2();
//	cout << x << " " << y << endl;*/
//
//	// 引用捕捉
//	auto swap2 = [&x, &y]()
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap2();
//	cout << x << " " << y << endl;
//
//	// 混合捕捉
//	auto func1 = [&x, y]()
//	{
//		//...
//	};
//
//	// 全部引用捕捉
//	auto func2 = [&]()
//	{
//		//...
//	};
//
//	// 全部传值捕捉
//	auto func3 = [=]()
//	{
//		//...
//	};
//
//	// 全部引用捕捉，x传值捕捉
//	auto func4 = [&, x]()
//	{
//		//...
//	};
//
//	return 0;
//}







void Func(int n, int num)
{
	for (int i = 0; i < n; i++)
	{
		cout <<num<<":" << i << endl;
	}
	cout << endl;
}

//int main()
//{
//	int n1, n2;
//	cin >> n1>>n2;
//	thread t1(Func, n1, 1);
//	thread t2(Func, n2, 2);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}


//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	thread t1([n1](int num)
//		{
//			for (int i = 0; i < n1; i++)
//			{
//				cout <<num<<":" << i << endl;
//			}
//			cout << endl;
//		}, 1);
//
//	thread t2([n2](int num)
//		{
//			for (int i = 0; i < n2; i++)
//			{
//				cout << num << ":" << i << endl;
//			}
//			cout << endl;
//		}, 2);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}




//int main()
//{
//	size_t m;
//	cin >> m;
//	vector<thread> vthds(m);
//
//	// 要求m个线程分别打印n
//	for (size_t i = 0; i < m; i++)
//	{
//		size_t n;
//		cin >> n;
//
//		vthds[i] = thread([i, n, m]() {
//			for (int j = 0; j < n; j++)
//			{
//				cout << i << ":" << j << endl;
//			}
//			cout << endl;
//			});
//	}
//
//	for (auto& t : vthds)
//	{
//		t.join();
//	}
//
//	return 0;
//}






class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};



//int main()
//{
//	/*int x = 0, y = 1;
//	int m = 0, n = 1;
//
//	auto swap1 = [](int& rx, int& ry)
//	{
//		int tmp = rx;
//		rx = ry;
//		ry = tmp;
//	};
//
//	cout << sizeof(swap1) << endl;*/
//
//	// 函数对象
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// lambda
//	auto r2 = [=](double money, int year)->double {return money * rate * year; };
//	r2(10000, 2);
//
//	auto f1 = [] {cout << "hello world" << endl; };
//	auto f2 = [] {cout << "hello world" << endl; };
//
//	//f1 = f2;
//
//	return 0;
//}





int main()
{
	size_t m;
	cin >> m;
	vector<thread> vthds(m);

	// 要求m个线程分别打印n次
	for (size_t i = 0; i < m; i++)
	{
		size_t n = 10;
		vthds[i] = thread([n, m]() {
			for (int j = 0; j < n; j++)
			{
				cout << this_thread::get_id() << ":" << j << endl;

				this_thread::sleep_for(chrono::milliseconds(200));
			}
			cout << endl;

			});

		//cout << vthds[i].get_id() << endl;
	}

	for (auto& t : vthds)
	{
		t.join();
	}

	int i = 0;
	//i += 1;

	// 原子
	/*int old = i;
	while (!__sync_bool_compare_and_swap(&i, old, old+1))
	{
		old = i;
	}*/

	return 0;
}