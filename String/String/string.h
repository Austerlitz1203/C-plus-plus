#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<algorithm>



// 模拟实现String类
namespace simulate
{
	class string
	{
	public:

		// string(const char* s = nullptr) 是不可以的，传参 '\0' 也不可以。因为cout对于char*类型的，是一直读到 \0 为止
		string(const char* s = "")
			:_size(strlen(s))    // 如果同时初始化_capacity，会导致按照申明的顺序初始化，顺序改动会造成随机值
		{
			_str = new char[_size + 1];
			_capacity = _size + 1;
			strcpy(_str, s);
		}

		string(const string& s)
			:_size(s._size)    
			,_capacity(s._capacity)
		{
			_str = new char[_capacity+1];
			strcpy(s._str, _str);
		}

		string operator=(const string& s)
		{
			if (_str != s._str)
			{
				//delete[] _str;   // 这样写并不好，可能会new失败
				//_str = new char[s._capacity];
				//_size = s._size;
				//_capacity = s._capacity + 1;

				char* tmp = new char[s._capacity+1];
				strcpy(tmp, s._str);
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity + 1;
			}
			return *this;
		}

		char* getstr()
		{
			return _str;
		}

	private:
		char* _str;
		int _size;
		int _capacity;
	};

}