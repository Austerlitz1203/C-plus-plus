//C++ ����C�﷨
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


//�����ռ�
//#include<stdio.h>
//#include<stdlib.h>
//
//
////1.�Լ���������ֺͿ��������ֳ�ͻ
////2.��Ŀ�飬������ĳ�Ա��������ֳ�ͻ
//int rand = 10;
//
////C�����޷����������������ͻ���⣬����C++ �����namespace�����
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
////1.ָ�������ռ����
////2.ȫ��չ����һ������£�������ȫ��չ��
////3.����
////using namespace std;
////using namespace AQueue;
//
//using AQueue::Queue;
//using std::cout;
//using std::endl; // ����չ����ֻ����ĳ�������ռ��һ���֡������ӱ������Ϳ����ҵ�����
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
//	BList::B::x++; // ���Զ���Ƕ��
//
//
//	return 0;
//}
//


//#include <iostream>
////using namespace std;
//// ʵ�ʿ�������Ŀ����
//// 1��ָ�������ռ����
//// 3�����ò���չ��
//
//// С�ĳ����ճ���ϰ����̫����ֳ�ͻ
//// 2��ȫ��չ��.һ�������������ȫ��չ���ġ�
//
//// ����չ��
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


// cin��cout 
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// <<������
//	cout << "hello world!" << endl;
//	cout << "hello world!" << "\n";
//
//	//�Զ�ʶ������
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




//ȱʡ����
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
////ȫȱʡ
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
//	func1(88, 65, 32); // ֻ�ܴ�������ȱʡ
//	func1(50, 1024);
//	func1(222);
//	func1();
//	return 0;
//}


#include<iostream>
using namespace std;

//��ȱʡ�����������������ȱʡ
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
	StackInit(&a, 100); //����������һ�ٸ�����
	StackInit(&a); //��֪����Ҫ���ٸ�����
	return 0;
}