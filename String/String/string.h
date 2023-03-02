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

		void resize(size_t n,char ch='\0')
		{
			// ɾ�����ݣ�����ǰn��
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else if (n > _size)  // ���ÿ��� n = _size ���������Ϊ�����������Ҫ�ı��κ�ֵ
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

		void reserve(size_t n) // ���ݣ����ı�����
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
			// Ҫɾ�������ݴ��ڵ���pos֮��ĳ���
			if (len == npos || pos + len >= _size) // Ҫ�ж� len == npos ��������� pos+len ������鷳��
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else  // Ҫɾ��������û�г������һ���ַ�
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
		int _size;      // Ŀǰ�ĳ��ȣ������� \0
		int _capacity;  // ������������������һ�� \0

		static const size_t npos; // ��������ȱʡֵ����ʼ���б�ʹ�ã�����Ϊstatic���Σ���ȫ�ֱ���

		//static const size_t npos1 = -1;  // ���������ӾͿ��ԣ�ֻ��������Ч��������������Ҫע�⡣
		//static const double npos2 = 1.9; // �����ԣ���Ϊ��������
	};

	const size_t string::npos = -1;

	istream& operator>>(istream& in, string& s)
	{
		s.clear(); // Ҫ����֮ǰ�����

		char ch = in.get();   // ��ֱ�� in>>ch; ��ԭ���ǣ�cin�Կո񡢻�����Ϊ���֣������������������֮һ���ͻ���Ϊ���ǽ�����������뻺����
		char buff[128];       // ��ֹƵ�����ݣ�������
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)   // ���ˣ����һ��λ�÷� \0 ��Ȼ�󽫻����������ݷŵ�s����
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get(); // in �� get �����������õ��ո�ͻ��У����Ὣ�䵱��������� 
		}

		if (i)  // ��������������û�д浽s��������
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
	    // �Լ�д�˵��������Ϳ���ʹ�÷�Χ for �ˣ����Բ�����Ԫ����
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}


}