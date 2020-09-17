#include"main.h"
//可以编译，不能链接(预处理,编译,汇编,链接)
//链接阶段，链接器在工程中找实现体(函数定义),


//C语言编译函数时,修饰函数名只会在函数名前加_(_Add)，所以无法进行函数重载
//C++编译时会将函数定义名修改(将参数列表添加进去),?Add@@HHH@Z(H:int型,N:double型)
//Linux中
//函数重载概念:作用域相同,返回值和参数列表不同(C++编译时修饰函数名(?Add@@XXX@Z)和C语言不同(_Add:重定义),因此可以重载)
//C++写的代码,按C语言方式进行引用,函数前加extern "C",即可按C语言方式进行编译(修饰函数名为_Add)
//extern "C"{函数1;函数2;函数3;}多个函数进行按C语言方式引用
//C++和C语言混合编程怎么处理？---采用条件编译可以处理
//有歧义的函数重载
//void Func(int data = 10)
//{
//
//}
//void Func()
//{
//
//}			当不传参数时,报错
//引用(类型名& +引用变量名):给已知变量取一个别名,使用的同一内存空间(类似不带*的指针)
//引用类型必须和引用实体类型一致，且定义时必须初始化,引用一个实体后就不能引用其他实体了
//const 常量 不能引用,系统直接报错
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
namespace add1
{
	int a;
}
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}
int main()
{
	int& r = Add(1, 2);
	Add(3, 4);
	Add(5, 6);
	return 0;
}
int Func(int left,int right)
{
	return left + right;
}