#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;

//class A
//{
//public:
//	//A(int a)
//	//	:_a1(a)
//	//{
//	//	cout << "A(int a)" << endl;
//	//}
//
//	A(int a,int b)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//
//private:
//	int _a1;
//};
//
//int main()
//{
//	// 单个参数
//	//A a1(1);
//	//A a2 = 1; // 隐式类型转换， 将 1 当作参数，调用初始化列表，有了 A 类型的临时变量，将临时变量拷贝给 a2
//	//          // 这样子很麻烦，所以有的编译器会优化成：直接调用初始化列表，1为参数
//
//	//const A& a3 = 1; // 引用就不像上面一样了，是要有临时变量这个过程的。临时变量具有常性，所以要const修饰
//
//
//	// 一开始不支持多个参数的，后来优化支持了
//	A b1(1, 2);
//	A b2 = { 2,2 };  // 多参数这样写
//	const A& b3 = { 4,7 };
//
//	int x = 10;
//	double y = x;  // 隐式类型转换
//
//	return 0;
//}







//class A
//{
//public:
//
//	explicit A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//
//private:
//	int _a1;
//};
//
//int main()
//{
//	// 如果不想让内置类型，转换为自定义类型，可以在初始化列表的函数前面用 explicit 修饰
//	A a = 1;
//
//	return 0;
//}




//using std::cout;
//using std::endl;
//
//int count = 0;
//
//class A
//{
//public:
//
//	 A(int a)
//		:_a1(a)
//	{
//		 count++;
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& a)
//	{
//		count++;
//		cout << "A(const A& a)" << endl;
//	}
//
//private:
//	int _a1;
//};
//
//
//int main()
//{
//	// 计算一个类到底创建了多少个对象
//	// 1. 定义全局变量，每次都++ . 
//	//A a(1);
//	//const A& a1 = 1;
//	// 
//	//cout << count << endl;  // count 和 std命名空间里面的部分冲突了，以C++ 的思想，不是换名字，是用部分std内容
//
//	return 0;
//}





//class A
//{
//public:
//
//	A(int a)
//		:_a1(a)
//	{
//		count++;
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& a)
//	{
//		count++;
//		cout << "A(const A& a)" << endl;
//	}
//
//	static int Size()  // 静态成员函数，没有 this 指针，所以无法访问非静态的成员变量
//	{
//		return count;
//	}
//
//private:
//	int _a1;
//	static int count; // 声明。此外，这个成员变量不属于某个对象，属于整个类
//};
//
//int A::count=0;  // 初始化
//
//int main()
//{
//	 //计算一个类到底创建了多少个对象
//	 //2. static 成员变量，让其被所有类公有，而不是每一个对象私有的 
//	//A a(1);
//	//const A& a1 = 1;
//	// 
//	//// 但是，此时 count是private的，需要变成public才可以被外部访问到
//	//A aa(2);
//	//cout << aa.count << endl;
//	//cout << A::count << endl;
//
//
//	// 上面的方法让其成为 public ，不安全。所以可以定义静态成员函数，这个函数返回 count 的值
//	A a(1);
//	const A& a1 = 1;
//	
//	cout << A::Size() << endl;
//
//	cout << A(1).Size() << endl;  // 匿名对象，生命周期只在这一行
//
//	return 0;
//}



//class A
//{
//public:
//	// B 是 A 的内部类，B 相当于被隐藏起来了，外面不可以直接使用。
//	// 1. B 受 A 的 类域限制。
//	// 2. B 天生就是 A 的友元类，B里面可以使用A的成员。（反过来不行，A里面不可以使用B的成员）
//	class B  
//	{
//	public:
//		B(int b)
//			:_b(b)
//		{
//			cout << "B(int b)" << endl;
//		}
//
//		void func(const A& a)
//		{
//			cout << a._a << endl;  // 可以直接访问 A 里面的成员
//		}
//
//	private:
//		int _b;
//
//	};
//
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//private:
//	int _a;
//	static int m;
//};
//
//int A::m = 10;
//
//int main()
//{
//	A a(1);
//	cout << sizeof(a) << endl;  // B 虽然是A 的内部类，但并不是实例化了A对象，也在A里面实例化了B对象
//	                            // A、B 是独立的
//
//	return 0;
//}





class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;

		if (this != &aa)
		{
			_a = aa._a;
		}

		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void func1(A aa)
{

}

void func2(const A& aa)
{

}

//int main()
//{
//	A aa1 = 1; // 构造+拷贝构造 -》 优化为直接构造
//	func1(aa1); // 无优化
//	func1(2); // 构造+拷贝构造 -》 优化为直接构造
//	func1(A(3)); // 构造+拷贝构造 -》 优化为直接构造
//
//	cout << "----------------------------------" << endl;
//
//	func2(aa1);  // 无优化
//	func2(2);    // 无优化
//	func2(A(3)); // 无优化
//
//
//	return 0;
//}



A func3()
{
	A aa;
	return aa;   // 不可以优化，因为分开的
}

A func4()
{
	return A();  // 可以优化
}


//深度探索C++对象模型
int main()
{
	func3();

	A aa1 = func3(); // 拷贝构造+拷贝构造  -- 优化为一个拷贝构造


	cout << "****" << endl;

	A aa2;
	aa2 = func3();   // 不能优化  ， 因为是赋值重载


	cout << "---------------------------" << endl;

	func4();         // 构造+拷贝构造 -- 优化为构造
	A aa3 = func4(); // 构造+拷贝构造+拷贝构造  -- 优化为构造

	return 0;
}

