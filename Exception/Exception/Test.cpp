#include<iostream>
#include<string>
#include <thread>
using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//
//	try
//	{
//		cout << Division(len, time) << endl;
//	}
//	catch (char str)
//	{
//		cout << str << endl;
//	}
//
//	cout << "void Func()" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}


//class Exception
//{
//public:
//	Exception(int errid, const string& msg)
//		:_errid(errid)
//		, _errmsg(msg)
//	{}
//
//	const string& GetMsg() const
//	{
//		return _errmsg;
//	}
//
//	int GetErrid() const
//	{
//		return _errid;
//	}
//
//private:
//	int _errid;     // 错误码
//	string _errmsg; // 错误描述
//};
//
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		//Exception err(1, "除0错误");
//		//throw err;
//		//throw Exception(1, "除0错误");
//		throw 1;
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//
//	try
//	{
//		cout << Division(len, time) << endl;
//	}
//	catch (char str)
//	{
//		cout << str << endl;
//	}
//
//	//cout << "void Func()" << endl;
//}
//
////template<class T>
////void Func(T&& x)
//
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (const Exception& e)
//		{
//			cout << e.GetMsg() << endl;
//		}
//		catch (...) // 放到最后，捕获任意类型的异常，防止有一些异常没捕获，导致程序终止
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//
//	return 0;
//}



class Exception
{
public:
	Exception(int errid, const string& msg)
		:_errid(errid)
		, _errmsg(msg)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

	int GetErrid() const
	{
		return _errid;
	}

protected:
	int _errid;     // 错误码
	string _errmsg; // 错误描述
};

class SqlException : public Exception
{
public:
	SqlException(int errid, const string& msg, const string& sql)
		:Exception(errid, msg)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string msg = "SqlException：";
		msg += _errmsg;
		msg += "->";
		msg += _sql;

		return msg;
	}

protected:
	string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(id, errmsg)
	{}

	virtual string what() const
	{
		string msg = "CacheException：";
		msg += _errmsg;

		return msg;
	}
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(id, errmsg)
		, _type(type)
	{}

	virtual string what() const
	{
		string msg = "HttpServerException：";
		msg += _errmsg;
		msg += "->";
		msg += _type;

		return msg;
	}

private:
	const string _type;
};


void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException(100, "权限不足", "select * from name = '张三'");
	}

	cout << "调用成功" << endl;
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	// 模拟服务出错
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}

	CacheMgr();
}

//int main()
//{
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//
//		try
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}




double Division(int a, int b) noexcept
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}

	return (double)a / (double)b;
}

void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];

	int len, time;
	cin >> len >> time;

	try
	{
		cout << Division(len, time) << endl;
		HttpServer();
	}
	catch (...)   // 异常的重新抛出
	{
		cout << "delete []" << array << endl;
		delete[] array;

		throw;   // 捕到什么抛什么
	}

	cout << "delete []" << array << endl;
	delete[] array;
}

//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const Exception& e) // 这里捕获父类对象就可以
//	{
//		// 多态
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//
//	return 0;
//}



int div1()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}

void Func1()
{
	// 1、如果p1这里new 抛异常会如何？
	// 2、如果p2这里new 抛异常会如何？
	// 3、如果div调用这里又会抛异常会如何？
	int* p1 = new int;
	int* p2 = nullptr;
	try
	{
		p2 = new int;
	}
	catch (...)
	{
		delete p1;
		throw;
	}

	try
	{
		cout << div1() << endl;
	}
	catch (...)
	{
		delete p1;
		delete p2;

		throw;
	}

	delete p1;
	delete p2;
}

int main()
{
	try
	{
		Func1();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}