//#include<iostream>
//using namespace std;

// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//	void PushBack(const T& data)；
//		void PopBack()；
//		// ...
//		size_t Size() { return _size; }
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _pData[pos];
//	}
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//
//// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
//template <class T>
//Vector<T>::~Vector()  // 和以前不一样，要加一个参数类型，但是还不够，要加上面一行的内容
//{
//	if (_pData)
//		delete[] _pData;
//	_size = _capacity = 0;
//}





// String
#include<string>
#include<iostream>
using namespace std;

//int main()
//{
//	string s1;
//	string s2("hello world!");
//
//	for (size_t i = 0; i < s2.size(); i++)
//	{
//		s2[i]++;
//	}
//
//	cout << s2 << endl;  // 可以直接打印，因为重载了流输出
//
//	return 0;
//}




//int main()
//{
//	char str1[] = "apple";
//
//	char str2[] = "比赛";
//	cout << sizeof(str2) << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//
//	return 0;
//}



//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3 = "hello world";
//	string s4(s3, 6, 3);
//	cout << s4 << endl;
//	string s5(s3, 6, 13);
//	cout << s5 << endl;
//	string s6(s3, 6);
//	cout << s6 << endl;
//	string s7("hello world", 5);
//	cout << s7 << endl;
//	string s8(10, '*');
//	cout << s8 << endl;
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		s2[i]++;
//	}
//
//	cout << s2 << endl;
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}



//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//
//	return 0;
//}




//int main()
//{
//	string s1("hello");
//	s1.push_back(' ');
//	s1.push_back('!');
//	cout << s1 << endl;
//
//	s1.append("world");
//	cout << s1 << endl;
//
//	s1 += ' ';
//	s1 += '!';
//	s1 += "world";
//	cout << s1 << endl;
//}



//class string
//{
//private:
//	char* _ptr;
//	char _buf[16];
//	size_t _size;
//	size_t _capacity;
//};


//int main()
//{
//	// 观察扩容情况  -- 1.5倍扩容
//	string s;
//
//	//cout << sizeof(s) << endl;
//	s.reserve(100);
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	cout << "capacity changed: " << sz << '\n';
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}



//int main()
//{
//	// 扩容
//	string s1("hello world");
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// 扩容+初始化
//	string s2("hello world");
//	s2.resize(100, 'x');
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	// 比size小，删除数据，保留前5个
//	s2.resize(5);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	return 0;
//}

int main()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}