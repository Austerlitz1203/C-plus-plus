#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace simulate
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;

		__list_node(const T& x=T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(x)
		{}
	};


	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T,Ref,Ptr> self;
		node* _node;

		__list_iterator(node * x)
			:_node(x)
		{}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return (&_node->_data);
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp = _node;
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(const self& x)
		{
			return _node == x._node;
		}

		bool operator!=(const self& x)
		{
			return _node != x._node;
		}
		
	};
	

	// 这和上面的区别仅仅是 operator* 返回值的类型
	/*template<class T>
	struct __list_const_iterator
	{
		typedef __list_node<T> node;
		typedef __list_const_iterator<T> self;
		node* _node;

		__list_const_iterator(node* x)
			:_node(x)
		{}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		const T& operator*()
		{
			return _node->_data;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp = _node;
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(const self& x)
		{
			return _node == x._node;
		}

		bool operator!=(const self& x)
		{
			return _node != x._node;
		}

	};*/


	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		//typedef __list_const_iterator<T> const_iterator;
		typedef __list_iterator<T, const T&,const T*> const_iterator;

		// 初始化一个list，先有一个哨兵位节点（双向带头循环链表）
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			//node* tail = _head->_prev;
			//node* tmp = new node(x);

			//tail->_next = tmp;
			//tmp->_prev = tail;

			//tmp->_next = _head;
			//_head->_prev = tmp;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end() 
		{
			return iterator(_head);
		}

		// 这里 const 修饰的是 *this， *this 是 list 的一个对象，其成员变量是一个指针
		// 指针本身固然是不可以改变的，但是其指向的内容可以改变
		// 可是这样的话，如何实现 const_iterator 呢？
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		// 在 pos 位置的前一个插入数据
		void insert(iterator pos, const T& val)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;

			node* tmp = new node(val);
			prev->_next = tmp;
			tmp->_prev = prev;
			tmp->_next = cur;
			cur->_prev = tmp;
		}

		void erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;
			delete pos._node;

			prev->_next = next;
			next->_prev = prev;
		}

	private:
		node* _head;
	};


	// 没有实现 const_iterator 的情况下，调用此函数会导致数据翻倍
	// 可是，我传入的是 const 修饰的list，数据不应该被改变，所以要实现 const_iterator
	void print_list(const list<int>& lt)
	{
		simulate::list<int>::const_iterator it = lt.begin(); // 
		while (it != lt.end())
		{
			//(*it) *= 2;   // 实现 const_iterator 之后，就不可以这样了
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

}


