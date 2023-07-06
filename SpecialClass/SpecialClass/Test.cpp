#include<iostream>

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

	// ����ͨ��һ����̬�����������󣬸÷����ڲ�������ջ���洴������
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



int main()
{
	//StackOnly st1;
	//static StackOnly st2;
	//StackOnly* st3 = new StackOnly;

	StackOnly st1 = StackOnly::CreateObj(1);
	//static StackOnly st2 = st1;
	static StackOnly st2 = move(st1);  // �����޷���ȫ����

	return 0;
}



