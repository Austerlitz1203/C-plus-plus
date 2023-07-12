#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<string>
#include<set>
#include<functional>
using namespace std;


// һ���࣬��ֹ����
class CopyBan
{
	//  C++ 11 ֧�� =delete ��ʾ�ñ�����ɾ����Ĭ�ϳ�Ա����
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;


private:
	// C++ 98 ���������ǽ������͸�ֵ������Ϊ˽��
	//CopyBan(const CopyBan&);
	//CopyBan& operator=(const CopyBan&);
	//...
};




// һ���ֻ࣬���ڶ��ϴ���
// ˼·1

//class HeapOnly
//{
//public:
//	void Destroy()
//	{
//		delete this;  // delete �ǵ����������������������ڲ������Կ��Ե���
//	}
//
//private:
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//
//	int _x;
//};
//
//int main()
//{
//	//HeapOnly ho1;  
//	//static HeapOnly ho2;  // ������������
//	HeapOnly* pho3 = new HeapOnly;
//	pho3->Destroy();
//
//	return 0;
//}


// ˼·2
class HeapOnly
{
public:

	// ������˽�У�Ȼ������һ����̬���������ö��󣬿���ֱ�ӵ�������������ڲ��ڶ��ϴ������󣬷���ָ�롣
	static HeapOnly* CreateObj(int x = 0)
	{
		HeapOnly* p = new HeapOnly(x);
		return p;
	}

private:
	HeapOnly(int x = 0)
		:_x(x)
	{}

	// ˽�п�������͸�ֵ���أ�Ҳ��Ϊ�˱�֤����ջ�ϴ�������
	HeapOnly(const HeapOnly& hp) = delete;
	HeapOnly& operator=(const HeapOnly& hp) = delete;

	int _x;
};


//int main()
//{
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//	//HeapOnly* hp3 = new HeapOnly;
//
//	HeapOnly* hp4 = HeapOnly::CreateObj();
//	//HeapOnly hp5(*p4);
//
//	return 0;
//}




// һ���ֻ࣬��ջ�ϴ�������
class StackOnly
{
public:

	// ֻ��ͨ��һ����̬�����������󣬸÷����ڲ�������ջ���洴������
	static StackOnly CreateObj(int x = 0)
	{
		return StackOnly(x);
	}

	StackOnly(StackOnly&& st)
		:_x(st._x)
	{}

private:
	StackOnly(int x = 0)
		:_x(x)
	{}

	StackOnly(const StackOnly& st) = delete;

	int _x;
};



//int main()
//{
//	//StackOnly st1;
//	//static StackOnly st2;
//	//StackOnly* st3 = new StackOnly;
//
//	StackOnly st1 = StackOnly::CreateObj(1);
//	//static StackOnly st2 = st1;
//	static StackOnly st2 = move(st1);  // �����޷���ȫ����
//
//	return 0;
//}



// ����ģʽ

// ����ģʽ��һ��ʼ(main����֮ǰ)�ʹ�������

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _ins;
//	}
//
//	void Add(const string& str)
//	{
//		_mtx.lock();
//		_v.push_back(str);
//		_mtx.unlock();
//	}
//
//	void Print()
//	{
//		_mtx.lock();
//
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//
//		_mtx.unlock();
//	}
//
//private:
//	// �������������ⴴ������
//	Singleton()
//	{}
//
//    //������
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//private:
//	mutex _mtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//};
//
//Singleton* Singleton::_ins = new Singleton;







// ����ģʽ����һ�η���ʵ������ʱ����

// �����������Ͷ�������ȱ��
// ������ȱ�㣺
// 1��������������ʼ�����������ʼ�������࣬�������һЩIO��Ϊ�����ȡ�����ļ��ȣ���main����֮ǰ��Ҫ���룬��һ����ʱ����Ҫʹ��ȷռ����Դ���ڶ�������������Ӱ�졣
// 2����������������Ƕ�����������������ϵ��Ҫ����1�ٴ���������2�ٴ����������޷�����˳�������ſ��ԡ�

// �������ŵ㣺
// �򵥣�����������ԣ�

// ���������Ľ����������������⣬���Ǿ�����Ը���һ���

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		// ˫������
//		if (_ins == nullptr)  // ���Ч��
//		{
//			_imtx.lock();
//
//			if (_ins == nullptr)  // �̰߳�ȫ
//			{
//				_ins = new Singleton;
//			}
//
//			_imtx.unlock();
//		}
//
//		return _ins;
//	}
//
//	// һ��ȫ�ֶ�Ҫʹ�õ����������Ե�������һ�㲻��Ҫ��ʾ�ͷ�
//	// ��Щ���ⳡ��������ʾ�ͷ�һ��
//	static void DelInstance()
//	{
//		_imtx.lock();
//		if (_ins)
//		{
//			delete _ins;
//			_ins = nullptr;
//		}
//		_imtx.unlock();
//	}
//
//	// �ڲ��ࣺ�����������
//	class GC
//	{
//	public:
//		~GC()
//		{
//			DelInstance();
//		}
//	};
//
//	static GC _gc;
//
//	void Add(const string& str)
//	{
//		_vmtx.lock();
//
//		_v.push_back(str);
//
//		_vmtx.unlock();
//	}
//
//	void Print()
//	{
//		_vmtx.lock();
//
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//
//		_vmtx.unlock();
//	}
//
//	~Singleton()
//	{
//		// �־û�
//		// ����Ҫ��������ʱ��������д���ļ���������������ʱ�־û��ͱȽϺ�
//	}
//
//private:
//	// �������������ⴴ������
//	Singleton()
//	{}
//
//	// ������
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//private:
//	mutex _vmtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//	static mutex _imtx;
//};
//
//Singleton* Singleton::_ins = nullptr;
//mutex Singleton::_imtx;
//
//Singleton::GC Singleton::_gc;
//
//int main()
//{
//	srand(time(0));
//
//	int n = 30;
//	thread t1([n](){
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t1�߳�:" + to_string(rand()));
//		}
//	});
//
//	thread t2([n](){
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t2�߳�:" + to_string(rand()));
//		}
//	});
//	
//	t1.join();
//	t2.join();
//
//	Singleton::GetInstance()->Print();
//
//	Singleton::GetInstance();
//
//	//Singleton s(*Singleton::GetInstance());
//
//	return 0;
//}




// ��һ�ִ�������ģʽ�İ취
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// C++11֮ǰ�����ﲻ�ܱ�֤��ʼ����̬������̰߳�ȫ����
		// C++11֮��������Ա�֤��ʼ����̬������̰߳�ȫ����
		static Singleton inst;

		return &inst;
	}

	void Add(const string& str)
	{
		_vmtx.lock();

		_v.push_back(str);

		_vmtx.unlock();
	}

	void Print()
	{
		_vmtx.lock();

		for (auto& e : _v)
		{
			cout << e << endl;
		}
		cout << endl;

		_vmtx.unlock();
	}

	~Singleton()
	{
		// �־û�
		// ����Ҫ��������ʱ��������д���ļ���������������ʱ�־û��ͱȽϺ�
	}

private:
	// �������������ⴴ������
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	// ������
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(const Singleton& s) = delete;

private:
	mutex _vmtx;
	vector<string> _v;
};


//int main()
//{
//	Singleton::GetInstance();
//	Singleton::GetInstance();
//
//	return 0;
//}




// C++ ������ת��

void Test()
{
	int i = 1;
	// ��ʽ����ת��
	double d = i;
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// ��ʾ��ǿ������ת��
	int address = (int)p;

	printf("%x, %d\n", p, address);
}


// ���£���ǰд������������һЩ���⣬pos == 0ʱ�ͻ��д���Ҳ����Ϊ����ת��
//void insert(size_t pos, char ch)
//{
//	int end = _size;
//	while (end >= pos)
//	{
//		//...
//		--end;
//	}
//}


//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// ����ʹ��static_cast�ᱨ��Ӧ��ʹ��reinterpret_cast
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//
//	return 0;
//}


//void main()
//{
//	volatile const int a = 2;
//	//int* p = const_cast<int*>(&a);
//	int* p = (int*)&a;
//
//	*p = 3;
//
//
//	// ��û���޸ĵ�a ���Ƿ�Ҫ���� volatile
//	cout << a << endl;
//	cout << *p << endl;
//}


class A
{
public:
	virtual void f(){}
};

class B : public A
{};



void fun(A* pa, const string& s)
{
	cout <<"paָ��"<<s << endl;

	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = (B*)pa;			   // ����ȫ��
	B* pb2 = dynamic_cast<B*>(pa); // ��ȫ��

	cout << "[ǿ��ת��]pb1:" << pb1 << endl;
	cout << "[dynamic_castת��]pb2:" << pb2 << endl << endl;
}

//int main()
//{
//	A a;
//	B b;
//	fun(&a, "ָ�������");
//	fun(&b, "ָ���������");
//
//	cout << typeid(a).name() << endl;
//	decltype(a) aa;
//
//	function<bool(int,int)> gt = [](int x, int y){return x > y; };
//	set<int, decltype(gt)> s;
//
//	return 0;
//}






// C++ �� IO��


//int main()
//{
//	string str;
//	// ctrl+c �ź�ǿɱ����
//	// ctrl+z + ���� ��������ȡ��������־
//	// istream& operator>> (istream& is, string& str);
//
//	while (cin>>str)
//	{
//		cout << str << endl;
//	}
//
//	// ƾʲôistream��cin�������תbool
//	// ƾʲôstring��str�������תbool
//	// ��Ϊistream�����-��explicit operator bool() const;
//	// ֧���Զ�������ת��������
//	while (str)  // str ������ֱ��תΪ bool 
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//	operator int() const
//	{
//		return _a;
//	}
//
//private:
//	int _a;
//};

//int main()
//{
//	// ��������ת�����Զ�������
//	//A aa1 = static_cast<A>(1);
//	A aa1 = 1;  // ��Ϊ�������Ĺ��캯��
//
//	// �Զ�����ת������������
//	int x = aa1;  // ��Ϊ operator int()
//
//
//	return 0;
//}



class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool() const
	{
		// ����������д�ģ���������_yearΪ0�������
		if (_year == 0)
			return false;
		else
			return true;
	}

private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;

	return out;
}


//int main()
//{
//	// �Զ�����������Ҫ�����Լ�����<< �� >>
//	Date d(2022, 4, 10);
//	cout << d;
//
//	while (d)  // str ������ ��Date ���ԣ�������Ϊ Date �� operator bool()  
//	{
//		cin >> d;
//		cout << d;
//	}
//
//	return 0;
//}




#include<fstream>

//int main()
//{
//	std::ofstream ofs("test.txt", ofstream::out | ofstream::app);
//	ofs << "hello world";
//	ofs << "hello world";
//
//	return 0;
//}


struct ServerInfo
{
	char _address[32];
	//string _address;

	int _port;
	Date _date;
};

struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	// �����ƶ�д����д�����У�������string
	// ��Ϊԭ�ⲻ���ؿ������������� string �ĳ�Ա������������ָ�룬���������������
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((char*)&info, sizeof(info));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ofstream::in | ofstream::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	// �ı���д C++�ı���д����
	// �ı���д���ʣ��ڴ����κ����Ͷ���ת���ַ�����д
	// c�����ı���д�ܲ����㣬��ΪҪ����ת�ַ���
	// c++��װ���Ժ���кܴ������
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " ";
		ofs << info._port << endl;
		ofs << info._date << endl;
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address;
		ifs >> info._port;
		ifs >> info._date;
	}

private:
	string _filename; // �����ļ�
};


//int main()
//{
//	ServerInfo winfo = { "192.168.11.189xxxxxxxxxxxxx",88,{2023,7,12} };
//	string str;
//	cin >> str;
//	if (str == "�����ƶ�")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadBin(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout<<rinfo._date << endl;
//	}
//	else if (str == "������д")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);
//	}
//	else if (str == "�ı���")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadText(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	else if (str == "�ı�д")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteText(winfo);
//	}
//
//	return 0;
//}




#include <sstream>

//int main()
//{
//	//ostringstream oss;
//	stringstream oss;
//	oss << 100 << " ";
//	oss << 11.22 << " ";
//	oss << "hello";
//
//	string str = oss.str();
//	cout << str << endl;
//
//	//istringstream iss(str);
//	stringstream iss(str);
//	int i;
//	double d;
//	string s;
//	iss >> i >> d >> s;
//	cout << i << endl;
//	cout << d << endl;
//	cout << s << endl;
//
//	return 0;
//}


// ���л��ͷ����л�
struct ChatInfo
{
	string _name; // ����
	int _id;      // id
	Date _date;   // ʱ��
	string _msg;  // ������Ϣ
};

int main()
{
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
	stringstream oss;
	oss << winfo._name << " ";
	oss << winfo._id << " ";
	oss << winfo._date << " ";
	oss << winfo._msg;
	string str = oss.str();
	cout << str << endl;

	stringstream iss(str);
	ChatInfo rinfo;
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}