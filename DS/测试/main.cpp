#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//int main()
//{
//	int a;
//	float b, c, d;
//	scanf("%2d%3f%4f", &a, &b, &c);
//	scanf("%f", &d);
//	printf("%d, %f, %f", a, b, c);
//	printf("\n%f", d);
//	return 0;
//}
class A
{
public:
	virtual void fun1()
	{}
	virtual void fun2()
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
class C : public B
{
public:
	virtual void fun3()
	{}
};
int main()
{
	A a;
	B b;
	C c;
	return 0;
}
