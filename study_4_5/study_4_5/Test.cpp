#include<iostream>

using namespace std;

//class Base
//{
//public:
//	Base()
//		:_b(10)
//	{
//		++_b;
//	}
//
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};

// 用程序打印虚表
typedef void(*VF_PTR)();

//void PrintVFTable(VF_PTR table[])
void PrintVFTable(VF_PTR* table)
{
	for (int i = 0; table[i] != nullptr; ++i)
	{
		printf("[%d]:%p->", i, table[i]);
		VF_PTR f = table[i];
		f();
	}
	cout << endl;
}

//int main()
//{
//	Base b;
//	Derive d;
//
//	// 在 32位 情况下适合，64位情况下，指针占8个字节，需要改变。
//	PrintVFTable((VF_PTR*)(*(int*)&b));
//	PrintVFTable((VF_PTR*)(*(int*)&d));
//
//	/*PrintVFTable((VF_PTR*)(*(long long*)&b));
//	PrintVFTable((VF_PTR*)(*(long long*)&d));*/
//
//
//
//	//PrintVFTable((*(VF_PTR**)&b));
//	//PrintVFTable((*(VF_PTR**)&d));
//
//	return 0;
//}


// 测试虚表在哪个区域，得出结论在 常量区（代码段）
//int main()
//{
//	Base b;
//	Derive d;
//
//	int x = 0;
//	static int y = 0;
//	int* z = new int;
//	const char* p = "xxxxxxxxxxxxxxxxxx";
//
//	printf("栈对象：%p\n", &x);
//	printf("堆对象：%p\n", z);
//	printf("静态区对象：%p\n", &y);
//	printf("常量区对象：%p\n", p);
//	printf("b对象虚表：%p\n", *((int*)&b));
//	printf("d对象虚表：%p\n", *((int*)&d));
//	return 0;
//}




class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
	int bb;
};

class Derive : public Base2, public Base1 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};



//int main()
//{
//	// 打印 Derive 类型的对象的虚表
//	// Derive 继承了两个类，自己实现的函数，是放在哪个虚表里面的？  —— 第一个虚表（最先继承的类的对象里面）
//	Derive d;
//	PrintVFTable((VF_PTR*)(*(int*)&d));
//	//PrintVFTable((VF_PTR*)(*(int*)((char*)&d+sizeof(Base1))));
//
//	Base2* ptr2 = &d;
//	PrintVFTable((VF_PTR*)(*(int*)(ptr2)));
//
//	return 0;
//}



int main()
{
	Derive d;
	Base1* ptr1 = &d;
	Base2* ptr2 = &d;

	// 调用 func1 ，这是多态的情况。
	// 但是两张虚表里面的 func1 ，地址不同。
	// 反汇编查看：ptr1 调用之后， ptr2调用的时候，要多一个修改 ecx 的过程，这是修正 this 指针（ecx里面存放）
	ptr1->func1();
 
	ptr2->func1();
	return 0;
}