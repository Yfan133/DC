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
	{
		cout << "����" << endl;
	}
	virtual void fun2()
	{
		cout << "����" << endl;
	}
};
class B : public A
{
public:
	virtual void fun1()
	{
		cout << "����" << endl;
	}
	virtual void fun2()
	{
		cout << "����" << endl;
	}
	/*virtual void fun3()
	{
		cout << "����" << endl;
	}*/
};
int main()
{
	A a;
	B b;
	A& c = a;
	A& d = b;
	c.fun1();
	d.fun1();
	return 0;
}