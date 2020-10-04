#include"main.h"
//每个成员函数中都放着一个this指针，指向当前对象的地址。且this指针不能赋值
/*
类似： void Test(student* ps,char name[],char gender[],int age)
this替换了ps的作用
ps->_name=name;
this->_name=name;
可写成_name=name;
this是*const类型因此无法改变指向
this指针主要通过“ecx”寄存器传递，lea取地址
查询：常用调用约定
add x---给this指针的地址加上x
*/

class student
{
	char name[20];
	char gender[3];
	int age;
};
class A			//类中既有成员函数，又有成员变量
{
	int a;
	void f1()
	{}
};
class B			//类中只有成员函数
{
	void Test_B()
	{}
};
class C			//空类
{};
struct D		//空结构体
{};
int main()
{
	C c1, c2, c3;
	cout << &c1 << endl << &c2 << endl << &c3;
	return 0;
}

//什么是结构体内存对齐？为什么需要内存对齐？
//默认对齐参数？如何对齐设置？默认对齐设置可以设置为任意值吗？
//怎么求结构体内成员变量的起始偏移量？offsetof(AA.c)模拟实现（百度笔试题）
//什么是大小端？写一个程序判断机器的大小端？（多种方法）说一个情景要考虑大小端问题。大小端和操作系统有没有关系
//#pragma pack(4)
//#pragma pack()恢复默认值
