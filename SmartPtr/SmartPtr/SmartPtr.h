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

		// ����Ȩת��
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

		*ap1 = 1; // ����Ȩת���Ժ���ap1���գ����ܷ���
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

		// C++11˼·���﷨ֱ��֧��
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;


		// ������
		// ��������͸�ֵ��Ĭ�ϳ�Ա���������ǲ�д���Զ����ɣ��������ǲ���д
		// C++98˼·��ֻ������ʵ�֣������õ��˿��ܻ�������ǿ�ж��壬�����ټ�һ��������Ϊ˽��
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

				// delete _pmtx;  ��ν����
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

		~Date()  // �����������Ż�����ĸ��ֽڼ�⣬Ȼ����ܷ��ִ���
		{} 
	};

	void SharePtrFunc(smart_ptr_simulate::shared_ptr<Date>& sp, size_t n, std::mutex& mtx)
	{
		//cout << sp.get() << endl;

		for (size_t i = 0; i < n; ++i)
		{
			// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
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



	// ѭ������
	struct ListNode
	{
		//shared_ptr<ListNode> _next;
		//shared_ptr<ListNode> _prev;

		// ���� weak_ptr �������
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
		sp2->_prev = sp1; // ע�͵�����������һ�����Ϳ��Խ� sp1��sp2 ����������ѭ�����õ��µ�

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
	}
	// ����취�� weak_ptr 
	// 1�������ǳ��������ָ�룬��֧��RAII
	// 2��֧����ָ��һ��
	// 3��ר����Ƴ������������shared_ptr��ѭ����������
	//    weak_ptr����ָ����Դ��������������������������ü���



	// ����ɾ����
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
		shared_ptr<Date> sp1(new Date); // ������������funciton ��һ��Ĭ�ϵ�delete����

		//shared_ptr<Date> sp2(new Date[10]); // Date �����������ܷ��ִ���
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

















