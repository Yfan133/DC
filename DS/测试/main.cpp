﻿#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
	virtual void fun()
	{
		cout << "基类" << endl;
	}
};
class B : public A
{
public:
	virtual void fun()
	{
		cout << "派生类" << endl;
	}
};
void Test(A& a)
{
	a.fun();
}
int main()
{
	A a;
	B b;
	Test(a);
	Test(b);
	return 0;
}