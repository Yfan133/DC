#include <iostream>
#include <string>
#include <queue>
using namespace std;
#pragma warning (disable:4996)
class par
{
public:
	int a_;
};
class chl : public  par
{
public:
	int b_;
};
void Test()
{
	chl a;
	a.a_ = 1;
	a.b_ = 2;
}
int main()
{
	Test();
	return 0;
}
