#include"vector.h"
#include<algorithm>

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


void Test3()
{
	simulate::vector<int> v1(10,5);
	simulate::vector<int>::iterator it = v1.begin();

	for (int i = 0; i < v1.size(); i++)
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto v : v1)
	{
		cout << v << " ";
	}
	cout << endl;

	std::string s("hello world!");
	simulate::vector<int> s1(s.begin(),s.end());
	for (auto c : s1)
	{
		cout << c << " ";
	}
	cout << endl;

	int arr[10] = { 5, 2, 7, 9, 10, 22, 6, 3, 1, 0 };
	simulate::vector<int> v2(arr, arr + 10);
	for (auto v : v2)
	{
		cout << v << " ";
	}
	cout << endl;

	sort(v2.begin(), v2.end());
	for (auto v : v2)
	{
		cout << v << " ";
	}
	cout << endl;

	for (auto a : arr)
	{
		cout << a << " ";
	}
	cout << endl;

	sort(arr, arr + sizeof(arr) / sizeof(int));
	for (auto a : arr)
	{
		cout << a << " ";
	}
	cout << endl;
}

// 删除vector 里面的偶数,用迭代器，会出现迭代器失效的情况
void Test4()
{
	simulate::vector<int> v1;
	v1._push_back(10);
	v1._push_back(2);
	v1._push_back(1);
	v1._push_back(4);
	v1._push_back(7);
	v1._push_back(6);

	simulate::vector<int>::iterator it = v1.begin();
	//while (it != v1.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v1.erase(it);
	//	}
	//	++it;
	//}

	// 上面会报错的本质原因就是——删除之后，后面的元素 前移，当前的指针其实相当于后移，但是下面有后移一次，相当于跳过一个元素。
	// 如果最后一个元素也是偶数，要删除，相当于跳过了 _finish 指针，无限循环
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it=v1.erase(it);
		}
		else ++it;
	}

	for (auto v : v1)
	{
		cout << v << " ";
	}
	cout << endl;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}