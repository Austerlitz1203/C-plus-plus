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
//	// ����֮����  Print(const A* this)  �������� Print(A* this) 
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
//	// ���� ȡ��ַ �� constȡ��ַ һ����Զ�����Ҫ�Լ�д���������ñ���ȡ����ĵ�ַ�����Ǽ���û���������
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
//	const A a;  // �������û��const ���εĳ�Ա�����������Ȩ�޷Ŵ������� *this ���Ը�����
//	a.Print();
//	
//	A b;   // ������� Print ���൱��Ȩ����С������ν
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
//	// ���ɺ������أ�Ӧ���ڲ�ͬ������ ��Ȼ�����ṩҲ���ԣ�������
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
//	// ����Ҫ����
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
//		, bb(4)  // B ��ĳ�ʼ���б��в����ˣ�û��Ĭ�Ϲ��죨�޲���������Ҫ���Σ���������д
//	{
//		_a1++;
//		_a2--;
//	}
//private:
//	int _a1=1; // ����
//	int _a2=2;
//
//	// ���� ��const���� ��û��Ĭ�Ϲ��� ��  �Զ������ͳ�Ա
//	const int _x;
//	int& _ref;   // ����ҲҪ�ڶ���ĵط���ʼ��
//	B bb;
//};
//
//
//int main()
//{
//	const int t = 10;  // const ���Σ�ֻ�ܳ�ʼ����ʱ���ֵ
//	A aa;  // ��������嶨�壬ÿ����Աʲôʱ�����أ�
//	// ���ǵ� const ���εģ�������ȱʡֵ�������� C++ 11 ���еģ���ô֮ǰ�أ�
//	// �����ÿ����Ա������һ�������λ�ã���Ȼ �� const ���εľͲ��ô���
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

	// �������� 1  ���ֵ
	// ��Ϊ��ʼ���б����棬��ʼ��˳���� ������˳�򣬶����� ��ʼ���б������˳��
}