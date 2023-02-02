#include "Stack.h"

// 不限定 Stack 作用域的话，编译器不知道函数内部的各个变量是从哪里来的
void Stack::Init(int n)
{
	a = (int*)malloc(sizeof(int) * n);
	if (nullptr == a)
	{
		perror("mallocfail");
		return;
	}

	capacity = n;
	size = 0;
}

void Stack::Push(int x)
{
	a[size++] = x;
}