#pragma once
#include<iostream>
#include<vector>
#include<list>

using namespace std;

namespace simulate
{
	template<class T, class Container = list<T>>
	class queue
	{
	public:

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& top()
		{
			return _con.front();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

}