#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#pragma warning (disable:4996)
class A
{
public:
	virtual void buy()	//ֻ��Ҫ�����еĺ����ӹؼ���virtual��������Բ���
	{
		cout << "����" << endl;
	}
	virtual A& cov()	//Э�䣺����ֵ���Ͳ�ͬ����Ҳ�ܹ�����д
	{
		cout << "cov������" << endl;
		return *this;
	}
	~A()
	{
		cout << "����������" << endl;
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
		cout << "����" << endl;
	}
	virtual B& cov()
	{
		cout << "cov������" << endl;
		return *this;
	}
	virtual ~B()
	{
		cout << "����������" << endl;
	}
	int* b_;
};
void Test(A& a)			//�������ͨ���������û���ָ��������ֳ���̬
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
	//a.buy();	//���ﲻ�����ֶ�̬����Ϊ�������̬�����������ǶԻ�������û���ָ��
	//b.buy();	
	//Test(a);
	//Test(b);
	return 0;
}
