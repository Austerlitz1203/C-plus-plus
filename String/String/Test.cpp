#include"string.h"

using namespace std;

void Test1()
{
	simulate::string s1;
	simulate::string s2("hello");
	cout<< s1.getstr() << endl;
	cout<< s2.getstr() << endl;
}

int main()
{
	Test1();

}