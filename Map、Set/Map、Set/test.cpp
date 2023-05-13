#pragma once
#include"map.h"
#include"set.h"


void my_set_test1()
{
	SetSimulate::set<int> m;
	m.insert(100);
	m.insert(2);
	m.insert(77);


	
	for (auto s : m)
	{
		cout << s << " ";
	}
	cout << endl;

	SetSimulate::set<int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it) << " ";
		++it;
	}
	cout << endl;

	it = m.begin();
	cout << (*it) << " ";
	++it;
	cout << (*it)<<" ";
	--it;
	cout << (*it) << endl;



}

void my_map_test1()
{
	MapSimulate::map<int,int> m;
	m.insert(make_pair(1,20));
	m.insert(make_pair(6,222));
	m.insert(make_pair(3,90));



	for (auto s : m)
	{
		cout << s.second << " ";
	}
	cout << endl;

	MapSimulate::map<int, int>::reverse_iterator rit = m.rbegin();
	while (rit != m.rend())
	{
		cout <<(*rit).second<< " ";
		++rit;
	}
	cout << endl;
	
}



void my_test_map2()
{
	string arr[] = { "苹果","香蕉","梨子","西瓜","葡萄","香蕉","梨子" };
	MapSimulate::map<string, int> countMap;
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
	my_set_test1();

	my_map_test1();

	my_test_map2();
	return 0;
}