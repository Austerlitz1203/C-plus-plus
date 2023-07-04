#pragma once

#include<iostream>
#include <mutex>
#include <thread>


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
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		~shared_ptr()
		{
			Release();
		}

		void Release()
		{
			_pmtx->lock();

			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;

				// delete _pmtx;  如何解决？
			}

			_pmtx->unlock();
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

		T* get()
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
	};

	void SharePtrFunc(smart_ptr_simulate::shared_ptr<Date>& sp, size_t n, std::mutex& mtx)
	{
		//cout << sp.get() << endl;

		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			smart_ptr_simulate::shared_ptr<Date> copy(sp);
		}
	}

	void test_shared_safe()
	{
		smart_ptr_simulate::shared_ptr<Date> p(new Date);
		std::cout << p.get() << std::endl;
		const size_t n = 10000;
		std::mutex mtx;
		std::thread t1(SharePtrFunc, std::ref(p), n, ref(mtx));
		std::thread t2(SharePtrFunc, std::ref(p), n, ref(mtx));

		t1.join();
		t2.join();

		std::cout << p.use_count() << std::endl;
	}
}