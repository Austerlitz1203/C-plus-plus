#include<iostream>

using namespace std;


//class A
//{
//public:
//	int _a;
//};
//
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	// 根据调试，查看内存，进而分析虚继承的特点
//
//	D d1,d2,d3; // 多个对象，其B、C对象中都是用同一个指针（内存窗口查看）
//
//
//	B b = d1;
//	C c = d1;
//  
//  // 通过反汇编，可以看出其方法是一摸一样的，寻找偏移量 
//  B* ptrb=&d;
//  ptrb->_a++;
//  
//  ptrb=&b;
//  ptrb->_a++;
// 
//	return 0;
//}



class M
{
public:
	void func() {
	}

protected:
	int _a;
	int _b;
};

class N
{
public:

private:
	M _m;  // 组合 ，可以使用 public 成员，不能使用 protected、private 成员
	       // M 改动 protected、private 成员基本不影响 N，如果是继承，会影响
};




class A
{
public:
	A(const char* s) {
		cout << s << endl;
	}
};


class B : virtual public A
{
public:
	B(const char* s1, const char* s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};


class C : virtual public A
{
public:
	C(const char* s1, const char* s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};


class D : public B, public C  // 先继承 B
{
public:
	D(const char* s1,const char* s2, const char* s3, const char* s4)
		:B(s1, s2)  // 初始化列表初始化的顺序，只和变量声明顺序有关
		, A(s1)     // 在继承这里，就是和被继承的先后顺序
		, C(s1, s3) // 首先， A 是最先被继承的，然后对于D，先继承B，再继承C
	{
		cout << s4;
	}
};

int main()
{
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}