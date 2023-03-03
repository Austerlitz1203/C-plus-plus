#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

void Test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (int i = 0; i < v.size(); i++)  // ��һ�ֱ�����ʽ���±�
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (auto s : v) // �ڶ��ֱ�����ʽ����Χfor
	{
		cout << s << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();  // �����֣�������
	for (int i = 0; i < v.size(); i++)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	for (int i = 0; i < v.size(); i++)
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void Test2()
{
	vector<int> v(10, 5);  // ����� 10 ��5
	auto it = v.begin(); // ��Ϥ�˿���ֱ���� auto
	for (int i = 0; i < v.size(); i++)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> v2(v.begin(), v.end());
	for (auto f : v2)
	{
		cout << f << " ";
	}
	cout << endl;

	string s("hello world!");// Ҳ�����ǲ�ͬ���͵� begin��end����һ��Ҫ vector��
	vector<int> v3(s.begin(), s.end()); // ��������������������ͺ� begin��end ָ�������Ҫƥ��
	for (auto f : v3)
	{
		cout << f << " ";
	}
	cout << endl;
}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	const size_t n = 100000;
	//v.reserve(100);   

	size_t begin = clock();
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	size_t end = clock();

	cout << "����ʱ���ǣ�" << end - begin << endl;
}


void Test3()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(9);
	v.push_back(5);
	v.push_back(3);

	// insertҪ��ϵ�����ʹ��
	// find ��һ��ģ�庯���������������κ���
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		v.insert(pos, 20);
	}
	for (auto s : v)
	{
		cout << s << " ";
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 9);
	if (pos != v.end())
	{
		v.erase(pos);
	}
	for (auto s : v)
	{
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	//Test1();
	//Test2();
	//TestVectorExpand();
	Test3();

	return 0;
}