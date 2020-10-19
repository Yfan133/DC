//为什么要内存对齐？
//
//默认对齐参数？如何对齐设置？默认对齐设置可以设置为任意值吗？
//vs:8字节       #prgma pack(4)     必须设置成2的n次方
//怎么求结构体内成员变量的起始偏移量？offsetof(AA.c)模拟实现（百度笔试题）
//什么是大小端？写一个程序判断机器的大小端？（多种方法）说一个情景要考虑大小端问题。大小端和操作系统有没有关系
////////////////////////////////////////////////////////////////////////////
/*
拷贝构造函数也是构造函数的一种，因此没有返回值
用户没有显示定义时默认给d2设置成和d1一样
用户定义了拷贝构造函数时，将不会运行默认的
Data(const Data& d){}一般情况下加const，不修改传参的内容，增加安全性
不能省略&引用标记，若省略则会无限调用Data()构造函数
Data d2(d1);用d1的成员变量初始化d2

默认拷贝构造函数在底层用的是同一块堆内存空间，析构函数释放时会被释放两次而报错
默认拷贝构造函数是按浅拷贝方式实现的，后果：多个对象用的同一份资源(地址)，被释放多次会引起代码崩溃
浅拷贝：将一个对象中的内容原封不动的拷贝到另一个对象中
类中涉及内存资源管理时(打开文件文件指针)，拷贝构造函数，析构函数，运算符重载必须显示实现

赋值运算符的重载：默认直接把d2的内容赋值给d1(浅拷贝)，且d1原资源丢失，内存泄露
编译器生成的赋值运算符重载是按浅拷贝的方式实现的

Data d1,d3;
调用赋值运算符的重载，和函数重载不同
如果一个类没有显示实现赋值运算符重载函数，则编译器
作用：提高代码的可读性
d1=d3;

如果类中涉及到资源管理时，赋值运算符重载必须显示定义,不能重载的操作符只有:点.三目运算符?:作用域访问符::运算符sizeof以及.*
赋值运算符重载与函数重载没有任何关联
函数重载：相同作用域，函数名相同，参数列表不同

= 就是赋值运算符
运算符重载不等于函数重载
可以提高代码的可读性
返回值类型operato操作符

const Data& d,加引用是因为防止调用拷贝构造创建一个新的类对象，this是=的左操作符，const Data& d是=的右操作符
d1=d2;    等价于--->  d1.operator=(d2);可以看看反汇编一模一样
d1=d2=d3;  -->  d1.operator=(d2.operator=(d3))
反汇编中可以看到d3给d2赋值，d2给d1赋值

自定义类型(类，结构体)，在返回和传参时能用引用尽量用引用，一般来说这样效率更高
赋值运算符重载有返回值，在赋值之前应该判断是否是原变量
面试4个注意点： 1.返回值类型Data&  2.参数列表const Data& d  3.判断是否给自己赋值if(this!=&d)  4.返回值return *this
格式：
Data& operator=(const Data& d)
{
	if(this!=d)
	{
		...;
	}
	return *this;
}
Data& operator++()	//运算符重载++是前置++
{
	_day++;
	return *this;
}
Data operator++(int)必须用int	//后置++，定义一个临时对象temp,返回值没有++，而传进去的this++了
{
	Data temp(*this)
	_day++;
	return this;
}
Data* operator&()  //无法打印const创建的对象，加const可以const Data* operator&()const
{
	cout<<this<<endl;
	return this;
}
bool operator==(const Data& d)const  //加const之后this指针指向的内容不能改变，增加了安全性
{
	//++_day;  该语句报错 
}
一般不修改this成员变量的值时，成员函数之后都要加const修饰,
const的对象无法调用非const的成员函数

const修饰的成员函数内不能调用非const函数，原因:非const函数内可以修改传递的this指针
非const修饰的成员函数内可以调用const函数，原因;传递的this权限更大

构造函数是对当前对象中的成员变量在进行赋值，并不是初始化  const int a;不能在构造中“初始化”
初始化和赋值的区别？
Data(int year = 1900, int month = 1, int day = 1)
	:_year(year)
	,_month(month)
	,_day(day)			//这才是真正的初始化
{
	_year=15;
	_month=14;			//在构造函数体内
	_day=5;				//这是赋值
}
初始化规则
1.必须在构造函数初始化列表位置进行初始化的成员：引用类型的成员，const类型的成员，A中包含B的对象，并且B只具有非全缺省构造函数
2.初始化顺序必须和声明时，成员变量的顺序一致
*/
/*
代码运行步骤：
void TestDate()
{
	Date d1(2020,10,14);
	d1=TestDate3(TestDate3(d1));
}
Date TestDate3(Date d)
{
	return d;
}
int main()
{
	TestDate();
	return 0;
}
构造d1->拷贝构造d->拷贝构造ret->销毁d->拷贝构造d->销毁ret->返回(编译器优化了拷贝构造临时对象，直接返回d)->操作运算赋值->销毁d->销毁d1
在Linux下可能运行结果不同!!!!

*/
/*
static可以修饰变量和函数
函数：改变函数的链接属性，表明该函数只能在当前文件中使用
变量：全局：该变量具有文件作用域
	  局部：该变量为全局变量
静态成员变量必须在类外进行初始化
*/