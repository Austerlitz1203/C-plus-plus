#pragma once
#include<iostream>
#include<array>
#include <vector>
using namespace std;


// �����Ͷ���ŵ�һ��ֱ�ӾͿ���ʵ����������ʱ���е�ַ������Ҫ����
template<class T>
T Add(const T& left, const T& right);

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}


void func();