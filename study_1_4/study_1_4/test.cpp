//C++ 兼容C语法
//#include<stdio.h>
//int main()
//{
//	printf("hello world!\n");
//	return 0;
//}


//#include<iostream>
////using namespace std;
//
//int main()
//{
//	//cout << "Hello World!" << endl;
//
//	std::cout << "Hello World!" << std::endl;
//	return 0;
//}


//命名空间
//#include<stdio.h>
//#include<stdlib.h>
//
//
////1.自己定义的名字和库里面名字冲突
////2.项目组，组里面的成员定义的名字冲突
//int rand = 10;
//
////C语言无法解决这样的命名冲突问题，所以C++ 提出了namespace来解决
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}

//#include"List.h"
//#include"Queue.h"
//#include<iostream>
////using namespace std;
//
//
//
//int main()
//{
//	//struct try1::Node a;
//
//	struct AQueue::Node b;
//
//	AQueue::m++;
//
//	std::cout << "Hello" << std::endl;
//
//
//	return 0;
//}




//#include"List.h"
//#include"Queue.h"
//#include<iostream>
//
////1.指定命名空间访问
////2.全局展开，一般情况下，不建议全局展开
////3.部分
////using namespace std;
////using namespace AQueue;
//
//using AQueue::Queue;
//using std::cout;
//using std::endl; // 部分展开，只是用某个命名空间的一部分。这样子编译器就可以找到它。
//
//int main()
//{
//	struct Queue a;
//	QueueInit(&a);
//	QueuePush(&a, 4);
//	QueuePush(&a, 7);
//	QueuePush(&a, 5);
//	QueuePush(&a, 10);
//
//	BList::B::x++; // 可以多重嵌套
//
//
//	return 0;
//}
//


//#include <iostream>
////using namespace std;
//// 实际开发的项目工程
//// 1、指定命名空间访问
//// 3、常用部分展开
//
//// 小的程序，日常练习，不太会出现冲突
//// 2、全局展开.一般情况，不建议全局展开的。
//
//// 常用展开
//using std::cout;
//using std::endl;
//
//
//int main()
//{
//	cout << "1111" << endl;
//	cout << "1111" << endl;
//	cout << "1111" << endl;
//	cout << "1111" << endl;
//
//	int i = 0;
//	std::cin >> i;
//
//	return 0;
//}


// cin、cout 
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// <<流插入
//	cout << "hello world!" << endl;
//	cout << "hello world!" << "\n";
//
//	//自动识别类型
//	int n = 0;
//	cin >> n;
//
//	double* a = (double*)malloc(sizeof(double) * n);
//	if (a == NULL)
//	{
//		perror("malloc fail::");
//		exit(-1);
//	}
//
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	for (int i = 0;i < n;i++)
//		cout << a[i] << endl;
//
//}




//缺省参数
//#include<iostream>
//using namespace std;
//
//void func1(int a = 10)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	func1();
//	return 0;
//}




//#include<iostream>
//using namespace std;
//
////全缺省
//void func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	cout << endl;
//}
//
//int main()
//{
//	func1(88, 65, 32); // 只能从右往左缺省
//	func1(50, 1024);
//	func1(222);
//	func1();
//	return 0;
//}


#include<iostream>
using namespace std;

//半缺省，必须从右往左连续缺省
void func1(int a, int b, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;
}


void func2(int a, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;
}

struct Stack
{
	int* a;
	int top;
	int capacity;
};

void StackInit(struct Stack* ps, int defaultCapacity = 4)
{
	ps->a = (int*)malloc(sizeof(int) * defaultCapacity);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = defaultCapacity;
}



int main()
{
	func1(11, 89);

	struct Stack a;
	StackInit(&a, 100); //明白最少有一百个数据
	StackInit(&a); //不知道需要多少个数据
	return 0;
}