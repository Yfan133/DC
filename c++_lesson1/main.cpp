#include"main.h"
//thisָ����������ڱȺ���Ҫ��
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
	{
		_count++;
	}
	A(const A& tmp)
	{
		_count++;
	}
	//static int GetACount()	//static���εĳ�Ա����
	//{
	//	return _count;
	//}
//private:
	static int _count;		//static���εĳ�Ա����
};
int A::_count = 0;
int main()
{
	cout << A::_count << endl;
	//cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::_count << endl;
	cout << a1._count << endl;
	//cout << A::GetACount() << endl;
	cout << sizeof(A);
	return 0;
}