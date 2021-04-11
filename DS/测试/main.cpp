#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	virtual void test() = 0;
	virtual ~A()
	{
		cout << "~A" << endl;
	}
};
class B :public A
{
	virtual void test()
	{
		cout << "hello" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};
int main()
{
	A* a = new B;
	delete a;
	return 0;
}