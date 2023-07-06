#include<iostream>

using namespace std;


// 一个类，禁止拷贝
class CopyBan
{
	//  C++ 11 支持 =delete 表示让编译器删掉该默认成员函数
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;


private:
	// C++ 98 的做法，是将拷贝和赋值重载设为私有
	//CopyBan(const CopyBan&);
	//CopyBan& operator=(const CopyBan&);
	//...
};




// 一个类，只能在堆上创建
// 思路1

//class HeapOnly
//{
//public:
//	void Destroy()
//	{
//		delete this;  // delete 是调用析构，但是这是在类内部，所以可以调用
//	}
//
//private:
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//
//	int _x;
//};
//
//int main()
//{
//	//HeapOnly ho1;  
//	//static HeapOnly ho2;  // 这两个都不行
//	HeapOnly* pho3 = new HeapOnly;
//	pho3->Destroy();
//
//	return 0;
//}


// 思路2
class HeapOnly
{
public:

	// 将构造私有，然后设置一个静态方法（不用对象，可以直接调），这个方法内部在堆上创建对象，返回指针。
	static HeapOnly* CreateObj(int x = 0)
	{
		HeapOnly* p = new HeapOnly(x);
		return p;
	}

private:
	HeapOnly(int x = 0)
		:_x(x)
	{}

	// 私有拷贝构造和赋值重载，也是为了保证不在栈上创建对象
	HeapOnly(const HeapOnly& hp) = delete;
	HeapOnly& operator=(const HeapOnly& hp) = delete;

	int _x;
};


//int main()
//{
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//	//HeapOnly* hp3 = new HeapOnly;
//
//	HeapOnly* hp4 = HeapOnly::CreateObj();
//	//HeapOnly hp5(*p4);
//
//	return 0;
//}




// 一个类，只在栈上创建对象
class StackOnly
{
public:

	// 智能通过一个静态方法常见对象，该方法内部就是在栈上面创建对象
	static StackOnly CreateObj(int x = 0)
	{
		return StackOnly(x);
	}

	StackOnly(StackOnly&& st)
		:_x(st._x)
	{}

private:
	StackOnly(int x = 0)
		:_x(x)
	{}

	StackOnly(const StackOnly& st) = delete;

	int _x;
};



int main()
{
	//StackOnly st1;
	//static StackOnly st2;
	//StackOnly* st3 = new StackOnly;

	StackOnly st1 = StackOnly::CreateObj(1);
	//static StackOnly st2 = st1;
	static StackOnly st2 = move(st1);  // 依旧无法完全避免

	return 0;
}



