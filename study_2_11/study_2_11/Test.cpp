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



// ƥ��ʹ�ã���Ҫ����
//int main()
//{
//	//int* p1 = new int;  
//	int* p1 = new int(10);// ��ʼ��
//
//	int* p3 = new int[10];// ���������
//	int* p4 = new int[10]{ 1,2,3,4,5};//�������ʼ��
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
//	int* p3 = (int*)operator new(sizeof(int));  // ��װ malloc 
//	operator delete(p3);                        // ��װ free
//
//
//	// ���� operator new ���ٿռ�   operator new -> malloc
//	// ���ù��캯��
//	A* p5 = new A;
//	
//	// �ȵ�����������
//	// �� operator delete p5ָ��Ŀռ�  operator deldte -> free
//	delete p5;
//
//
//	
//	// �ȵ��� operator new[] ��ʵ���� operator new[] Ҳ��ȥ���� operator new
//	// ����ʮ�ι��캯��
//	A* p6 = new A[10];
//
//	// һ�����ȵ���ʮ����������
//	// �ٵ��� operator delete[] 
//	delete[] p6;
//
//
//
//	// �Զ������ͣ��Զ����� ���캯�� �� ����������
//	Stack st;
//
//	// ָ�룬���������ͣ�������ù��캯���� new ��ʱ��ŵ���
//	Stack* pst = new Stack;
//	delete pst;  // ��� free(pst) ���ٵ���һ��������������ô�� Stack ��ͻ�������⡣��A �಻�ᣩ
//
//
//	// malloc ��new �ײ�ʵ�ֻ����н����������ƥ��ʹ�ÿ��������⣬����û���⡣Ҫƥ��ʹ��
//	A* p7 = new A[10];
//	//free(p7);  // ����
//	//delete p7; // ���� ����ȥ�������������Ͳ�������Ϊ���ٿռ��ʱ������ǰ������һ�����֣�������delete��ʱ��Ҫ���ü���������
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
//	new(p1)A(1); // ��λ new �����ڵ��ù��캯������ʼ����һ�����ڴ�����ʹ�á�
//
//	return 0;
//}




// ���ͱ�̡���ģ��
// 
////template<class T>
//template<typename T> // typename �� class ������
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
//	Swap(c, d);  // ת����࿴�����ε��ò�����ͬһ������
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
//	cout << Add<int>(a1, d1) << endl;    // ����Ķ��Ǳ�����ͨ��ʵ�Σ���ȷ�����ݳ�ʲô�������͵ĺ���
//	cout << Add<double>(a1, d1) << endl; // ��������ָ���ò������͡���ʾʵ����
//
//	// ��Ȼ��Ҳ��ģ��д����class
//	return 0;
//}




// ר�Ŵ��� int ���͵ļӷ�����
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
//// ͨ�üӷ�����
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
//	Add(a, b);  // ʵ�ʵ��õ�һ������������ģ��
//
//	
//	// ǿ�Ʊ�����ģ��
//	Add<int>(a, b);
//
//
//	Add(10.28, 9);  // ���������Լ�ѡ����ƥ���
//
//	return 0;
//}




// ��ģ��

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
//	Stack st1; // �洢 int ���͵�����
//	Stack st2; // �洢 double ���͵����ݣ�������
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
	// ֻ����ʾʵ����
	Stack<int> st1; // �洢 int ���͵�����
	Stack<double> st2; // �洢 double ���͵�����

}