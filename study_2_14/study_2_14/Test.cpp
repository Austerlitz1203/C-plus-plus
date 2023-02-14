#include<iostream>
#include<String>

using namespace std;

void func(const string s)
{
	//string::iterator it = s.begin(); // ����
	
	// const ��������ֻ���Զ��ͱ�����������д
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//string::const_reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();  // ��Ϥ�Ļ���Ҳ������ auto 
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
//	string::iterator it = s1.begin(); // ��һ���ַ�
//	string::iterator it1 = s1.end();  // ���һ���ַ� �� ��һ������ \0
//	while (it != it1)
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	cout << endl;
//	// ���������
//	string::reverse_iterator rit = s1.rbegin(); // ���һ���ַ�
//	while (rit != s1.rend())  // rend() �ǵ�һ���ַ���ǰһ��
//	{
//		cout << *rit << " ";
//		++rit; // ��������
//	}
//	cout << endl;
//
//	func(s1);
//
//
//	//s1[100]; //����Խ��ֱ�Ӷ���
//
//	//s1.at(100); // Խ���׳��쳣��Ҫ����
//
//	return 0;
//}





//int main()
//{
//	// ���Ƽ�ʹ�� insert �� erase �������þ����ã���Ϊ O(N)
//	string s1("world!");
//	s1.insert(0, "hello");
//	cout << s1 << endl;
//
//	//s1.insert(5, " ");
//	s1.insert(5, 1, ' ');
//	s1.insert(5, "");  // ����һ�����ַ������൱��ֱ�� \0  ,\0 �ǲ�������ȥ��
//	cout << s1 << endl;
//
//
//	string s2("hello World!");
//	//s2.erase(0, 2);  // pos �� λ�ÿ�ʼ��ɾ�� n ���ַ�
//	//s2.erase(5, 1);
//	//s2.erase(s2.begin() + 7);  // ��ָ��ָ���λ��ɾһ��
//	//s2.erase(5);                 // ��λ�ú���ɾ��
//	s2.erase(5,20);              // ����ʵ�ʳ��ȣ��ж���ɾ����
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
	s1.reserve(s1.size() + count * 2);  // ��ǰ���ռ䣬������治������

	size_t pos = s1.find(' ');
	while (pos != string::npos)
	{
		s1.replace(pos, 1, "%20");
		pos = s1.find(' ', pos + 3);  // Ҳ���Դ�ָ��λ�ÿ�ʼ��
	}
	cout << s1 << endl;
}

void replace1()
{
	string s1("who am i");
	string newstr;  // �ռ任ʱ��

	for (auto s : s1)
	{
		if (s != ' ')
		{
			newstr += s1;  // ��Ȼ += Ҳ�����ݣ������Ҫ�Ż���Ҳ���԰� newstr ��ǰ����
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
//	s2.replace(5, 1, "%%d");  // �����λ�� �� һ���ַ� �滻�� �����
//	cout << s2 << endl;
//
//	string s3("xxx");
//	s3.swap(s2);  // ����ֱ�ӽ�������ָ��ָ���λ�þͿ���
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	swap(s2, s3); // �����������
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//
//	return 0;
//}



//int main()
//{
//	string s1("hello world!");
//	cout << s1 << endl;         // string����
//	cout << s1.c_str() << endl; // ���� const char* �������ַ�������ӡ
//	cout << (void*)s1.c_str() << endl;
//
//	s1 += '\0';
//	s1 += '\0';
//	s1 += "xxx";
//	cout << s1 << endl;         // ���� size ����
//	cout << s1.c_str() << endl; // ���� '\0' ��ֹ
//
//
//	// �� c_str �����ɣ���Ϊ�˼���C
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
//	size_t pos = file.rfind('.');  // ������
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
//	size_t pos = str.find_first_of("abcd");  // �ҵ����������һ���ַ��������ҡ� find_last_of �ǵ�����
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
	//cin >> s1;  // ���� who are you  ��ֻ��� who ��������Ϊ�ǰ��տո񡢻��С�Tab������ģ�Ϊ�� cin>>s1>>s2;
	getline(cin, s1); // ��������������пո񣬱���ʹ��getline��һ��Ϊ��λ
	cout << s1 << endl;

	return 0;
}