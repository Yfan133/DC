#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
// 1.strcat和strcpy作用相似，都是拼接后面的字符串到前面，返回前一个的地址
// 2.若strcat(str + 1, ptr + 2);表示从ptr起始的第三个字符开始拷贝，到str后面，返回str第二个字符的地址
int main()
{
	string str("qwerasdf-zxcv");
	int pos = str.find("xcv");
	string st(str.substr(str.find('-')));
	return 0;
}

//class A
//{
//public:
//	A(const char* s)
//	{
//		cout << s << endl;
//	}
//};
//class B :virtual public A
//{
//public:
//	B(const char* s1, const char* s2) : A(s1)
//	{
//		cout << s2 << endl;
//	}
//};
//class C :virtual public A
//{
//public:
//	C(const char* s1, const char* s2) : A(s1)
//	{
//		cout << s2 << endl;
//	}
//};
//class D :public B, public C
//{
//public:
//	D(const char* s1, const char* s2, const char* s3, const char* s4) : B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}
