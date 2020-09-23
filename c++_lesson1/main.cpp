#include"main.h"
//在C语言中aoto用来修饰局部变量,表明该变量是自动变量,函数结束,变量自动销毁
//C++中auto：自动类型推断,定义变量时必须初始化.例：auto e;系统报错
inline int  Add(int left, int right)
{
	return left + right;
}
inline int Max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	Add(1, 2);
	return 0;
}