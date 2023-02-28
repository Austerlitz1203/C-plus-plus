#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<algorithm>
#include<assert.h>



// ģ��ʵ��String��
namespace simulate
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;


		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// string(const char* s = nullptr) �ǲ����Եģ����� '\0' Ҳ�����ԡ���Ϊcout����char*���͵ģ���һֱ���� \0 Ϊֹ
		string(const char* s = "")
			:_size(strlen(s))    // ���ͬʱ��ʼ��_capacity���ᵼ�°���������˳���ʼ����˳��Ķ���������ֵ
		{
			_capacity = _size == 0 ? 3 : _size + 1;
			_str = new char[_capacity+1];
			strcpy(_str, s);
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
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

				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity + 1;
			}
			return *this;
		}

		char* getstr()const
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		int size()const
		{
			return _size;
		}

		bool operator>(const string& s)const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s)const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s)const
		{
			return (*this > s) || (s == *this); // �������Ϊconst�������ᱨ����Ϊ s ���� == ����̬��Ա���÷Ǿ�̬��Ա����
		}

		bool operator<(const string& s)const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}

		void reserve(int n) // ���ݣ����ı�����
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void pushback(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(_capacity*2);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);  // ���ʹ��strcat�����������Ҫ�Լ�ȥ�� \0 ,�Ƚ��˷�ʱ��
			_size += len;
		}

		string& operator+=(const char ch)
		{
			pushback(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(int pos, const char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(_capacity * 2);
			}
			size_t end = _size;
			for (int i = end - 1; i >= pos; i--)
			{
				_str[i + 1] = _str[i];
			}
			_str[pos] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void insert(int pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size;
			for (int i = end - 1; i >= pos; i--) // ����
			{
				_str[i + len] = _str[i];
			}

			const char* tmp = str;
			for (int i = pos; i < pos+len; i++) // ����
			{
				_str[i] = *str++;
			}
			_size += len;
			_str[_size] = '\0';

		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size && npos > 0);
			for (int i = pos; i + len < _size; i++)
			{
				_str[i] = _str[i + len];
			}
			_size -= len;
			_str[_size] = '\0';
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

	private:
		char* _str;
		int _size;      // Ŀǰ�ĳ��ȣ������� \0
		int _capacity;  // ������������������һ�� \0

		static size_t npos; // ��������ȱʡֵ����ʼ���б�ʹ�ã�����Ϊstatic���Σ���ȫ�ֱ���

		//static const size_t npos1 = -1;  // ���������ӾͿ��ԣ�ֻ��������Ч��������������Ҫע�⡣
		//static const double npos2 = 1.9; // �����ԣ���Ϊ��������
	};

	size_t string::npos = -1;

}