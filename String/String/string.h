#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<algorithm>
#include<assert.h>



// 模拟实现String类
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

		// string(const char* s = nullptr) 是不可以的，传参 '\0' 也不可以。因为cout对于char*类型的，是一直读到 \0 为止
		string(const char* s = "")
			:_size(strlen(s))    // 如果同时初始化_capacity，会导致按照申明的顺序初始化，顺序改动会造成随机值
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
				//delete[] _str;   // 这样写并不好，可能会new失败
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

		char* c_str()const
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
			return (*this > s) || (s == *this); // 如果不设为const，这样会报错，因为 s 调用 == ，静态成员调用非静态成员函数
		}

		bool operator<(const string& s)const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}

		void resize(size_t n,char ch='\0')
		{
			// 删除数据，保留前n个
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else if (n > _size)  // 不用考虑 n = _size 的情况，因为这种情况不需要改变任何值
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				size_t i = _size;
				while (i < n)
				{
					_str[i] = ch;
					i++;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void reserve(size_t n) // 扩容，不改变数据
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
			strcpy(_str + _size, str);  // 如果使用strcat，这个函数需要自己去找 \0 ,比较浪费时间
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

		string& insert(size_t pos, const char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(_capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size+len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);
			// 要删除的内容大于等于pos之后的长度
			if (len == npos || pos + len >= _size) // 要判断 len == npos ，否则如果 pos+len 溢出就麻烦了
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else  // 要删除的内容没有超过最后一个字符
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(const char ch,size_t pos=0)
		{
			assert(pos <= _size);
			for (int i = pos; i < _size; i++)
			{
				if (_str[ch] = i) return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			char* p = strstr(_str, str);
			if (p == nullptr)
			{
				return npos;
			}
			return p - _str;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
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
		int _size;      // 目前的长度，不包括 \0
		int _capacity;  // 最大容量，不包括最后一个 \0

		static const size_t npos; // 不可以用缺省值（初始化列表使用），因为static修饰，是全局变量

		//static const size_t npos1 = -1;  // 但是这样子就可以（只对整形有效），所以用起来要注意。
		//static const double npos2 = 1.9; // 不可以，因为不是整形
	};

	const size_t string::npos = -1;

	istream& operator>>(istream& in, string& s)
	{
		s.clear(); // 要输入之前先清空

		char ch = in.get();   // 不直接 in>>ch; 的原因是，cin以空格、换行作为区分，下面如果读到这两个之一，就会以为这是结束，不会放入缓冲区
		char buff[128];       // 防止频繁扩容，缓冲区
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)   // 满了，最后一个位置放 \0 ，然后将缓冲区的数据放到s里面
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get(); // in 的 get 函数，可以拿到空格和换行，不会将其当作间隔处理 
		}

		if (i)  // 缓冲区还有数据没有存到s里面的情况
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
	    // 自己写了迭代器，就可以使用范围 for 了，可以不用友元函数
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}


}