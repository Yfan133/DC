#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#pragma warning (disable:4996)
class A
{
public:
	virtual void buy()	//只需要基类中的函数加关键字virtual，子类可以不加
	{
		cout << "父类" << endl;
	}
	virtual A& cov()	//协变：返回值类型不同，但也能构成重写
	{
		cout << "cov：父类" << endl;
		return *this;
	}
	~A()
	{
		cout << "析构：父类" << endl;
	}
	int a_;
};
class B : public  A
{
public:
	B()
	{
		b_ = new int[10];
	}
	virtual void buy()
	{
		cout << "子类" << endl;
	}
	virtual B& cov()
	{
		cout << "cov：子类" << endl;
		return *this;
	}
	virtual ~B()
	{
		cout << "析构：子类" << endl;
	}
	int* b_;
};
void Test(A& a)			//这个函数通过基类引用或者指针才能体现出多态
{
	a.buy();
	a.cov();
}
int main()
{
	A* a = new B;
	delete a;
	//A a;
	//B b;
	//a.buy();	//这里不能体现多态，因为不满足多态条件：必须是对基类的引用或者指针
	//b.buy();	
	//Test(a);
	//Test(b);
	return 0;
}
