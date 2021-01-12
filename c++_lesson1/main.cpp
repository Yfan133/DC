#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#pragma warning (disable:4996)
class A
{
public:
	virtual void fun1()
	{}
	void fun2()
	{}
};
class B : public A
{
public:
	virtual void fun1()
	{}
	virtual void fun3()
	{}
};
int main()
{
	A a;
	B b;
	A& c = a;
	A& d = b;
	a.fun1();
	a.fun2();
	b.fun1();
	b.fun2();
	return 0;
}