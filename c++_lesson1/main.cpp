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
int main()
{
	int year = 0, month = 0, day = 0;
	while (cin >> year >> month >> day)
	{
		cout << year << "-" << month << "-" << day << endl;
	}
	return 0;
}