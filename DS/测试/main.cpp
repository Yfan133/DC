#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<list>
#include <algorithm>
//#include<stack>
using namespace std;
#pragma warning(disable:4996)
//int Quick(vector<int>& arr, int left, int right)
//{
//	
//}
//void QuickSort(vector<int>& arr,int left,int right)
//{
//	
//}
//int main()
//{
//	vector<int> arr = { 49,38,56,75,12,99,68,75,49 };
//	QuickSort(arr, 0, arr.size());
//	return 0;
//}
class A
{
public:
	A()
	{

	}
	~A()
	{
		delete this;
	}
	void foo()
	{
		delete this;
	}
};
int main()
{
	A* a = new A();
	a->foo();
	return 0;
}
//void fun(const int& a,const int& b)
//{
//	cout << a << ' ' << b << endl;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int x = 0;
//	int y = 0;
//	fun(i++, i);	//第一个参数：i的一份临时值  第二个参数：i的一份拷贝
//	fun(j++, ++j);	
//	fun(++x, x++);
//	fun(++y, ++y);
//	return 0;
//}
