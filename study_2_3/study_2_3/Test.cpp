#include<iostream>
#include<assert.h>
using namespace std;



//class Date
//{
//public:
//
//	//Date()
//	//{
//	//	_year = 1;
//	//	_month = 2;
//	//	_day = 3;
//	//}
//
//	Date(int year=1,int month=2,int day=3)// 构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//	~Date() // 析构函数
//	{
//		cout<<"~Date()" << endl; // 用来测试是否自动调用
//	   // ......
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//int main()
//{
//	//Date d;
//	//d.Init(2023, 2, 3);
//	//d.Print();
//
//	// 但是这样写太麻烦，所以有了构造函数
//	//Date d1(2023, 2, 3);
//	//Date d2;
//	//d1.Print();
//	//d2.Print();
//
//	// 又要写无参数的构造函数，又要写有参数的构造函数，很麻烦，所以可以用缺省参数，全缺省
//	Date d1(2023, 2, 3);
//	Date d2;
//	d1.Print();
//	d2.Print();
//
//	return 0;
//}






//class Stack
//{
//public:
//
//	Stack()
//	{
//		cout << "Test Stack" << endl;
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//
//	~Stack()
//	{
//		cout<<"Test ~Stack" << endl;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//class Date
//{
//public:
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Stack test;
//
//};
//
//int main()
//{
//	// 对于构造函数和析构函数，都是默认成员函数，如果自己不写，编译器会自动创建
//	// 如果单单是下面这样写，观察不到什么，这是因为，编译器自动创建的构造函数有一些规则：
//	// 1. 对于内置类型，构造函数不会进行任何操作。 内置类型——int、double、char等等
//	// 2. 对于自定义类型，会调用该自定义类型的构造函数。()
//
//	//Date d1;
//	//Date d2;
//	//d1.Print(); // 随机值，但是这就说明编译器默认生成的构造函数没有用了吗？
//	//d2.Print();
//
//
//
//	// 对上面规则的验证——在日期类中，定义一个Stack类的成员变量
//	//通过监视窗口或者输出结果可以看到，确实调用了自定义类型的构造函数，但是为什么内置类型也初始化了？
//	// 这是因为有的编译器会自动初始化，有的不会，具体要看编译器
//	// 默认生成析构函数，对自定义类型成员，会调用他的析构函数
//	Date d1;
//
//
//	return 0;
//}







//class Stack
//{
//public:
//
//	Stack()
//	{
//		cout << "Test Stack" << endl;
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//class Date
//{
//public:
//
//	Date()
//	{
//		_year = 2023;
//	}
//
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//
//
//private:
//	// 如果内置类型和自定义类型都有，那就给内置类型缺省值
//	Stack s1;
//
//	// 这不是初始化，是缺省值，因为并没有开辟空间
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	// 对于内置类型不初始化，而自定义类型调用它的默认构造函数，感觉怪怪的，所以后来修补了这个bug
//	// C++ 11 中，允许在内置成员变量申明的时候，给出一个缺省值，类似于缺省参数
//	Date d1;
//
//	d1.Print();  // _year 是构造函数调用的，其余两个是缺省值
//
//	return 0;
//}





// 另外，无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
//注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数

//class Stack
//{
//public:
//
//	Stack()
//	{
//		cout << "Test Stack" << endl;
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	// 上下两个其实构成函数重载，但是编译器在寻找默认构造函数的时候，认为这两个都是，所以会有错误，不知道用哪一个
//	Stack(int* b=nullptr,int size=0,int capacity=4)
//	{
//		cout << "Test Stack" << endl;
//		_a = b;
//		_size = size;
//		_capacity = capacity;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//int main()
//{
//	// 像这样是无法编译通过的，因为不知道找哪个默认构造函数
//	Stack s1;
//
//	return 0;
//}






//class Stack
//{
//public:
//
//	Stack()
//	{
//		cout << "Test Stack" << endl;
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//class Date
//{
//public:
//
//	Date(int year=2023, int month=2, int day=3)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 这样子写拷贝构造函数是错误的
//	//Date(Date d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	Date(const Date& d)
//	{
//		//_s=(int*)malloc……
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	Date(Date* d)
//	{
//		_year = (*d)._year;
//		_month = (*d)._month;
//		_day = (*d)._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Stack _s;
//};
//
//// 传值传参
//void Func1(Date d)
//{
//    // 对于这种参数，要拷贝一个Date类型的 d 作为参数,由于Date类型是自定义类型，所以编译器无法直接拷贝，需要
//	// 调用该类型的拷贝构造函数
//    // 为什么呢？ 如果像以前的内置类型一样，把内存中的数据直接赋值一份，假如自定义类型里面有指针呢？
//	// 拷贝的数据和原来的数据，两个里面的指针岂不是指向一块地方，所以必须要调拷贝构造，不可以编译器自行拷贝
//	// 编译器按字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝。
//}
//
//// 传引用传参
//void Func2(const Date& d)
//{
//	//传引用就不一样了，d是实参的别名，不存在拷贝的问题
//	// 但是为了避免改变实参，要加上const
//}
//
//// 传指针传参
//void Func3(Date* d)
//{
//	// 这样子自然也是可以，但是用起来要加&，不如上面方便
//}
//
//int main()
//{
//	//Date d1;
//	//Func1(d1);
//	//Func2(d1);
//
//	Date d1;
//	Date d2 = d1;
//	Date d3(d1);
//	Date d4(&d1); // 这样不方便，而且只能以这种形式写
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();
//
//	return 0;
//}






class Date
{
public:

	Date(int year = 2023, int month = 2, int day = 3)
	{
		_year = year;
		_month = month;
		_day = day;
	}


	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
		{
			return 29;
		}
		else
		{
			return monthArray[month];
		}
	}


	// +
	Date Add(int x)
	{
		Date tmp = *this;  // 拷贝
		tmp._day += x;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			// 进位
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			++tmp._month;
			if (tmp._month == 13)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;  // 将tmp拷贝到临时变量返回
		//这样子实际上经历了两轮拷贝，消耗略大
	}

	// +=
	Date& AddEqual(int x)
	{
		_day += x;
		while (_day > GetMonthDay(_year, _month))
		{
			// 进位
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;

		// 不需要拷贝，但是数据变化是在自己身上的
	}


	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}



private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2023, 2, 3);
	Date d2 = d1.Add(100);
	Date d3 = d1.Add(150);

	d1.Print();
	d2.Print();
	d3.Print();

	d1.AddEqual(200);
	d1.Print();

	return 0;
}