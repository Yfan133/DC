#include"main.h"
//this指针的生命周期比函数要长
//class A
//{
//public:
//	A()
//	{
//		_sum += _count;
//		++_count;
//	}
//	static int _count;
//	static int _sum;
//};
//int A::_count = 0;
//int A::_sum = 0;
//
//int Sum_Solution(int n) 
//{
//	A d1;
//	n > 0 && Sum_Solution(n - 1);
//	return d1._sum;
//}
//int main()
//{
//	int a = Sum_Solution(5);
//	return 0;
//}
class A
{
public:
	A()
		:p(new int(10))
	{
		cout << "构造A()" << endl;
	}
	~A()
	{
		delete p;
		cout << "析构A()" << endl;
	}
	void print()
	{
		printf("666\n");
	}

	int* p;
};
int main()
{
	A* a = (A*)malloc(sizeof(A));
	int data = 10;
	a->p = &data;
	a->print();
	free(a);
	//new(a) A();
	//a->~A();
	//free(a);
	//delete a;
	return 0;
}