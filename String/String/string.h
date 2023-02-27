#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<algorithm>



// ģ��ʵ��String��
namespace simulate
{
	class string
	{
	public:

		// string(const char* s = nullptr) �ǲ����Եģ����� '\0' Ҳ�����ԡ���Ϊcout����char*���͵ģ���һֱ���� \0 Ϊֹ
		string(const char* s = "")
			:_size(strlen(s))    // ���ͬʱ��ʼ��_capacity���ᵼ�°���������˳���ʼ����˳��Ķ���������ֵ
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
				//delete[] _str;   // ����д�����ã����ܻ�newʧ��
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