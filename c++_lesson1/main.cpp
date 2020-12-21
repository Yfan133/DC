#include<iostream>
#include<string>
using namespace std;
#pragma warning (disable:4996)


class par
{
	friend void Test();
private:
	int a_;
};
class chl : public  par
{
protected:
	int b_;
};
void Test()
{
	chl a;
	par b;
	b.a_ = 1;
	a.a_ = 2;
}
int main()
{
	Test();
	return 0;
}
