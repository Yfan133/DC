#include"main.h"
//在类里放函数：所有对象中都有这个函数，太浪费空间
//解决：放一个指针，指针指向成员函数存放位置的首地址（函数入口地址）
//类/对象的大小计算（对象中只存储了成员变量）:只需将类中成员变量的大小加起来，注意内存对齐，例char [20]; char [3];int; 28字节
//成员函数单独进行存放，当程序运行起来，成员函数存放在代码段里，
//特别的：空类的大小为1（不是0字节）,因为定义不同变量在栈帧中地址应该不同，如果地址一样则说明空间大小为0，c1,c2,c3变量是同一对象，事实上不同
//说明空类也是有大小的，在主流编译器中，空类大小为1，这样做是为了区分空类定义出来的是不同对象
//每个成员函数中都放着一个this指针，指向当前对象的地址。且this指针不能赋值
/*类似： void Test(student* ps,char name[],char gender[],int age)
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
class A			//大小为4
{
	int a;
};
class B			//空类大小为1
{
	void Test_B()
	{}
};
class C			//空类的大小为1
{};
struct D
{};
int main()
{
	A a1, a2, a3;
	D a4;
	cout << &a1 << endl << &a2 << endl << &a3 << endl << &a4;
	return 0;
}

//什么是结构体内存对齐？为什么需要内存对齐？
//默认对齐参数？如何对齐设置？默认对齐设置可以设置为任意值吗？
//怎么求结构体内成员变量的起始偏移量？offsetof(AA.c)模拟实现（百度笔试题）
//什么是大小端？写一个程序判断机器的大小端？（多种方法）说一个情景要考虑大小端问题。大小端和操作系统有没有关系
//#pragma pack(4)
//#pragma pack()恢复默认值