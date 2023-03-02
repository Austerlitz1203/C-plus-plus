#include"string.h"

using namespace std;

void Test1()
{
	simulate::string s1;
	simulate::string s2("hello");
	cout<< s1.c_str() << endl;
	cout<< s2.c_str() << endl;
}

void Test2()
{
	simulate::string s1("Hello String!");
	cout << s1[4] << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;

	simulate::string s2("who am i");
	cout << (s1 <= s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 > s2) << endl;

	for (auto ch : s2) // ��Χ for ��ʵ�����Լ�д�� begin() ���Ϳ������ˡ�����ע�⣬������������begin��Сд
	{
		cout << ch << " ";
	}
}

void Test3()
{
	simulate::string s1("Hello");
	s1.pushback(' ');
	s1.pushback('W');
	s1.pushback('o');
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	s1.append("rld");
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
}

void Test4()
{
	simulate::string s1;
	s1 += 'H';
	s1 += 'l';
	s1 += "lo";
	cout << s1.c_str() << endl;

	s1.insert(2, 'a');
	s1.insert(0, 'l');
	s1.insert(s1.size(), 'e');
	cout << s1.c_str() << endl;

	simulate::string s2("Helrld!");
	s2.insert(3, "lo wo");
	cout << s2.c_str() << endl;

	simulate::string s3("where");
	s3.insert(0, "who ");
	s3.insert(s3.size(), " are you");
	cout << s3.c_str() << endl;

	simulate::string s4("This is an example sentence");
	s4.erase(10, 8);
	s4.erase(9, 1);
	s4.erase(0, 5);
	cout << s4.size() << endl;
	s4.erase(s4.size(), 1);
	cout << s4.c_str() << endl;
}


void Test5()
{
	simulate::string s1("xxxxxxx");
	s1.resize(2, 'y');
	cout << s1.c_str() << endl;
	s1.resize(10, 'z');
	cout << s1.c_str() << endl;
}

void Test6()
{
	simulate::string s1("Hello World!");
	cout << s1.find('H') << endl;
	cout << s1.find("orld") << endl;


	
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
}