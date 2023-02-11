#include<iostream>
#include<algorithm>

using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};
//
////ListNode BuyListNode(int x)
////{
////	//...
////}
//
//int main()
//{
//	int* pp1 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//
//	free(pp1);
//
//	delete p1;
//
//	int* pp2 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];
//
//	free(pp2);
//	delete[] p2;
//
//	A* pp3 = (A*)malloc(sizeof(A));
//	free(pp3);
//
//	A* p3 = new A(1);
//	delete p3;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//
//
//	return 0;
//}



// 匹配使用，不要交叉
//int main()
//{
//	//int* p1 = new int;  
//	int* p1 = new int(10);// 初始化
//
//	int* p3 = new int[10];// 申请的数组
//	int* p4 = new int[10]{ 1,2,3,4,5};//对数组初始化
//
//	int* p2 = (int*)malloc(sizeof(int));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	free(p2);
//	delete p1;
//	delete[] p3;
//	delete[] p4;
//
//	return 0;
//}





//class A
//{
//public:
//	A(int a = 10)
//	{
//		cout<<"A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Stack
//{
//public:
//	Stack()
//	{
//		cout<<"Stack()" << endl;
//		_a = new int[4];
//		_size = 0;
//		_capacity = 4;
//	}
//
//	~Stack()
//	{
//		cout<<"~Stack()" << endl;
//		free(_a);
//		_size = 0;
//		_capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};

//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	if (p1 == nullptr)
//	{
//		perror("malloc fail");
//	}
//	int* p2 = new int;
//
//	free(p1);
//	delete p2;
//
//	int* p3 = (int*)operator new(sizeof(int));  // 封装 malloc 
//	operator delete(p3);                        // 封装 free
//
//
//	// 调用 operator new 开辟空间   operator new -> malloc
//	// 调用构造函数
//	A* p5 = new A;
//	
//	// 先调用析构函数
//	// 再 operator delete p5指向的空间  operator deldte -> free
//	delete p5;
//
//
//	
//	// 先调用 operator new[] 。实际上 operator new[] 也是去调用 operator new
//	// 调用十次构造函数
//	A* p6 = new A[10];
//
//	// 一样，先调用十次析构函数
//	// 再调用 operator delete[] 
//	delete[] p6;
//
//
//
//	// 自定义类型，自动调用 构造函数 和 析构函数。
//	Stack st;
//
//	// 指针，是内置类型，不会调用构造函数。 new 的时候才调用
//	Stack* pst = new Stack;
//	delete pst;  // 如果 free(pst) 会少调用一次析构函数，那么在 Stack 类就会出现问题。（A 类不会）
//
//
//	// malloc 、new 底层实现机制有交叉关联，不匹配使用可能有问题，可能没问题。要匹配使用
//	A* p7 = new A[10];
//	//free(p7);  // 报错
//	//delete p7; // 报错。 但是去掉析构函数，就不报错。因为开辟空间的时候，在最前面存放了一个数字，代表着delete的时候，要调用几次析构。
//	delete[] p7;
//	return 0;
//}


//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	new(p1)A(1); // 定位 new ，用于调用构造函数来初始化。一般与内存池配合使用。
//
//	return 0;
//}




// 泛型编程——模板
// 
////template<class T>
//template<typename T> // typename 和 class 都可以
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class X, class Y>
//void func()
//{
//
//
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//
//	double c = 10.0, d = 18.8;
//	Swap(c, d);  // 转到汇编看，两次调用并不是同一个函数
//	cout << c << " " << d << endl;
//
//	return 0;
//}




//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 2.89, d2 = 5.90;
//	cout << Add(a1, a2) << endl;
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	cout << Add<int>(a1, d1) << endl;    // 上面的都是编译器通过实参，来确定推演出什么参数类型的函数
//	cout << Add<double>(a1, d1) << endl; // 这两个是指定好参数类型。显示实例化
//
//	// 当然，也可模板写两个class
//	return 0;
//}




// 专门处理 int 类型的加法函数
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//// 通用加法函数
//template<class T1,class T2>
//T1 Add(T1 x, T2 y)
//{
//	return x + y;
//}
//
//
//int main()
//{
//	int a = 10, b = 3;
//	Add(a, b);  // 实际调用第一个，而不是用模板
//
//	
//	// 强制必须用模板
//	Add<int>(a, b);
//
//
//	Add(10.28, 9);  // 编译器会自己选择最匹配的
//
//	return 0;
//}




// 类模板

//typedef int STDatetype;
//class Stack
//{
//public:
//
//private:
//	STDatetype* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st1; // 存储 int 类型的数据
//	Stack st2; // 存储 double 类型的数据，做不到
//
//}



template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = new T[capacity];
		_size = 0;
		_capacity = capacity;
	}

	~Stack()
	{
		delete[] _a;
		_size = 0;
		_capacity = 0;
	}
private:
	T* _a;
	int _size;
	int _capacity;
};

int main()
{
	// 只能显示实例化
	Stack<int> st1; // 存储 int 类型的数据
	Stack<double> st2; // 存储 double 类型的数据

}