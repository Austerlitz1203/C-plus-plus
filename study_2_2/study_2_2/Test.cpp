#include<iostream>
using namespace std;


//void test(int array[])
//{
//	for (auto x : array) // 不可以，因为此时array是指针
//		cout << x << " ";
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = &a;
//	auto& d = a;
//	// auto 不可以定义数组，不可以做为形参
//
//
//
//	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (auto e : array)   // 遍历 array 里面的元素，每一个都赋值给e
//		cout << e << " ";
//
//	cout << endl;
//	for (auto& e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//
//	cout << endl;
//	for (auto e : array)
//		cout << e << " ";
//	cout << endl;
//	
//	return 0;
//}





//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	/*int* p1 = NULL;
//	int* p2 = nullptr;*/
//	f(0);
//	f(NULL);  // 对于 NULL，C++ 使用 nullptr代替，避免出现这样的情况，NULL的值为 0（int 类型）
//	f(nullptr);
//
//	return 0;
//}




// C++兼容C结构体的用法
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTN;
//
//// C里面： struct ListNode 是类型
//
//// C++把结构体升级成了类
//struct ListNode
//{
//	int val;
//	ListNode* next;  // ：ListNode 是类型
//};


// 类
// 成员函数可以直接定义到类里面
//struct Stack
//{
//	// 成员函数
//	void Init(int n = 4)
//	{
//		a = (int*)malloc(sizeof(int)* n);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		capacity = n;
//		size = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//		a[size++] = x;
//	}
//
//	// 成员变量
//	int* a;
//	int size;
//	int capacity;
//};





//#include "Stack.h"
//
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	Date d1;
//	d1.Init(2023, 2, 3);
//
//	return 0;
//}





// 类 -- 就类似于别墅设计图
// 将其实例化之后，就类似于一栋栋的毛胚房，里面具体的一些东西，要自己添加
// 
//class Date
//{
//public:
//	// 定义
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
////private:
//	int _year;  // 声明
//	int _month;
//	int _day;
//};
//
//class A2 {
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	// 类对象实例化 -- 开空间
//	// 实例化 -- 用设计图建造一栋栋别墅
//	Date d1;
//	Date d2;
//
//	// 为什么成员变量在对象中，成员函数不在对象中？
//	// 每个对象成员变量是不一样的，需要独立存储
//	// 每个对象调用成员函数是一样的，放到共享公共区域(代码段）
// 
//	d1.Init(2023, 2, 2);
//	d1._year++;
//
//	d2.Init(2022, 2, 2);
//	d2._year++;
//
//	cout << sizeof(d1) << endl;
//
//	// 大小是1，这1byte不存储有效数据
//	// 起一个占位的作用，标识对象被实例化定义出来了。
//	A2 aa1;
//	A2 aa2;
//	cout << &aa1 << endl;
//	cout << &aa2 << endl;
//	cout << sizeof(aa1) << endl;
//
//	return 0;
//}





//class Date
//{
//public:
//	// 定义
//  // 实际上编译器处理之后是：
//  // void Init(Date* this,int year, int month, int day) 多了一个 this 指针
//	void Init(int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		cout << this << endl;
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void func()
//	{
//		cout << this << endl;
//		cout << "func()" << endl;
//	}
//
////private:
//	int _year;  // 声明
//	int _month;
//	int _day;
//};
//
//// 1、this存在哪里？-- 栈，因为他是隐含形参 / vs下面是通过ecx寄存器
//// 2、空指针问题
//int main()
//{
//	Date d1;
//	Date d2;
//	d1.Init(2022, 2, 2);  // 编译器优化之后  d1.Init(&d1，2022, 2, 2);  这样子，this指针就得以区分
//	d2.Init(2023, 2, 2);
//
//	// 编译报错  运行崩溃   正常运行
//	Date* ptr = nullptr;     
//	//ptr->Init(2022, 2, 2); // 运行崩溃，因为 this 解引用了
//
//	 ptr->func();            // 正常运行 ，因为并没有解引用 this
//	(*ptr).func();           // 正常运行 ，同上，虽然说是解引用 ptr，但是本质上也没有解引用 this 指针
//
//	return 0;
//}




class Stack
{
public:
	// 成员函数
	void Init(int n)
	{
		a = (int*)malloc(sizeof(int) * n);
		if (nullptr == a)
		{
			perror("malloc申请空间失败");
			return;
		}

		capacity = n;
		size = 0;
	}

	void Push(int x)
	{
		//...
		a[size++] = x;
	}

	//...

private:
	// 成员变量
	int* a;
	int size;
	int capacity;
};

int main()
{

	return 0;
}

