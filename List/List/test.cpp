#include"list.h"




void Test1()
{
	simulate::list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);

	// begin 赋值给 it 要调用拷贝构造，自己没有实现，所以是编译器自己实现的
	// 但是，这里就是需要浅拷贝，让it 和 begin 指向同一块 node
	simulate::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		(*it) *= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto l : lt)
	{
		cout << l << " ";
	}
	cout << endl;

	simulate::print_list(lt);
}


struct AA
{
	int _a1;
	int _a2;

	AA(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{}
};

void Test2()
{
	simulate::list<AA> lt;
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));

	// AA* ptr
	simulate::list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << ":" << (*it)._a2 << endl;		
		cout << it->_a1 << ":" << it->_a2 << endl;
		cout << it.operator->()->_a1 << ":" << it.operator->()->_a1 << endl;
		++it;
	}
	cout << endl;
}

void Test3()
{
	simulate::list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_front(1);
	simulate::print_list(lt);
	simulate::list<int>::iterator it = lt.begin();
	it++;
	lt.erase(it);
	simulate::print_list(lt);
	//lt.insert(it, 3);  // 删除之后迭代器失效
	it = lt.begin();
	it++;
	lt.insert(it, 100);
	lt.insert(it, 1000); // 插入之后不会
	simulate::print_list(lt);
	lt.pop_back();
	simulate::print_list(lt);
	lt.pop_front();
	simulate::print_list(lt);
}

int main()
{
	//Test1();
	//Test2();
	Test3();
}