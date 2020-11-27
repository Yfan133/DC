#include<iostream>
#include<string>
using namespace std;
#pragma warning (disable:4996)
int main()
{
	//构造
	string ar0;		//无参构造，即空字符串
	string ar1("qwer");	//用C_string构造
	string ar2(5, 'w');	//n个有效元素，每一个都是字符'w'
	string ar3(ar1);	//拷贝构造
	//容量
	size_t size_ = ar1.size();		//返回有效元素个数
	size_t lenth_ = ar1.length();	//效果和size一样
	size_t capacity_ = ar1.capacity();	//返回容量
	ar1.empty();	//判断是否为空
	ar1.resize(10, 'a');	//将有效元素修改为10个，多的用'a'来填充
	ar1.reserve(100);		//将容量设置为20，若小于原始容量则容量不变
	ar1.clear();			//清空有效字符串
	//在使用string之前尽量先用reserve把容量设置好，避免每次插入扩容带来的开销
	capacity_ = ar0.capacity();
	for (int i = 0; i < 100; i++)
	{
		ar0.push_back('a');
		if (capacity_ != ar0.capacity())
		{
			capacity_ = ar0.capacity();
			cout << capacity_ << endl;
		}
	}

	return 0;
}
//#include"vc.h"
//int main()
//{
//	bit::vector<int> v0;
//	bit::vector<int> v1(5);
//	bit::vector<int> v2(v1.begin(), v1.end());
//	bit::vector<int> v3(v1);
//	v0.push_back(1);
//	v0.push_back(2);
//	v0.push_back(3);
//	v0.push_back(5);
//	v0.pop_back();
//	v0.swap(v1);
//	v0.insert(v0.begin(), 99);
//	v0.erase(v0.begin());
//	return 0;
//}