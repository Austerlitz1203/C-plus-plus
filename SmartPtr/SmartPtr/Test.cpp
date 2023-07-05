#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


// 1、RAII
// 2、像指针一样使用
// 3、拷贝问题
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout <<"delete:"<<_ptr << endl;
//		delete _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//



////int div()
////{
////	int a, b;
////	cin >> a >> b;
////	if (b == 0)
////		throw invalid_argument("除0错误");
////
////	return a / b;
////}
////
////void Func()
////{
////	// 1、如果p1这里new 抛异常会如何？
////	// 2、如果p2这里new 抛异常会如何？
////	// 3、如果div调用这里又会抛异常会如何？
////	SmartPtr<int> sp1(new int(1));
////	SmartPtr<int> sp2(new int(2));
////
////	cout << div() << endl;
////
////	*sp1 = 10;
////
////	cout << *sp1 << endl;
////	cout << *sp2 << endl;
////}
////
////int main()
////{
////	try
////	{
////		Func();
////	}
////	catch (exception& e)
////	{
////		cout << e.what() << endl;
////	}
////
////	return 0;
////}
//
//int main()
//{
//	SmartPtr<int> sp1(new int(1));
//
//	SmartPtr<int> sp2(sp1);
//
//	return 0;
//}




#include "SmartPtr.h"
#include <memory>

void test_auto()
{
	std::auto_ptr<int> ap1(new int(1));
	std::auto_ptr<int> ap2(ap1);

	*ap1 = 1; // 管理权转移以后导致ap1悬空，不能访问
	*ap2 = 1;
}


void test_unique()
{
	std::unique_ptr<int> up1(new int(1));
	//std::unique_ptr<int> up2(up1);
}

int main()
{
	//smart_ptr_simulate::test_auto();
	//smart_ptr_simulate::test_shared();
	//smart_ptr_simulate::test_shared_safe();

	//test_auto();
	//test_unique();


	//smart_ptr_simulate::test_shared_cycle();
	//smart_ptr_simulate::test_shared_deletor1();
	smart_ptr_simulate::test_shared_deletor2();
	return 0;
}