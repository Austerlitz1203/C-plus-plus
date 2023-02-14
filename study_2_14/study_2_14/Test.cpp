#include<iostream>
#include<String>

using namespace std;

void func(const string s)
{
	//string::iterator it = s.begin(); // 报错
	
	// const 迭代器，只可以读和遍历，不可以写
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//string::const_reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();  // 熟悉的话，也可以用 auto 
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

}


//int main()
//{
//	string s1("Hello World!");
//
//	string::iterator it = s1.begin(); // 第一个字符
//	string::iterator it1 = s1.end();  // 最后一个字符 的 后一个，即 \0
//	while (it != it1)
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	cout << endl;
//	// 反向迭代器
//	string::reverse_iterator rit = s1.rbegin(); // 最后一个字符
//	while (rit != s1.rend())  // rend() 是第一个字符的前一个
//	{
//		cout << *rit << " ";
//		++rit; // 反过来的
//	}
//	cout << endl;
//
//	func(s1);
//
//
//	//s1[100]; //访问越界直接断言
//
//	//s1.at(100); // 越界抛出异常，要处理
//
//	return 0;
//}





//int main()
//{
//	// 不推荐使用 insert 、 erase ，能少用就少用，因为 O(N)
//	string s1("world!");
//	s1.insert(0, "hello");
//	cout << s1 << endl;
//
//	//s1.insert(5, " ");
//	s1.insert(5, 1, ' ');
//	s1.insert(5, "");  // 这是一个空字符串，相当于直接 \0  ,\0 是不会插入进去的
//	cout << s1 << endl;
//
//
//	string s2("hello World!");
//	//s2.erase(0, 2);  // pos 个 位置开始，删除 n 个字符
//	//s2.erase(5, 1);
//	//s2.erase(s2.begin() + 7);  // 该指针指向的位置删一个
//	//s2.erase(5);                 // 该位置后面删完
//	s2.erase(5,20);              // 超过实际长度，有多少删多少
//	cout << s2 << endl;
//
//	return 0;
//}




void replace()
{
	string s1("who am i");
	size_t count = 0;
	for (auto s : s1)
	{
		if (s == ' ')
			count++;
	}
	s1.reserve(s1.size() + count * 2);  // 提前开空间，避免后面不断扩容

	size_t pos = s1.find(' ');
	while (pos != string::npos)
	{
		s1.replace(pos, 1, "%20");
		pos = s1.find(' ', pos + 3);  // 也可以从指定位置开始找
	}
	cout << s1 << endl;
}

void replace1()
{
	string s1("who am i");
	string newstr;  // 空间换时间

	for (auto s : s1)
	{
		if (s != ' ')
		{
			newstr += s1;  // 当然 += 也会扩容，如果还要优化，也可以把 newstr 提前开好
		}
		else
			newstr += "%20";
	}
	s1=newstr;
	cout << s1 << endl;
}



//int main()
//{
//	string s2("hello world!");
//	s2.replace(5, 1, "%%d");  // 第五个位置 的 一个字符 替换成 后面的
//	cout << s2 << endl;
//
//	string s3("xxx");
//	s3.swap(s2);  // 这是直接交换两个指针指向的位置就可以
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	swap(s2, s3); // 深拷贝，开销大
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//
//	return 0;
//}



//int main()
//{
//	string s1("hello world!");
//	cout << s1 << endl;         // string类型
//	cout << s1.c_str() << endl; // 返回 const char* ，当作字符串来打印
//	cout << (void*)s1.c_str() << endl;
//
//	s1 += '\0';
//	s1 += '\0';
//	s1 += "xxx";
//	cout << s1 << endl;         // 按照 size 来的
//	cout << s1.c_str() << endl; // 遇到 '\0' 终止
//
//
//	// 有 c_str 的理由，是为了兼容C
//	string s("test.cpp");
//	FILE* fout = fopen(s.c_str(), "r");
//	if (fout == nullptr)
//	{
//		perror("fopen fail::");
//		exit(-1);
//	}
//
//	return 0;
//}



//int main()
//{
//	string file("test.cpp.zip.tar");
//	size_t pos = file.rfind('.');  // 倒着找
//	if (pos != string::npos)
//	{
//		string suffix = file.substr(pos);
//		cout << suffix;
//	}
//
//	return 0;
//}


//int main()
//{
//	string str("Please, replace the vowels in this sentence by asterisks.");
//	size_t pos = str.find_first_of("abcd");  // 找到里面的任意一个字符，正着找。 find_last_of 是倒着找
//	while (pos != string::npos)
//	{
//		str[pos] = '%';
//		pos = str.find_first_of("abcd",pos+1);
//	}
//
//	cout << str << endl;
//	return 0;
//}


int main()
{
	string s1;
	//cin >> s1;  // 输入 who are you  ，只输出 who ，这是因为是按照空格、换行、Tab来间隔的，为了 cin>>s1>>s2;
	getline(cin, s1); // 所以如果流输入有空格，必须使用getline，一行为单位
	cout << s1 << endl;

	return 0;
}