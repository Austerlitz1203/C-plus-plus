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
	Date d2 = ++d1;  // �Զ������;�����ǰ��++�� ��Ϊ����++ ���۱Ƚϴ�
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
	// ������
	int i = 10;
	double d = 20.00;
	cout << i << endl;
	cout << d << endl; // ���������+��������

	Date d1(2023, 2, 7);
	d1 << cout;

	// �������������ԣ������ֲ����޸� iostream �⣬���Զ���һ��ȫ�ֵ�
	cout << d1 ;
}

void TestDate5()
{
	// ����ȡ
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