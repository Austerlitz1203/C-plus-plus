#include<iostream>
#include<assert.h>
using namespace std;

//class A
//{
//public:
//	//void Print()
//	//{
//	//	cout << _a << endl;
//	//}
//
//	// 修饰之后，是  Print(const A* this)  。否则是 Print(A* this) 
//	void Print()const
//	{
//		cout << _a << endl;
//	}
//
//	void Add(int x)
//	{
//		_a += x;
//	}
//
//
//	// 但是 取地址 、 const取地址 一般而言都不需要自己写。除非想让别人取到别的地址，但是几乎没有这种情况
//	A* operator&()
//	{
//		return this;
//	}
//
//	const A* operator&()const
//	{
//		return this;
//	}
//private:
//	int _a = 10;
//};
//
//int main()
//{
//	const A a;  // 如果调用没有const 修饰的成员函数，会出现权限放大的情况， *this 可以更改了
//	a.Print();
//	
//	A b;   // 这里调用 Print 就相当于权限缩小，无所谓
//	b.Add(2);
//	b.Print();
//
//	return 0;
//}




//class A
//{
//public:
//	int& operator[](int i)
//	{
//		assert(i < 10);
//		return _a[i];
//	}
//
//	// 构成函数重载，应用于不同场景。 当然，不提供也可以，看需求。
//	const int& operator[](int i)const 
//	{
//		assert(i < 10);
//		return _a[i];
//	} 
//private:
//	int _a[10];
//	int _size;
//};
//
//void Func(const A& aa)
//{
//	for (int i = 0; i < 10; i++)
//		cout << aa[i] << " ";
//}
//
//int main()
//{
//	A aa;
//	for (int i = 0; i < 10; i++)
//		aa[i] = i;
//
//	for (int i = 0; i < 10; i++)
//		cout << aa[i] << " ";
//
//	cout << endl;
//	Func(aa);
//}




//class B
//{
//public:
//	// 不需要传参
//	//B()
//	//	:_b(0)
//	//{
//	//	cout << "B()" << endl;
//	//}
//
//	B(int n)
//		:_b(0)
//	{
//		cout << "B()" << endl;
//	}
//
//
//private:
//	int _b;
//};
//
//class A
//{
//public:
//	A()
//		:_x(1)
//		, _a2(1)
//		, _ref(_a1)
//		, bb(4)  // B 类的初始化列表有参数了，没有默认构造（无参数），需要传参，必须这样写
//	{
//		_a1++;
//		_a2--;
//	}
//private:
//	int _a1=1; // 声明
//	int _a2=2;
//
//	// 引用 、const修饰 、没有默认构造 的  自定义类型成员
//	const int _x;
//	int& _ref;   // 引用也要在定义的地方初始化
//	B bb;
//};
//
//
//int main()
//{
//	const int t = 10;  // const 修饰，只能初始化的时候给值
//	A aa;  // 对象的整体定义，每个成员什么时候定义呢？
//	// 考虑到 const 修饰的，可以用缺省值，但这是 C++ 11 才有的，那么之前呢？
//	// 必须给每个成员变量找一个定义的位置，不然 像 const 修饰的就不好处理
//
//
//	return 0;
//}


class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};
int main() {
	A aa(1);
	aa.Print();

	// 输出结果是 1  随机值
	// 因为初始化列表里面，初始化顺序是 声明的顺序，而不是 初始化列表里面的顺序
}