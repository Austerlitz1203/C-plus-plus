//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int i = 10;
//	int& k = i;//�൱�ڣ���iȡһ��������k��i��һ����
//	int j = i;
//
//	cout << &i << endl;
//	cout << &k << endl;
//	cout << &j << endl;
//
//	++k;
//	++j;
//
//	cout << i << endl;
//	cout << j << endl;
//
//	int& m = i;//�����ж������
//
//	int& n = k;//Ҳ���Ը�����ȡ����
//
//
//	return 0;
//}


// 1.��������������
//#include<iostream>
//using namespace std;
//
//void swap(int& x, int& y)//ֱ��ʹ�����ã�Ҫ����ܶ࣬�βξ���ʵ�εı���
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//typedef struct Node
//{
//	int val;
//	struct Node* next;
//}Node;
//
//void PushBack(Node*& phead, int x)
//{
//	Node* newhead = (Node*)malloc(sizeof(Node));
//	if (!phead)
//	{
//		phead = newhead;
//	}
//
//}
//
//int main()
//{
//	//int a = 1, b = 2;
//	//cout << a << ' ' << b << endl;
//	//swap(a, b);
//	//cout << a << ' ' << b << endl;
//
//
//	//int* p = &a;
//	//int*& rp = p;
//
//	Node* plist = nullptr;
//	PushBack(plist, 1);
//	PushBack(plist, 2);
//
//
//	return 0;
//}



// 2. ����������ֵ
// ���ȣ����Լ��ٿ�������Σ������߿����޸ķ��ض���
//#include<iostream>
//#include<assert.h>
//
//#define N 10
//using namespace std;
//
//struct Array
//{
//	int& at(int i)
//	{
//		assert(i < N);
//		return a[i];
//	}
//	int a[N];
//	int size;
//
//};
//
//int main()
//{
//	struct Array ay;
//	for (int i= 0; i < N; i++)
//	{
//		ay.at(i) = i;  // �������ֵ�������ã�������ͨ�� int ����ôÿ�ξ��Ƿ��ص���ʱ������������ʱ��������
//		               // ���ԣ������޸ģ����Իᱨ���
//	}
//
//	for (int i = 0; i < N; i++)
//		cout << ay.at(i) << endl;
//
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int& Add(int a, int b)
//{
//    int c = a + b;
//	return c;
//}
//// ����������c�����ˣ����Ƿ��ص���c�����ã���Ȼ���ҵ�ԭ��c�ĵ�ַ�����ǲ�֪���ǲ��Ǳ�������
//// ����������˺��������򣬷��ض����Ѿ�������ϵͳ�����ˣ��ͱ��뷵��ֵ�������Է�������
//int main()
//{
//	int& ret = Add(1, 2);  
//	cout << ret << endl;
//	Add(3, 4);
//	cout << ret << endl;
//
//	cout << ret << endl;
//
//	printf("\n");
//	int ret1 = Add(1, 2);  // ret1 ���� c �ı�������һ����������������ֵ���ǲ�ȷ���ģ�Ҫ���ջؿռ��Ƿ����������
//	cout << ret1 << endl;
//	Add(3, 4);
//	cout << ret1 << endl;
//
//	cout << ret1 << endl;
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int main()
//{
//	 // Ȩ��ƽ��
//	int a = 10;
//	int& b = a;
//
//
//	// ���ú�ָ�룬��ֵ / ��ʼ��  Ȩ�޿�����С��ƽ�ƣ������ԷŴ�
//	const int c = 10;
//	int& d = c; // Ȩ�޷Ŵ�
//
//	const int*  p1=null;
//	int* p2 = p1;
//
//
//	int x = 10;
//	const int& y = x; // Ȩ����С
//
//	int* p3=null;
//	const int* p4 = p3; // Ȩ����С
//
//
//
//	// Ȩ�޵ķŴ����С��ֻ������ָ������ã���Ϊ��������һ��������b�ĸı��Ӱ��a��ָ��ͬ��
//	// �������棬n��m�����鲻ͬ�Ŀռ䣬n�ĸı䲻��Ӱ��m
//	const int m = 10;
//	int n = m; // �� m ��ֵ���� n
//
//
//	int i = 10;
//	cout << (double)i << endl; // ���ﲢ���ǰ� i ǿ������ת���� double ���ͣ�ֻ�ǰ�i�ŵ�һ��double���͵���ʱ��������
//
//	double dd = i; // ����� ������ʱ������Ȼ��i�ŵ���ʱ��������Ĺ���ʡ����
//
//	double& l = i;   // ���� l ����ʱ���������ã�������ʱ�������г��ԣ��൱��Ȩ�޷Ŵ�
//	const double& ll = i;  // ll ����ʱ���������ã�Ȩ��ƽ��
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	// �ӻ��Ƕ�������������ʵҲ��ָ��ʵ�ֵģ������˿ռ䣬��������ʹ�õ�ʱ����Ҫ�������
//	return 0;
//}





// C++�Ƽ���
// const �� enum ����곣��
// inline ����꺯��
// ��Ϊ �� 
// 1�����ܵ���
// 2��û�����Ͱ�ȫ�ļ��
// 3����Щ�����·ǳ�����
// 


#include<iostream>

#define Add(x,y) ((x)+(y))

using std::cout;
using std::endl;

// ʹ������������û�к������ã�����������ʹ������������ʱ�򣬽�������չ��
// ������������ֻ���൱�ڸ�������һ�������顱��ʵ�����Ǳ����������Ƿ�չ��������ݹ麯����չ���͵úܶ��У��������Ͳ���չ��
inline int ADD(int x, int y)
{
	int c = x + y;
	return c;
}

int main()
{
	//int m=Add(4, 6);
	//cout << m << endl;

	cout << ADD(3, 7) << endl;

	return 0;
}
