#include<iostream>
#include<string>
using namespace std;

//����/����
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
////protected:   // ������ɼ���   ֻ�ܷ�����
//private:  // ������Ҳ�ǲ��ɼ�(������)  
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// ���ɼ�
//		// cout <<_name << endl;
//		cout << "void func()" << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};

//int main()
//{
//	/*Student s;
//	s.Print();*/
//
//	double d = 1.1;
//	int i = d;  // ��ʽ����ת��
//	const int& ri = d;
//
//	Student s;
//	Person p = s;  // ��Ƭ�����߽��и
//	Person& rp = s;
//	Person* ptrp = &s;
//
//
//	return 0;
//}







//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 		// ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		// �޶���
//		cout << Person::_num << endl;
//		// ���޶��򣬾ͽ����ʱ����е�ͬ����Ա
//		cout << _num << endl;
//	}
//
//protected:
//	// ����͸�������ͬ����Ա�������Ա�����θ����ͬ����Ա��ֱ�ӷ��ʣ�������������أ�Ҳ���ض��塣
//	int _num = 999; // ѧ��
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
////����fun�������أ���Ϊ��ͬ����
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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	// һ����˵������Ĺ��졢��������Ĭ�ϵľͿ���
//	// �����������������ָ��ָ��ĳ�����򣬾ͱ�����Լ�д
//	// ���ǣ���ʹ���Լ�д��Ҳ����Ҫ���ø���Ĺ���
//	Student(const char* name, int num)
//		:Person(name)
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	// û�е��ø���Ĺ��죬���ǻ��Զ����ø����Ĭ�Ϲ���
//	//Student(const char* name, int num)
//	//	: _num(num)
//	//{
//	//	cout << "Student()" << endl;
//	//}
//
//
//	Student(const Student& s)
//		:Person(s)  // ��Ƭ
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
//	// ���������ᱻ�����destructor
//	~Student()
//	{
//		//Person::~Person();
//
//		cout << "~Student()" << endl;
//	}
//	// ���������������ʱ�����Զ����ø���������������֤����������������
//
//protected:
//	int _num; //ѧ��
//};
//
//int main()
//{
//	Student s1("����", 18);
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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//	// ��Ԫ�������ܱ�����̳У����������������һ����Ԫ
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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
//	string _name; // ����
//public:
//	// static ���εģ�ֻ��һ�ݣ�������Է��ʣ��������ಢ�����Լ�ӵ��static���εĳ�Ա
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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




// ���ܱ��̳е��࣬private���ι��������������
//class A
//{
//public:
//  // ����Ҫ����A�Ķ�������������������� 
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
	string _name; // ����
	//int _age;
	//int _tel;
	//int _address;
};

// ��������Եķ�������̳�
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};

class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};

void main()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	a._name = "����";

	// �������� �� ������
	// ��Ȼ����ͨ��������޶�������������Ե����⣬����ȴ��������������������
	a.Student::_name = "С��";
	a.Teacher::_name = "����";
}
