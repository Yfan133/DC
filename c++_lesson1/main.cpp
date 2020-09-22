#include"main.h"
//C++中被const修饰的变量称为常量,而且被const修饰的常量还具有类似宏替换的作用
//C语言中被const修饰的不是常量(而是变量只是不能修改)
//例子：数组的定义时  int ar[a];C语言报错,C++编译通过

//宏函数的缺点：1.意想不到的副作用 2.在预处理替换，少了类型检测 3.不能调试
//内联函数(吸收宏的优点)
//debug模式下内联函数默认是不会展开,可以调试，如果想展开
//release模式下
//在其他文件中调用Add函数则会发生链接错误，因为编译器
//inline函数具有文件作用域(跨文件用不了)
//内联函数和宏的共同缺点：会使代码膨胀(本来就一句call,现在是替换成多条语句)
//在C语言中aoto用来修饰局部变量,表明该变量是自动变量,函数结束,变量自动销毁
//C++中auto：自动类型推断,定义变量时必须初始化.例：auto e;系统报错
inline int  Add(int left, int right)
{
	return left + right;
}
int main()
{
	char a = 'a';
	int b = 1;
	float c = 1.0;
	double d = 1.2;
	auto e = a * b + c + d;

	/*int a = 1; int b = 2;
	Add(a, b);*/
	return 0;
	//看回放为啥const int*
	//const int a = 10;
	//int* pa = (int*)&a;//&a ---> const int*
	//*pa = 100;
	//cout << a << endl << *pa << endl;//a在编译时被替换成常量10,其实不是宏替换但效果一样,宏替换是在预处理阶段，const是在编译阶段替换
	//宏和const底层代码一样，为什么一个是编译阶段一个是预处理阶段
	//例子：两个替换报错位置不同,宏在使用位置报错,const在定义时报错
	/*
	#define PI "3.14";
	const char pi ="3.14";
	b=PI*2*3;在这一行报错但式子并没有问题，原因：预处理之后PI被替换为"3.14"看不到PI了，因此在此处报错
	b=pi*2*3;在const处报错，编译时报错
	*/
	//因此C++中更建议用const取代C语言的宏,因为const修饰的已经是常量,而且会进行类型检测
}