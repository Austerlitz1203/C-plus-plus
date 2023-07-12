#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<string>
#include<set>
#include<functional>
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


//int main()
//{
//	Singleton::GetInstance();
//	Singleton::GetInstance();
//
//	return 0;
//}




// C++ 的类型转换

void Test()
{
	int i = 1;
	// 隐式类型转换
	double d = i;
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// 显示的强制类型转换
	int address = (int)p;

	printf("%x, %d\n", p, address);
}


// 如下，以前写代码往往面临一些问题，pos == 0时就会有错误，也是因为类型转换
//void insert(size_t pos, char ch)
//{
//	int end = _size;
//	while (end >= pos)
//	{
//		//...
//		--end;
//	}
//}


//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// 这里使用static_cast会报错，应该使用reinterpret_cast
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//
//	return 0;
//}


//void main()
//{
//	volatile const int a = 2;
//	//int* p = const_cast<int*>(&a);
//	int* p = (int*)&a;
//
//	*p = 3;
//
//
//	// 有没有修改到a ，是否要加上 volatile
//	cout << a << endl;
//	cout << *p << endl;
//}


class A
{
public:
	virtual void f(){}
};

class B : public A
{};



void fun(A* pa, const string& s)
{
	cout <<"pa指向"<<s << endl;

	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = (B*)pa;			   // 不安全的
	B* pb2 = dynamic_cast<B*>(pa); // 安全的

	cout << "[强制转换]pb1:" << pb1 << endl;
	cout << "[dynamic_cast转换]pb2:" << pb2 << endl << endl;
}

//int main()
//{
//	A a;
//	B b;
//	fun(&a, "指向父类对象");
//	fun(&b, "指向子类对象");
//
//	cout << typeid(a).name() << endl;
//	decltype(a) aa;
//
//	function<bool(int,int)> gt = [](int x, int y){return x > y; };
//	set<int, decltype(gt)> s;
//
//	return 0;
//}






// C++ 的 IO流


//int main()
//{
//	string str;
//	// ctrl+c 信号强杀进程
//	// ctrl+z + 换行 流对象提取到结束标志
//	// istream& operator>> (istream& is, string& str);
//
//	while (cin>>str)
//	{
//		cout << str << endl;
//	}
//
//	// 凭什么istream的cin对象可以转bool
//	// 凭什么string的str对象可以转bool
//	// 因为istream的这个-》explicit operator bool() const;
//	// 支持自定义类型转内置类型
//	while (str)  // str 不可以直接转为 bool 
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//	operator int() const
//	{
//		return _a;
//	}
//
//private:
//	int _a;
//};

//int main()
//{
//	// 内置类型转换成自定义类型
//	//A aa1 = static_cast<A>(1);
//	A aa1 = 1;  // 因为单参数的构造函数
//
//	// 自定义类转换成内置类型
//	int x = aa1;  // 因为 operator int()
//
//
//	return 0;
//}



class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool() const
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}

private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;

	return out;
}


//int main()
//{
//	// 自定义类型则需要我们自己重载<< 和 >>
//	Date d(2022, 4, 10);
//	cout << d;
//
//	while (d)  // str 不可以 ，Date 可以，这是因为 Date 的 operator bool()  
//	{
//		cin >> d;
//		cout << d;
//	}
//
//	return 0;
//}




#include<fstream>

//int main()
//{
//	std::ofstream ofs("test.txt", ofstream::out | ofstream::app);
//	ofs << "hello world";
//	ofs << "hello world";
//
//	return 0;
//}


struct ServerInfo
{
	char _address[32];
	//string _address;

	int _port;
	Date _date;
};

struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	// 二进制读写，读写对象中，不能有string
	// 因为原封不动地拷贝，拷贝的是 string 的成员变量，里面是指针，除了作用域会销毁
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((char*)&info, sizeof(info));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ofstream::in | ofstream::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	// 文本读写 C++文本读写更简单
	// 文本读写本质，内存中任何类型都是转成字符串在写
	// c语言文本读写很不方便，因为要不断转字符串
	// c++封装了以后就有很大的优势
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " ";
		ofs << info._port << endl;
		ofs << info._date << endl;
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address;
		ifs >> info._port;
		ifs >> info._date;
	}

private:
	string _filename; // 配置文件
};


//int main()
//{
//	ServerInfo winfo = { "192.168.11.189xxxxxxxxxxxxx",88,{2023,7,12} };
//	string str;
//	cin >> str;
//	if (str == "二进制读")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadBin(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout<<rinfo._date << endl;
//	}
//	else if (str == "二进制写")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);
//	}
//	else if (str == "文本读")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadText(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	else if (str == "文本写")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteText(winfo);
//	}
//
//	return 0;
//}




#include <sstream>

//int main()
//{
//	//ostringstream oss;
//	stringstream oss;
//	oss << 100 << " ";
//	oss << 11.22 << " ";
//	oss << "hello";
//
//	string str = oss.str();
//	cout << str << endl;
//
//	//istringstream iss(str);
//	stringstream iss(str);
//	int i;
//	double d;
//	string s;
//	iss >> i >> d >> s;
//	cout << i << endl;
//	cout << d << endl;
//	cout << s << endl;
//
//	return 0;
//}


// 序列化和反序列化
struct ChatInfo
{
	string _name; // 名字
	int _id;      // id
	Date _date;   // 时间
	string _msg;  // 聊天信息
};

int main()
{
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
	stringstream oss;
	oss << winfo._name << " ";
	oss << winfo._id << " ";
	oss << winfo._date << " ";
	oss << winfo._msg;
	string str = oss.str();
	cout << str << endl;

	stringstream iss(str);
	ChatInfo rinfo;
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "姓名：" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}