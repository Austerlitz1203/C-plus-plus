#pragma once
#pragma once
#include <stdlib.h>

// ���Ա���������Ͷ������
//struct Stack

class Stack
{
public:
	// ��Ա��������
	void Init(int capacity = 4);
	void Push(int x);

private:
	// ��Ա����
	int* a;
	int size;
	int capacity;
};