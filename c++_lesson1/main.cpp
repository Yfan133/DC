#include"main.h"
//this指针的生命周期比函数要长
class A
{
public:
	A(int data)				//构造函数
	{
		_data = data;
	}
	ostream& operator<<(ostream& _cout)const	//在类内重载<<操作符，cout是右操作数，隐藏的this为左操作数
	{
		cout << _data;
		return _cout;
	}
	int _data;
};
ostream& operator<<(ostream& _cout,const A& tmp)
{
	cout << tmp._data;
	return _cout;
}
int main()
{
	A a1(1);
	cout << a1 << 1 << endl << a1;
	a1 << cout;
	return 0;
}
