#pragma once
#include"map.h"
#include"set.h"


void my_map_test1()
{
	simulate::map<int, int> m;
	m.insert(make_pair(1,100));
	m.insert(make_pair(2, 200));
	m.insert(make_pair(3, 300));

}

int main()
{
	my_map_test1();
	return 0;
}