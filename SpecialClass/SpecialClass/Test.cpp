#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<string>
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

	// 只能通过一个静态方法常见对象，该方法内部就是在栈上面创建对象
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



//int main()
//{
//	//StackOnly st1;
//	//static StackOnly st2;
//	//StackOnly* st3 = new StackOnly;
//
//	StackOnly st1 = StackOnly::CreateObj(1);
//	//static StackOnly st2 = st1;
//	static StackOnly st2 = move(st1);  // 依旧无法完全避免
//
//	return 0;
//}



// 单例模式

// 饿汉模式：一开始(main函数之前)就创建对象

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _ins;
//	}
//
//	void Add(const string& str)
//	{
//		_mtx.lock();
//		_v.push_back(str);
//		_mtx.unlock();
//	}
//
//	void Print()
//	{
//		_mtx.lock();
//
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//
//		_mtx.unlock();
//	}
//
//private:
//	// 限制类外面随意创建对象
//	Singleton()
//	{}
//
//    //防拷贝
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//private:
//	mutex _mtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//};
//
//Singleton* Singleton::_ins = new Singleton;







// 懒汉模式：第一次访问实例对象时创建

// 分析：懒汉和饿汉的优缺点
// 饿汉的缺点：
// 1、如果单例对象初始化很慢（如初始化动作多，还会伴随一些IO行为，如读取配置文件等），main函数之前就要申请，第一，暂时不需要使用确占用资源，第二程序启动会受影响。
// 2、如果两个单例都是饿汉，并且有依赖关系，要求单例1再创建，单例2再创建，饿汉无法控制顺序，懒汉才可以。

// 饿汉的优点：
// 简单（相对懒汉而言）

// 懒汉完美的解决了上面饿汉的问题，但是就是相对复杂一点点

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		// 双检查加锁
//		if (_ins == nullptr)  // 提高效率
//		{
//			_imtx.lock();
//
//			if (_ins == nullptr)  // 线程安全
//			{
//				_ins = new Singleton;
//			}
//
//			_imtx.unlock();
//		}
//
//		return _ins;
//	}
//
//	// 一般全局都要使用单例对象，所以单例对象一般不需要显示释放
//	// 有些特殊场景，想显示释放一下
//	static void DelInstance()
//	{
//		_imtx.lock();
//		if (_ins)
//		{
//			delete _ins;
//			_ins = nullptr;
//		}
//		_imtx.unlock();
//	}
//
//	// 内部类：单例对象回收
//	class GC
//	{
//	public:
//		~GC()
//		{
//			DelInstance();
//		}
//	};
//
//	static GC _gc;
//
//	void Add(const string& str)
//	{
//		_vmtx.lock();
//
//		_v.push_back(str);
//
//		_vmtx.unlock();
//	}
//
//	void Print()
//	{
//		_vmtx.lock();
//
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//
//		_vmtx.unlock();
//	}
//
//	~Singleton()
//	{
//		// 持久化
//		// 比如要求程序结束时，将数据写到文件，单例对象析构时持久化就比较好
//	}
//
//private:
//	// 限制类外面随意创建对象
//	Singleton()
//	{}
//
//	// 防拷贝
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//private:
//	mutex _vmtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//	static mutex _imtx;
//};
//
//Singleton* Singleton::_ins = nullptr;
//mutex Singleton::_imtx;
//
//Singleton::GC Singleton::_gc;
//
//int main()
//{
//	srand(time(0));
//
//	int n = 30;
//	thread t1([n](){
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t1线程:" + to_string(rand()));
//		}
//	});
//
//	thread t2([n](){
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t2线程:" + to_string(rand()));
//		}
//	});
//	
//	t1.join();
//	t2.join();
//
//	Singleton::GetInstance()->Print();
//
//	Singleton::GetInstance();
//
//	//Singleton s(*Singleton::GetInstance());
//
//	return 0;
//}




// 另一种创建单例模式的办法
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// C++11之前，这里不能保证初始化静态对象的线程安全问题
		// C++11之后，这里可以保证初始化静态对象的线程安全问题
		static Singleton inst;

		return &inst;
	}

	void Add(const string& str)
	{
		_vmtx.lock();

		_v.push_back(str);

		_vmtx.unlock();
	}

	void Print()
	{
		_vmtx.lock();

		for (auto& e : _v)
		{
			cout << e << endl;
		}
		cout << endl;

		_vmtx.unlock();
	}

	~Singleton()
	{
		// 持久化
		// 比如要求程序结束时，将数据写到文件，单例对象析构时持久化就比较好
	}

private:
	// 限制类外面随意创建对象
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	// 防拷贝
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(const Singleton& s) = delete;

private:
	mutex _vmtx;
	vector<string> _v;
};


int main()
{
	Singleton::GetInstance();
	Singleton::GetInstance();

	return 0;
}