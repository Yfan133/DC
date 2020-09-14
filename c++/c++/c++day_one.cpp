//命名空间定义格式
#include<stdio.h>
namespace N
{
	int a = 10;
}
int a = 20;
int main()
{
	int a = 30;
	//::  作用域运算符
	//::  全局变量
	//命名空间+ :: 命名空间中的成员使用
	printf("%d", ::a);
	return 0;
}