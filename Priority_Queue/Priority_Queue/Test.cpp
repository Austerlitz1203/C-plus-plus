#include"Priority_Queue.h"
#include<iostream>

void Test1()
{
	simulate::priority_queue<int> pq;
	pq.push(10);
	pq.push(200);
	pq.push(3);
	pq.push(44);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;


	simulate::priority_queue<int,vector<int>,greater<int>> pq1;
	pq1.push(10);
	pq1.push(200);
	pq1.push(3);
	pq1.push(44);
	pq1.push(9);

	while (!pq1.empty())
	{
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;
	
}


int main()
{
	Test1();
}