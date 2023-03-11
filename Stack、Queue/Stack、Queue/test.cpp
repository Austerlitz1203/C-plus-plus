#include"Stack.h"
#include"Queue.h"

void Test1()
{
	simulate::stack<int, vector<int>> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	simulate::stack<int, list<int>> st1;
	st1.push(10);
	st1.push(20);
	st1.push(30);
	st1.push(40);
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;

}

void Test2()
{
	// 使用vector实现队列的话，出队开销比较大
	simulate::queue<int, list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}


int main()
{
	Test1();
	Test2();
}