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

int main()
{
	PerfectForward(10);           // 右值

	int a;
	PerfectForward(a);            // 左值
	PerfectForward(std::move(a)); // 右值

	const int b = 8;
	PerfectForward(b);		      // const 左值
	PerfectForward(std::move(b)); // const 右值

	int&& rr1 = 10;
	cout << &rr1 << endl;
	rr1++;

	/*string s1("hello world");
	string s2("hello world");
	string s3 = s1 + s2;*/



	simulate::list<simulate::string> lt;
	
	simulate::string s1("hello world");
	lt.push_back(s1);
	
	lt.push_back(simulate::string("hello world"));
	lt.push_back("hello world");


	return 0;
}
