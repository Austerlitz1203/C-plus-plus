#include"Date.h"



void TestDate()
{
	Date d1(2023, 2, 4);
	d1 += 5000;
	d1.Print();

}

void TestDate1()
{
	Date d1(2023, 2, 7);
	d1 -= 100;
	d1.Print();

}

void TestDate2()
{
	Date d1(2023, 2, 7);
	Date d2 = ++d1;  // 自定义类型尽量用前置++， 因为后置++ 代价比较大
	Date d3(2023, 2, 7);
	Date d4 = d3++;
	d2.Print();
	d4.Print();

}
void TestDate3()
{
	Date d1(2023, 2, 7);
	Date d2(2023, 4, 5);
	cout << (d2 - d1) << endl;
}

void TestDate4()
{
	// 流插入
	int i = 10;
	double d = 20.00;
	cout << i << endl;
	cout << d << endl; // 运算符重载+函数重载

	Date d1(2023, 2, 7);
	d1 << cout;

	// 上面那样不可以，但是又不能修改 iostream 库，所以定义一个全局的
	cout << d1 ;
}

void TestDate5()
{
	// 流提取
	Date d1;
	cin >> d1;
	cout << d1;

}

int main()
{
	//TestDate();
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	TestDate5();
	return 0;
}