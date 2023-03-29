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
//	// ���ݵ��ԣ��鿴�ڴ棬����������̳е��ص�
//
//	D d1,d2,d3; // ���������B��C�����ж�����ͬһ��ָ�루�ڴ洰�ڲ鿴��
//
//
//	B b = d1;
//	C c = d1;
//  
//  // ͨ������࣬���Կ����䷽����һ��һ���ģ�Ѱ��ƫ���� 
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
	M _m;  // ��� ������ʹ�� public ��Ա������ʹ�� protected��private ��Ա
	       // M �Ķ� protected��private ��Ա������Ӱ�� N������Ǽ̳У���Ӱ��
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


class D : public B, public C  // �ȼ̳� B
{
public:
	D(const char* s1,const char* s2, const char* s3, const char* s4)
		:B(s1, s2)  // ��ʼ���б��ʼ����˳��ֻ�ͱ�������˳���й�
		, A(s1)     // �ڼ̳�������Ǻͱ��̳е��Ⱥ�˳��
		, C(s1, s3) // ���ȣ� A �����ȱ��̳еģ�Ȼ�����D���ȼ̳�B���ټ̳�C
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