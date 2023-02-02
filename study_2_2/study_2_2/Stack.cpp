#include "Stack.h"

// ���޶� Stack ������Ļ�����������֪�������ڲ��ĸ��������Ǵ���������
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