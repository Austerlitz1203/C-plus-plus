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
//	Date(int year=1,int month=2,int day=3)// ���캯��
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
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//
//	~Date() // ��������
//	{
//		cout<<"~Date()" << endl; // ���������Ƿ��Զ�����
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
//	// ��������д̫�鷳���������˹��캯��
//	//Date d1(2023, 2, 3);
//	//Date d2;
//	//d1.Print();
//	//d2.Print();
//
//	// ��Ҫд�޲����Ĺ��캯������Ҫд�в����Ĺ��캯�������鷳�����Կ�����ȱʡ������ȫȱʡ
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
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
//	// ���ڹ��캯������������������Ĭ�ϳ�Ա����������Լ���д�����������Զ�����
//	// �����������������д���۲첻��ʲô��������Ϊ���������Զ������Ĺ��캯����һЩ����
//	// 1. �����������ͣ����캯����������κβ����� �������͡���int��double��char�ȵ�
//	// 2. �����Զ������ͣ�����ø��Զ������͵Ĺ��캯����()
//
//	//Date d1;
//	//Date d2;
//	//d1.Print(); // ���ֵ���������˵��������Ĭ�����ɵĹ��캯��û��������
//	//d2.Print();
//
//
//
//	// ������������֤�������������У�����һ��Stack��ĳ�Ա����
//	//ͨ�����Ӵ��ڻ������������Կ�����ȷʵ�������Զ������͵Ĺ��캯��������Ϊʲô��������Ҳ��ʼ���ˣ�
//	// ������Ϊ�еı��������Զ���ʼ�����еĲ��ᣬ����Ҫ��������
//	// Ĭ�������������������Զ������ͳ�Ա�������������������
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
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//
//
//
//private:
//	// ����������ͺ��Զ������Ͷ��У��Ǿ͸���������ȱʡֵ
//	Stack s1;
//
//	// �ⲻ�ǳ�ʼ������ȱʡֵ����Ϊ��û�п��ٿռ�
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	// �����������Ͳ���ʼ�������Զ������͵�������Ĭ�Ϲ��캯�����о��ֵֹģ����Ժ����޲������bug
//	// C++ 11 �У����������ó�Ա����������ʱ�򣬸���һ��ȱʡֵ��������ȱʡ����
//	Date d1;
//
//	d1.Print();  // _year �ǹ��캯�����õģ�����������ȱʡֵ
//
//	return 0;
//}





// ���⣬�޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ����
//ע�⣺�޲ι��캯����ȫȱʡ���캯��������ûд������Ĭ�����ɵĹ��캯������������Ϊ��Ĭ�Ϲ��캯��

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
//	// ����������ʵ���ɺ������أ����Ǳ�������Ѱ��Ĭ�Ϲ��캯����ʱ����Ϊ���������ǣ����Ի��д��󣬲�֪������һ��
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
//	// ���������޷�����ͨ���ģ���Ϊ��֪�����ĸ�Ĭ�Ϲ��캯��
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
//	// ������д�������캯���Ǵ����
//	//Date(Date d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	Date(const Date& d)
//	{
//		//_s=(int*)malloc����
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
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
//// ��ֵ����
//void Func1(Date d)
//{
//    // �������ֲ�����Ҫ����һ��Date���͵� d ��Ϊ����,����Date�������Զ������ͣ����Ա������޷�ֱ�ӿ�������Ҫ
//	// ���ø����͵Ŀ������캯��
//    // Ϊʲô�أ� �������ǰ����������һ�������ڴ��е�����ֱ�Ӹ�ֵһ�ݣ������Զ�������������ָ���أ�
//	// ���������ݺ�ԭ�������ݣ����������ָ������ָ��һ��ط������Ա���Ҫ���������죬�����Ա��������п���
//	// ���������ֽ�����ɿ��������ֿ�������ǳ����������ֵ������
//}
//
//// �����ô���
//void Func2(const Date& d)
//{
//	//�����þͲ�һ���ˣ�d��ʵ�εı����������ڿ���������
//	// ����Ϊ�˱���ı�ʵ�Σ�Ҫ����const
//}
//
//// ��ָ�봫��
//void Func3(Date* d)
//{
//	// ��������ȻҲ�ǿ��ԣ�����������Ҫ��&���������淽��
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
//	Date d4(&d1); // ���������㣬����ֻ����������ʽд
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
		Date tmp = *this;  // ����
		tmp._day += x;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			// ��λ
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			++tmp._month;
			if (tmp._month == 13)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;  // ��tmp��������ʱ��������
		//������ʵ���Ͼ��������ֿ����������Դ�
	}

	// +=
	Date& AddEqual(int x)
	{
		_day += x;
		while (_day > GetMonthDay(_year, _month))
		{
			// ��λ
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;

		// ����Ҫ�������������ݱ仯�����Լ����ϵ�
	}


	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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