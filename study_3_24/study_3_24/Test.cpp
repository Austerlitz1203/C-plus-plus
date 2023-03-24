#include<iostream>
#include<string>
using namespace std;

//基类/父类
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
////protected:   // 在子类可见的   只能防外面
//private:  // 在子类也是不可见(不能用)  
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// 不可见
//		// cout <<_name << endl;
//		cout << "void func()" << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};

//int main()
//{
//	/*Student s;
//	s.Print();*/
//
//	double d = 1.1;
//	int i = d;  // 隐式类型转换
//	const int& ri = d;
//
//	Student s;
//	Person p = s;  // 切片（或者叫切割）
//	Person& rp = s;
//	Person* ptrp = &s;
//
//
//	return 0;
//}







//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 		// 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		// 限定域
//		cout << Person::_num << endl;
//		// 不限定域，就近访问本类中的同名成员
//		cout << _num << endl;
//	}
//
//protected:
//	// 子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。
//	int _num = 999; // 学号
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//
////两个fun构成隐藏，因为是同名的
//void Test()
//{
//	/*B b;
//	b.fun(10);*/
//
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	Test();
//
//	return 0;
//}





//class Person
//{
//public:
//
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	// 一般来说，子类的构造、析构调用默认的就可以
//	// 但是如果子类里面由指针指向某块区域，就必须得自己写
//	// 但是，即使是自己写，也必须要调用父类的构造
//	Student(const char* name, int num)
//		:Person(name)
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	// 没有调用父类的构造，但是会自动调用父类的默认构造
//	//Student(const char* name, int num)
//	//	: _num(num)
//	//{
//	//	cout << "Student()" << endl;
//	//}
//
//
//	Student(const Student& s)
//		:Person(s)  // 切片
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//
//
//		return *this;
//	}
//
//	// 析构函数会被处理成destructor
//	~Student()
//	{
//		//Person::~Person();
//
//		cout << "~Student()" << endl;
//	}
//	// 子类析构函数完成时，会自定调用父类析构函数，保证先析构子再析构父
//
//protected:
//	int _num; //学号
//};
//
//int main()
//{
//	Student s1("张三", 18);
//
//	Student s2(s1);
//
//	Person p = s1;
//
//	s1 = s2;
//
//
//	return 0;
//}




//class Student;
//
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//	// 友元函数不能被子类继承，但是子类可以声明一下友元
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}





//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	// static 修饰的，只有一份，子类可以访问，但是子类并不是自己拥有static修饰的成员
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	//cout << &(p._name) << endl;
//	//cout << &(s._name) << endl;
//
//	//cout << &(p._count) << endl;
//	//cout << &(s._count) << endl;
//
//	Graduate g1;
//	Graduate g2;
//
//	cout << Person::_count << endl;
//	cout << Graduate::_count << endl;
//
//	return 0;
//}




// 不能被继承的类，private修饰构造或者析构即可
//class A
//{
//public:
//  // 但是要构造A的对象，所以这里有这个函数 
//	static A CreateObj()
//	{
//		return A();
//	}
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	A::CreateObj();
//
//	//B bb;
//
//	return 0;
//}




class Person
{
public:
	string _name; // 姓名
	//int _age;
	//int _tel;
	//int _address;
};

// 解决二义性的方法，虚继承
class Student : virtual public Person
{
protected:
	int _num; //学号
};

class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};

void main()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	a._name = "张三";

	// 数据冗余 和 二义性
	// 虽然可以通过域访问限定符来解决二义性的问题，但是却解决不了数据冗余的问题
	a.Student::_name = "小张";
	a.Teacher::_name = "老张";
}
