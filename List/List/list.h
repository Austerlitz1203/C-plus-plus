#pragma once
#include<iostream>
#include<assert.h>
#include"iterator.h"
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

		// ���ﲻ��Ҫд�������죬ֱ���ñ������Զ����ɵ�ǳ��������


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
	

	// ����������������� operator* ����ֵ������
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

		typedef simulate_iterator::ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef simulate_iterator::ReverseIterator<iterator, const T&, const T*> const_reverse_iterator;


		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		void empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		// ��ʼ��һ��list������һ���ڱ�λ�ڵ㣨˫���ͷѭ������
		list()
		{
			empty_init();
		}

		void swap(list<T>& x)
		{
			std::swap(_head, x._head);
		}

		list(const list<T>& x)
		{
			empty_init();
			list<T> tmp(x.begin(), x.end()); // ���ǹ��캯��
			swap(tmp);
		}

		template<class InputIterator>
		list(InputIterator start,InputIterator finish)
		{
			empty_init();
			while (start._node != finish._node)
			{
				push_back(*start);
				++start;
			}
		}

		list<T> operator=( list<T> x)
		{
			swap(x);
			return *this;
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

		// ���� const ���ε��� *this�� *this �� list ��һ���������Ա������һ��ָ��
		// ָ�뱾���Ȼ�ǲ����Ըı�ģ�������ָ������ݿ��Ըı�
		// ���������Ļ������ʵ�� const_iterator �أ�
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		// �� pos λ�õ�ǰһ����������
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

		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;
			delete pos._node;

			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}

		~list<T>()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);//����++ ���������������ˣ�����it������ʵ���� it �Ѿ�++
			}

			delete _head;
			_head = nullptr;
		}

	private:
		node* _head;
	};


	// û��ʵ�� const_iterator ������£����ô˺����ᵼ�����ݷ���
	// ���ǣ��Ҵ������ const ���ε�list�����ݲ�Ӧ�ñ��ı䣬����Ҫʵ�� const_iterator
	void print_list(const list<int>& lt)
	{
		simulate::list<int>::const_iterator it = lt.begin(); // 
		while (it != lt.end())
		{
			//(*it) *= 2;   // ʵ�� const_iterator ֮�󣬾Ͳ�����������
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

}


