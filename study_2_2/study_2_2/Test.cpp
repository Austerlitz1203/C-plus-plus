#include<iostream>
using namespace std;


//void test(int array[])
//{
//	for (auto x : array) // �����ԣ���Ϊ��ʱarray��ָ��
//		cout << x << " ";
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = &a;
//	auto& d = a;
//	// auto �����Զ������飬��������Ϊ�β�
//
//
//
//	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (auto e : array)   // ���� array �����Ԫ�أ�ÿһ������ֵ��e
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
//	f(NULL);  // ���� NULL��C++ ʹ�� nullptr���棬������������������NULL��ֵΪ 0��int ���ͣ�
//	f(nullptr);
//
//	return 0;
//}




// C++����C�ṹ����÷�
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTN;
//
//// C���棺 struct ListNode ������
//
//// C++�ѽṹ������������
//struct ListNode
//{
//	int val;
//	ListNode* next;  // ��ListNode ������
//};


// ��
// ��Ա��������ֱ�Ӷ��嵽������
//struct Stack
//{
//	// ��Ա����
//	void Init(int n = 4)
//	{
//		a = (int*)malloc(sizeof(int)* n);
//		if (nullptr == a)
//		{
//			perror("malloc����ռ�ʧ��");
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
//	// ��Ա����
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





// �� -- �������ڱ������ͼ
// ����ʵ����֮�󣬾�������һ������ë�߷�����������һЩ������Ҫ�Լ����
// 
//class Date
//{
//public:
//	// ����
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
////private:
//	int _year;  // ����
//	int _month;
//	int _day;
//};
//
//class A2 {
//public:
//	void f2() {}
//};
//
//// ����ʲô��û��---����
//class A3
//{};
//
//int main()
//{
//	// �����ʵ���� -- ���ռ�
//	// ʵ���� -- �����ͼ����һ��������
//	Date d1;
//	Date d2;
//
//	// Ϊʲô��Ա�����ڶ����У���Ա�������ڶ����У�
//	// ÿ�������Ա�����ǲ�һ���ģ���Ҫ�����洢
//	// ÿ��������ó�Ա������һ���ģ��ŵ�����������(����Σ�
// 
//	d1.Init(2023, 2, 2);
//	d1._year++;
//
//	d2.Init(2022, 2, 2);
//	d2._year++;
//
//	cout << sizeof(d1) << endl;
//
//	// ��С��1����1byte���洢��Ч����
//	// ��һ��ռλ�����ã���ʶ����ʵ������������ˡ�
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
//	// ����
//  // ʵ���ϱ���������֮���ǣ�
//  // void Init(Date* this,int year, int month, int day) ����һ�� this ָ��
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
//	int _year;  // ����
//	int _month;
//	int _day;
//};
//
//// 1��this�������-- ջ����Ϊ���������β� / vs������ͨ��ecx�Ĵ���
//// 2����ָ������
//int main()
//{
//	Date d1;
//	Date d2;
//	d1.Init(2022, 2, 2);  // �������Ż�֮��  d1.Init(&d1��2022, 2, 2);  �����ӣ�thisָ��͵�������
//	d2.Init(2023, 2, 2);
//
//	// ���뱨��  ���б���   ��������
//	Date* ptr = nullptr;     
//	//ptr->Init(2022, 2, 2); // ���б�������Ϊ this ��������
//
//	 ptr->func();            // �������� ����Ϊ��û�н����� this
//	(*ptr).func();           // �������� ��ͬ�ϣ���Ȼ˵�ǽ����� ptr�����Ǳ�����Ҳû�н����� this ָ��
//
//	return 0;
//}




class Stack
{
public:
	// ��Ա����
	void Init(int n)
	{
		a = (int*)malloc(sizeof(int) * n);
		if (nullptr == a)
		{
			perror("malloc����ռ�ʧ��");
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
	// ��Ա����
	int* a;
	int size;
	int capacity;
};

int main()
{

	return 0;
}

