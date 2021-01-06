#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#pragma warning (disable:4996)
class A
{
public:
	virtual void fun()
	{
		cout << "基类" << endl;
	}
};
class B : public  A
{
public:
	void fun(int i)
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