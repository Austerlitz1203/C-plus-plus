#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<string>
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


int main()
{
	Singleton::GetInstance();
	Singleton::GetInstance();

	return 0;
}