#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<iostream>
#include <mutex>
#include <thread>
#include<stdio.h>
#include<functional>


namespace smart_ptr_simulate
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// 管理权转移
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_auto()
	{
		auto_ptr<int> ap1(new int(1));
		auto_ptr<int> ap2(ap1);

		*ap1 = 1; // 管理权转移以后导致ap1悬空，不能访问
		*ap2 = 1;

	}

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// C++11思路：语法直接支持
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;


		// 防拷贝
		// 拷贝构造和赋值是默认成员函数，我们不写会自动生成，所以我们不需写
		// C++98思路：只声明不实现，但是用的人可能会在外面强行定义，所以再加一条，声明为私有
	private:
		//unique_ptr(const unique_ptr<T>& up);
		// unique_ptr<T>& operator=(const unique_ptr<T>& up);
	private:
		T* _ptr;
	};

	void test_unique()
	{
		unique_ptr<int> up1(new int(1));
		//unique_ptr<int> up2(up1);
	}

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		template<class D>
		shared_ptr(T* ptr ,D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
			,_del(del)
		{}

		~shared_ptr()
		{
			Release();
		}

		void Release()
		{
			_pmtx->lock();
			bool deleteFlag = false;
			if (--(*_pcount) == 0)
			{
				
				if (_ptr)
				{
					_del(_ptr);
				}

				delete _pcount;
				deleteFlag = true;

				// delete _pmtx;  如何解决？
			}

			_pmtx->unlock();

			if (deleteFlag)
			{
				delete _pmtx;
			}
		}

		void AddCount()
		{
			_pmtx->lock();

			++(*_pcount);

			_pmtx->unlock();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			AddCount();
		}

		// sp1 = sp4
		// sp1 = sp1;
		// sp1 = sp2;
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddCount();
			}

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}

	private:
		T* _ptr;
		int* _pcount;
		std::mutex* _pmtx;

		function<void(T*)> _del = [](T* ptr) {
			cout << "function defalut lambda delete" << endl;
			delete ptr;
		};
	};



	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};





	void test_shared()
	{
		shared_ptr<int> sp1(new int(1));
		shared_ptr<int> sp2(sp1);
		shared_ptr<int> sp3(sp2);

		shared_ptr<int> sp4(new int(10));

		//sp1 = sp4;
		sp4 = sp1;

		sp1 = sp1;
		sp1 = sp2;
	}

	struct Date
	{
		int _year = 0;
		int _month = 0;
		int _day = 0;

		~Date()  // 加了析构，才会回退四个字节检测，然后才能发现错误
		{} 
	};

	void SharePtrFunc(smart_ptr_simulate::shared_ptr<Date>& sp, size_t n, std::mutex& mtx)
	{
		//cout << sp.get() << endl;

		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			smart_ptr_simulate::shared_ptr<Date> copy(sp);

			mtx.lock();

			sp->_day++;
			sp->_month++;
			sp->_year++;

			mtx.unlock();
		}
	}

	void test_shared_safe()
	{
		smart_ptr_simulate::shared_ptr<Date> p(new Date);
		std::cout << p.get() << std::endl;
		const size_t n = 100000;
		std::mutex mtx;
		std::thread t1(SharePtrFunc, ref(p), n, ref(mtx));
		std::thread t2(SharePtrFunc, ref(p), n, ref(mtx));

		t1.join();
		t2.join();

		cout << p->_day << endl;
		cout << p->_month << endl;
		cout << p->_year << endl;

		std::cout << p.use_count() << std::endl;
	}



	// 循环引用
	struct ListNode
	{
		//shared_ptr<ListNode> _next;
		//shared_ptr<ListNode> _prev;

		// 换成 weak_ptr 解决问题
		weak_ptr<ListNode> _next;
		weak_ptr<ListNode> _prev;
		
		int _val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};


	void test_shared_cycle()
	{
		shared_ptr<ListNode> sp1(new ListNode);
		shared_ptr<ListNode> sp2(new ListNode);

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;

		sp1->_next = sp2;
		sp2->_prev = sp1; // 注释掉这两行任意一个，就可以将 sp1、sp2 析构，这是循环引用导致的

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
	}
	// 解决办法： weak_ptr 
	// 1、他不是常规的智能指针，不支持RAII
	// 2、支持像指针一样
	// 3、专门设计出来，辅助解决shared_ptr的循环引用问题
	//    weak_ptr可以指向资源，但是他不参与管理，不增加引用计数



	// 定制删除器
	template<class T>
	struct DeleteArray
	{
		void operator()(T* ptr)
		{
			cout << "void operator()(T* ptr)" << endl;
			delete[] ptr;
		}
	};

	void test_shared_deletor1()
	{
		std::shared_ptr<Date> sp1(new Date[10],DeleteArray<Date>());

		std::shared_ptr<Date> sp2(new Date[10], [](Date * ptr) {
			delete[] ptr;
			cout << "lambda delete[]" << endl;
			});

		std::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* ptr) {
			fclose(ptr);
			cout << "FILE fclose" << endl;
			});

	}

	void test_shared_deletor2()
	{
		shared_ptr<Date> sp1(new Date); // 面对这种情况，funciton 加一个默认的delete就行

		//shared_ptr<Date> sp2(new Date[10]); // Date 加了析构才能发现错误
		shared_ptr<Date> sp2(new Date[10], DeleteArray<Date>());

		shared_ptr<Date> sp3(new Date[10], [](Date* ptr) {
			delete[] ptr;
			cout << "lambda delete[]" << endl;
			});

		shared_ptr<FILE> sp4(fopen("Test.cpp", "r"), [](FILE* ptr) {
			fclose(ptr);
			cout << "FILE fclose" << endl;
			});

	}
}

















