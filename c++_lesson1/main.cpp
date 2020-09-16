#include"main.h"
//C语言文件 .c
//C++文件   .cpp
void TestFun()	//C语言中可以传很多参数  Fun(); Fun(1,2,3,4);
{				//C++中该函数不能传参数

}
//C语言中不设置函数返回类型，默认为int类 Fun()
//C++必须设置函数返回类型

//C语言参数不可设置初始值	(缺省参数)
//C++参数可以设置默认值 int Fun(int a=10)
//半缺省参数:缺省的参数必须在不缺省的右边，Fun(int a,int b,int c=1)
//因为传参默认先给最左边的赋值
//声明和定义中，缺省参数不能同时给出  例：Fun(int a=10);声明
										//Fun(int a = 10)定义
										//{				
										//}
//函数重载 概念：函数名相同，参数列表必须(数量，类型，次序)不同，则构成重载，根据传参类型调用
//         注意：如果两个函数仅仅是返回类型不同，则不能构成重载
//函数重载的调用原理:编译阶段会对函数实参类型进行推演，根据推演的实际结果找类型匹配的函数进行调用
//有完全匹配的：直接调用  
//没有与匹配的：1.先隐式转化  2.隐式转化后没有合适的或无法隐式转换直接报错
//例：有Fun(int a,int b)和Fun(double a,double b) 使用Fun(1,5.2)就会报错
int Add(int a,int b)
{
	return a + b;
}
double Add(double a, double b)
{
	return a + b;
}
void main()
{
	cout << 1 << endl << "hello,world";
	TestFun();
}