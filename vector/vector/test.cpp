#include"vector.h"

void Test1()
{
	simulate::vector<int> v1;
	v1._push_back(10);
	v1._push_back(5);
	v1._push_back(4);
	simulate::vector<int>::iterator it = v1.begin();
	for (int i = 0; i < v1.size(); i++)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
	v1._pop_back();
	v1._pop_back();
	for (auto v : v1)
	{
		cout << v << " ";
	}
	cout << endl;
}


void Test2()
{
	int x1 = int();
	int x2 = int(1);
	//int& x3 = int* (10); // int* 是不允许的

}

int main()
{
	Test1();
	Test2();
	return 0;
}