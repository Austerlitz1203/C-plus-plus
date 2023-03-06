#pragma once
#include<iostream>
#include<assert.h>



namespace simulate
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//vector()
		//	:_start(nullptr)
		//	,_finish(nullptr)
		//	,_end_of_storage(nullptr)
		//{}

		//vector(size_t n, const T& val=T())
		//	:_start(nullptr)
		//	,_finish(nullptr)
		//	,_end_of_storage(nullptr)
		//{
		//	reserve(n);
		//	iterator* tmp = _start;
		//	for (size_t i = 0; i < n; i++)
		//	{
		//		*tmp = val;
		//		tmp++;
		//	}
		//}

		// 直接用缺省值替代初始化列表
		vector(){}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				*(_start + i) = val;
				++_finish;  // 不要忘了++ _finish ，一开始忘记了，所以打印不出来
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				*(_start + i) = val;
				++_finish;  // 不要忘了++ _finish ，一开始忘记了，所以打印不出来
			}
		}


		// 写了模板，但是不加上上面的int参数重载，会报错，因为vector(10,5)会调用模板函数
		template<class InputIterator>
		vector(InputIterator begin, InputIterator end)
		{
			reserve(end - begin);
			while (begin != end)
			{
				_push_back(*begin);
				++begin;
			}
		}


		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			
			for (int i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}

			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

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

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
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

		// 自己要写赋值重载，赋值重载和拷贝构造类似，一个 vector 复制给另一个 vector
		vector<T> operator=(const vector<T>& val)
		{
			_start = new T[val.capacity()];
			for (int i = 0; i < val.size(); i++)
			{
				_start[i] = val._start[i];
			}

			_finish = _start + val.size();
			_end_of_storage = _start + val.capacity();

			return *this;
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
				if (n > capacity())
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

		// 用迭代器，可能会出现迭代器失效的情况
		iterator insert(iterator pos , const T& x)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			size_t len = pos - _start;
			if (_finish == _end_of_storage)
			{
				reserve(2 * capacity());
				pos = _start + len;  // 扩容之后，_start 改变了
			}

			iterator tmp = _finish - 1;
			while (tmp >= pos)
			{
				*(tmp + 1) = *tmp;
				--tmp;
			}
			*pos = x;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator tmp = pos + 1;

			while (tmp != _finish)
			{
				*(tmp-1) = *tmp;
				tmp++;
			}
			--_finish;

			return pos;
		}

		~vector()
		{
			delete[] _start;
			_finish = _end_of_storage = nullptr;
		}

	private:
		T* _start=nullptr;
		T* _finish=nullptr;
		T* _end_of_storage=nullptr;
	};



	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows, vector<int>());
			for (size_t i = 0; i < vv.size(); ++i)
			{
				vv[i].resize(i + 1, 0);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

}