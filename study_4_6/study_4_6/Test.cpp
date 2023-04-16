#include <iostream>
using namespace std;


//class A
//{
//public:
//	virtual A()
//	{}
//
//	virtual A(const A& aa)
//	{}
//
//	virtual A& operator=(const A& aa)
//	{
//		return *this;
//	}
//
//	inline virtual void func1()
//	{
//
//	}
//
//	// 报错
//	/*static virtual void func2()
//	{}*/
//};
//
//int main()
//{
//	A aa;
//	aa.func1();
//
//	return 0;
//}



class A
{
public:
	virtual void func1()
	{
		cout << "A::func1" << endl;
	}

	void func2()
	{
		cout << "func2" << endl;
	}
};

class B : public A
{
public:
	virtual void func1()
	{
		cout << "B::func1" << endl;
	}

	void func2()
	{
		cout << "func2" << endl;
	}
};

//int main()
//{
//	A aa;
//	aa.func1();
//	aa.func2();
//
//	// 多态调用  -- 去虚表中找虚函数地址
//	A* ptr = &aa;
//	ptr->func1();
//
//	ptr = new B;
//	ptr->func1();
//
//	return 0;
//}

#include"BSTree.h"

void TestBSTree()
{
	BSTree<int> t;
	int arr[] = { 3,5,7,4,1,12,8,9,0 };
	for (int i = 0; i < 9; i++)
	{
		t.InsertR(arr[i]);
	}

	t.Inorder();
	cout << t.FIndR(1) << endl;
	cout << t.FIndR(10) << endl;
	cout<<t.EraseR(0);
	cout<<t.EraseR(8);
	cout<<t.EraseR(3);

	cout << endl;
	t.Inorder();
}

int main()
{
	TestBSTree();
	return 0;
}