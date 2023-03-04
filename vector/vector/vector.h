#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


namespace simulate
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		bool empty()
		{
			return _start == _finish;
		}

		T& operator[](size_t x)
		{
			assert(x < size());
			return _start[x];
		}


		const T& operator[](size_t x)const
		{
			assert(x < size());
			return _start[x];
		}

		void resize(size_t n,T x=T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > apacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = x;
					_finish++;
				}

			}
		}


		void reserve(int n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)  // 非空，复制数据，删除原空间。为空则不需要这样做
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;
			}
		}

		void _push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				int sz = capacity() == 0 ? 4 : 2 * capacity();
				reserve(sz);
			}

			*_finish = x;
			++_finish;
		}

		void _pop_back()
		{
			assert(!empty());
			--_finish;
		}


	private:
		T* _start;
		T* _finish;
		T* _end_of_storage;
	};

}