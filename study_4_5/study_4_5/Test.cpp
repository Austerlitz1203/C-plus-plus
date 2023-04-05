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

// �ó����ӡ���
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
//	// �� 32λ ������ʺϣ�64λ����£�ָ��ռ8���ֽڣ���Ҫ�ı䡣
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


// ����������ĸ����򣬵ó������� ������������Σ�
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
//	printf("ջ����%p\n", &x);
//	printf("�Ѷ���%p\n", z);
//	printf("��̬������%p\n", &y);
//	printf("����������%p\n", p);
//	printf("b�������%p\n", *((int*)&b));
//	printf("d�������%p\n", *((int*)&d));
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
//	// ��ӡ Derive ���͵Ķ�������
//	// Derive �̳��������࣬�Լ�ʵ�ֵĺ������Ƿ����ĸ��������ģ�  ���� ��һ��������ȼ̳е���Ķ������棩
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

	// ���� func1 �����Ƕ�̬�������
	// ���������������� func1 ����ַ��ͬ��
	// �����鿴��ptr1 ����֮�� ptr2���õ�ʱ��Ҫ��һ���޸� ecx �Ĺ��̣��������� this ָ�루ecx�����ţ�
	ptr1->func1();
 
	ptr2->func1();
	return 0;
}