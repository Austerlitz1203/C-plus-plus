#pragma once
#include<iostream>
#include<vector>
#include<list>

using namespace std;

namespace simulate
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
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