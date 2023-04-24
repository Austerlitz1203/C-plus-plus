#include<iostream>
#include<set>
#include<map>

using namespace std;


void set_test1()
{
	set<int> s;
	s.insert(10);
	s.insert(1);
	s.insert(4);
	s.insert(0);
	s.insert(2);
	s.insert(8);

	for (auto a : s)
	{
		cout << a << " ";
	}
	cout << endl;

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 2;  // key ֵ�����޸�
		cout << *it << " ";
		++it;
	}
}


void set_test2()
{
	// ���� + ȥ��
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	int x;
	while (cin >> x)
	{
		/*	auto ret = s1.find(x);
			if (ret != s1.end())
			{
				cout << "��" << endl;
			}
			else
			{
				cout << "����" << endl;
			}*/


		if (s1.count(x))
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
	}
}



void set_test3()
{
	// ����
	multiset<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	s1.insert(2);

	multiset<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// �������������޸�key�����ܻ��ƻ������Ĺ���
		//*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// ���key��find����ĵ�һ��key
	auto ret = s1.find(1);
	while (ret != s1.end() && *ret == 1)
	{
		cout << *ret << " ";
		++ret;
	}
	cout << endl;

	cout << s1.count(1) << endl;
	cout << s1.count(2) << endl;
}



void map_test1()
{
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));  // make_pair() ����
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));

	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first << ":" << (*dit).second << endl;
		++dit;
	}
	cout << endl;
}



void map_test2()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));
	dict.insert(make_pair("string", "(�ַ���)")); // ����ʧ��

	dict["left"];			// ����
	dict["right"] = "�ұ�"; // ����+�޸�
	dict["string"] = "(�ַ���)"; // �޸�
	cout << dict["string"] << endl; // ����
	cout << dict["string"] << endl; // ����


	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << ":" << dit->second << endl;

		++dit;
	}
	cout << endl;
}


void map_test3()
{
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶", "��" };
	map<string, int> countMap;
	//for (auto& e : arr)
	//{
	//	auto ret = countMap.find(e);
	//	if (ret == countMap.end())
	//	{
	//		countMap.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}

	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}


int main()
{
	//set_test1();
	//set_test2();
	//set_test3();

	//map_test1();
	//map_test2();
	map_test3();
	return 0;
}