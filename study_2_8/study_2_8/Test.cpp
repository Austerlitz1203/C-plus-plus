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
//	// ��������
//	//A a1(1);
//	//A a2 = 1; // ��ʽ����ת���� �� 1 �������������ó�ʼ���б����� A ���͵���ʱ����������ʱ���������� a2
//	//          // �����Ӻ��鷳�������еı��������Ż��ɣ�ֱ�ӵ��ó�ʼ���б�1Ϊ����
//
//	//const A& a3 = 1; // ���þͲ�������һ���ˣ���Ҫ����ʱ����������̵ġ���ʱ�������г��ԣ�����Ҫconst����
//
//
//	// һ��ʼ��֧�ֶ�������ģ������Ż�֧����
//	A b1(1, 2);
//	A b2 = { 2,2 };  // ���������д
//	const A& b3 = { 4,7 };
//
//	int x = 10;
//	double y = x;  // ��ʽ����ת��
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
//	// ����������������ͣ�ת��Ϊ�Զ������ͣ������ڳ�ʼ���б�ĺ���ǰ���� explicit ����
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
//	// ����һ���ൽ�״����˶��ٸ�����
//	// 1. ����ȫ�ֱ�����ÿ�ζ�++ . 
//	//A a(1);
//	//const A& a1 = 1;
//	// 
//	//cout << count << endl;  // count �� std�����ռ�����Ĳ��ֳ�ͻ�ˣ���C++ ��˼�룬���ǻ����֣����ò���std����
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
//	static int Size()  // ��̬��Ա������û�� this ָ�룬�����޷����ʷǾ�̬�ĳ�Ա����
//	{
//		return count;
//	}
//
//private:
//	int _a1;
//	static int count; // ���������⣬�����Ա����������ĳ����������������
//};
//
//int A::count=0;  // ��ʼ��
//
//int main()
//{
//	 //����һ���ൽ�״����˶��ٸ�����
//	 //2. static ��Ա���������䱻�����๫�У�������ÿһ������˽�е� 
//	//A a(1);
//	//const A& a1 = 1;
//	// 
//	//// ���ǣ���ʱ count��private�ģ���Ҫ���public�ſ��Ա��ⲿ���ʵ�
//	//A aa(2);
//	//cout << aa.count << endl;
//	//cout << A::count << endl;
//
//
//	// ����ķ��������Ϊ public ������ȫ�����Կ��Զ��徲̬��Ա����������������� count ��ֵ
//	A a(1);
//	const A& a1 = 1;
//	
//	cout << A::Size() << endl;
//
//	cout << A(1).Size() << endl;  // ����������������ֻ����һ��
//
//	return 0;
//}



//class A
//{
//public:
//	// B �� A ���ڲ��࣬B �൱�ڱ����������ˣ����治����ֱ��ʹ�á�
//	// 1. B �� A �� �������ơ�
//	// 2. B �������� A ����Ԫ�࣬B�������ʹ��A�ĳ�Ա�������������У�A���治����ʹ��B�ĳ�Ա��
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
//			cout << a._a << endl;  // ����ֱ�ӷ��� A ����ĳ�Ա
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
//	cout << sizeof(a) << endl;  // B ��Ȼ��A ���ڲ��࣬��������ʵ������A����Ҳ��A����ʵ������B����
//	                            // A��B �Ƕ�����
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
//	A aa1 = 1; // ����+�������� -�� �Ż�Ϊֱ�ӹ���
//	func1(aa1); // ���Ż�
//	func1(2); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
//	func1(A(3)); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
//
//	cout << "----------------------------------" << endl;
//
//	func2(aa1);  // ���Ż�
//	func2(2);    // ���Ż�
//	func2(A(3)); // ���Ż�
//
//
//	return 0;
//}



A func3()
{
	A aa;
	return aa;   // �������Ż�����Ϊ�ֿ���
}

A func4()
{
	return A();  // �����Ż�
}


//���̽��C++����ģ��
int main()
{
	func3();

	A aa1 = func3(); // ��������+��������  -- �Ż�Ϊһ����������


	cout << "****" << endl;

	A aa2;
	aa2 = func3();   // �����Ż�  �� ��Ϊ�Ǹ�ֵ����


	cout << "---------------------------" << endl;

	func4();         // ����+�������� -- �Ż�Ϊ����
	A aa3 = func4(); // ����+��������+��������  -- �Ż�Ϊ����

	return 0;
}

