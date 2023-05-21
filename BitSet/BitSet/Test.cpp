#include"bitset.h"
#include<iostream>
using namespace std;

void test_bitset1()
{
	bitset<100> bs;
	bs.set(10);
	bs.set(11);
	bs.set(15);
	cout << bs.test(10) << endl;
	cout << bs.test(15) << endl;

	bs.reset(10);

	cout << bs.test(10) << endl;
	cout << bs.test(15) << endl;

	bs.reset(10);
	bs.reset(15);

	cout << bs.test(10) << endl;
	cout << bs.test(15) << endl;
}

void test_bitset2()
{
	//bitset<-1> bs1;
	bitset<0xFFFFFFFF> bs1;
}


void test_bloomfilter1()
{
	BloomFilter<100> bs;
	bs.set("sort");
	bs.set("bloom");
	bs.set("hello world hello bit");
	bs.set("test");
	bs.set("etst");
	bs.set("estt");

	cout << bs.test("sort") << endl;
	cout << bs.test("bloom") << endl;
	cout << bs.test("hello world hello bit") << endl;
	cout << bs.test("etst") << endl;
	cout << bs.test("test") << endl;
	cout << bs.test("estt") << endl;

	cout << bs.test("ssort") << endl;
	cout << bs.test("tors") << endl;
	cout << bs.test("ttes") << endl;
}


void test_bloomfilter2()
{
	srand(time(0));
	const size_t N = 10000;
	BloomFilter<N> bf;

	std::vector<std::string> v1;
	std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2跟v1是相似字符串集，但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		//string url = "https://www.cctalk.com/m/statistics/live/16845432622875";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}

int main()
{
	//test_bitset1();
	//test_bitset2();
	//test_bloomfilter1();
	test_bloomfilter2();
	return 0;
}