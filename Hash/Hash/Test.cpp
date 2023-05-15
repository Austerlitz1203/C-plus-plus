#include"HashTable.h"

void TestHashTable1()
{
	int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
	OpenAddress::HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.insert(make_pair(e, e));
	}

	ht.insert(make_pair(15, 15));

	if (ht.Find(13))
	{
		cout << "13��" << endl;
	}
	else
	{
		cout << "13����" << endl;
	}

	cout<<"ɾ����"<<ht.Erase(13)<<endl;

	if (ht.Find(13))
	{
		cout << "13��" << endl;
	}
	else
	{
		cout << "13����" << endl;
	}
}


void TestHashTable2()
{
	int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
	HashBucket::HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.insert(make_pair(e, e));
	}

	ht.insert(make_pair(15, 15));
	ht.insert(make_pair(25, 25));
	ht.insert(make_pair(35, 35));
	ht.insert(make_pair(45, 45));
}


// �ַ�����ϣ��˼��
struct HashStr
{
	// BKDR
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}

		return hash;
	}
};


void TestHashTable3()
{
	//HashTable<string, string, HashStr> ht;
	HashBucket::HashTable<string, string> ht;
	ht.insert(make_pair("sort", "����"));
	ht.insert(make_pair("string", "�ַ���"));
	ht.insert(make_pair("left", "���"));
	ht.insert(make_pair("right", "�ұ�"));
	ht.insert(make_pair("", "�ұ�"));

	HashStr hashstr;
	cout << hashstr("abcd") << endl;
	cout << hashstr("bcda") << endl;
	cout << hashstr("aadd") << endl;
	cout << hashstr("eat") << endl;
	cout << hashstr("ate") << endl;
}

void TestHashTable4()
{
	size_t N = 900000;
	HashBucket::HashTable<int, int> ht;
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		ht.insert(make_pair(x, x));
	}

	cout << ht.MaxBucketSize() << endl;
}


int main()
{
	//TestHashTable1();
	//TestHashTable2();
	//TestHashTable3();
	TestHashTable4();
	return 0;
}