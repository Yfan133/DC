#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
	void fun()
	{
		cout << "基类" << endl;
	}
	int a_ = 1;
};
class B : public A
{
public:
	void fun()
	{
		cout << "派生" << endl;
	}
	int b_ = 2;
};
void TestFun()
{
	B b;
	b.fun();
	b.A::fun();
}
int main()
{
	TestFun();
	
	return 0;
}