//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int i = 10;
//	int& k = i;//相当于，给i取一个别名，k和i是一样的
//	int j = i;
//
//	cout << &i << endl;
//	cout << &k << endl;
//	cout << &j << endl;
//
//	++k;
//	++j;
//
//	cout << i << endl;
//	cout << j << endl;
//
//	int& m = i;//可以有多个别名
//
//	int& n = k;//也可以给别名取别名
//
//
//	return 0;
//}


// 1.引用作函数参数
//#include<iostream>
//using namespace std;
//
//void swap(int& x, int& y)//直接使用引用，要舒服很多，形参就是实参的别名
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//typedef struct Node
//{
//	int val;
//	struct Node* next;
//}Node;
//
//void PushBack(Node*& phead, int x)
//{
//	Node* newhead = (Node*)malloc(sizeof(Node));
//	if (!phead)
//	{
//		phead = newhead;
//	}
//
//}
//
//int main()
//{
//	//int a = 1, b = 2;
//	//cout << a << ' ' << b << endl;
//	//swap(a, b);
//	//cout << a << ' ' << b << endl;
//
//
//	//int* p = &a;
//	//int*& rp = p;
//
//	Node* plist = nullptr;
//	PushBack(plist, 1);
//	PushBack(plist, 2);
//
//
//	return 0;
//}



// 2. 引用作返回值
// 首先，可以减少拷贝，其次，调用者可以修改返回对象
//#include<iostream>
//#include<assert.h>
//
//#define N 10
//using namespace std;
//
//struct Array
//{
//	int& at(int i)
//	{
//		assert(i < N);
//		return a[i];
//	}
//	int a[N];
//	int size;
//
//};
//
//int main()
//{
//	struct Array ay;
//	for (int i= 0; i < N; i++)
//	{
//		ay.at(i) = i;  // 如果返回值不是引用，就是普通的 int ，那么每次就是返回的临时变量，由于临时变量具有
//		               // 常性，不可修改，所以会报错的
//	}
//
//	for (int i = 0; i < N; i++)
//		cout << ay.at(i) << endl;
//
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int& Add(int a, int b)
//{
//    int c = a + b;
//	return c;
//}
//// 出了作用域，c销毁了，但是返回的是c的引用，虽然能找到原本c的地址，但是不知道是不是被销毁了
//// 所以如果出了函数作用域，返回对象已经被操作系统回收了，就必须返回值而不可以返回引用
//int main()
//{
//	int& ret = Add(1, 2);  
//	cout << ret << endl;
//	Add(3, 4);
//	cout << ret << endl;
//
//	cout << ret << endl;
//
//	printf("\n");
//	int ret1 = Add(1, 2);  // ret1 不是 c 的别名，是一个变量，但是它的值还是不确定的，要看收回空间是否先清除数据
//	cout << ret1 << endl;
//	Add(3, 4);
//	cout << ret1 << endl;
//
//	cout << ret1 << endl;
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int main()
//{
//	 // 权限平移
//	int a = 10;
//	int& b = a;
//
//
//	// 引用和指针，赋值 / 初始化  权限可以缩小、平移，不可以放大
//	const int c = 10;
//	int& d = c; // 权限放大
//
//	const int*  p1=null;
//	int* p2 = p1;
//
//
//	int x = 10;
//	const int& y = x; // 权限缩小
//
//	int* p3=null;
//	const int* p4 = p3; // 权限缩小
//
//
//
//	// 权限的放大和缩小，只适用于指针和引用，因为引用是起一个别名，b的改变会影响a，指针同理
//	// 但是下面，n，m是两块不同的空间，n的改变不会影响m
//	const int m = 10;
//	int n = m; // 把 m 的值赋给 n
//
//
//	int i = 10;
//	cout << (double)i << endl; // 这里并不是把 i 强制类型转换成 double 类型，只是把i放到一个double类型的临时变量里面
//
//	double dd = i; // 这里把 创建临时变量，然后i放到临时变量里面的过程省略了
//
//	double& l = i;   // 这里 l 是临时变量的引用，但是临时变量具有常性，相当于权限放大
//	const double& ll = i;  // ll 是临时变量的引用，权限平移
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	// 从汇编角度来看，引用其实也是指针实现的，开辟了空间，但是我们使用的时候不需要这样理解
//	return 0;
//}





// C++推荐：
// const 和 enum 替代宏常量
// inline 替代宏函数
// 因为 宏 
// 1、不能调试
// 2、没有类型安全的检查
// 3、有些场景下非常复杂
// 


#include<iostream>

#define Add(x,y) ((x)+(y))

using std::cout;
using std::endl;

// 使用内联函数，没有函数调用，编译器会在使用内联函数的时候，将函数体展开
// 但是内联函数只是相当于给编译器一个“建议”，实际上是编译器决定是否展开，比如递归函数，展开就得很多行，编译器就不会展开
inline int ADD(int x, int y)
{
	int c = x + y;
	return c;
}

int main()
{
	//int m=Add(4, 6);
	//cout << m << endl;

	cout << ADD(3, 7) << endl;

	return 0;
}
