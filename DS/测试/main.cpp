#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
	int a_ = 1;
};
class B1 : virtual public A
{
public:
	int b1_ = 2;
};
class B2 : virtual public A
{
public:
	int b2_ = 3;
};
class C : public B1, public B2
{
public:
	int c_ = 4;
};
void TestFun()
{
	C c;
	c.B1::a_ = 9;
	c.B2::a_ = 10;
	c.a_ = 1;
}
int main()
{
	TestFun();
	
	return 0;
}