#include"main.h"
//引用(类型名& +引用变量名):给已知变量取一个别名,使用的同一内存空间(类似不带*的指针)
//引用类型必须和引用实体类型一致，且定义时必须初始化,引用一个实体后就不能引用其他实体了
//const 常量 不能引用,系统直接报错
//思考题:
//在C语言中,写一个函数

//注意:以引用方式作为函数返回值时,不能返回栈空间(局部变量)
//Add函数结束ret不存在,但是result引用ret(共用一个空间),栈帧并没有清理,所以&result的结果没变(仍然指向ret的地址)
//继续使用Add函数,栈帧内容会被新数据覆盖,因此result的内容被修改
//_cdecl是函数默认的调用约定(函数在调用期间所做的一些约定)
//传值:效率较低
//传地址:效率高,通过形参可以改变实参
//传引用:效率高,可达到类似指针的效果
//代码

//引用和指针的区别:反汇编中底层代码完全相同---引用就是指针,不同点:空间大小不同(指针4字节,引用和实体一致,例如:代码),没有多级引用但是可以多级指针
//反汇编图片
//int&等价于int* const(指针指向不能修改)(引用只能和一个实体结合,不能修改)
//const int&等价于const int* const

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int& Add(int left, int right)
{
	int ret = left + right;
	return ret;
}
//int& result = Add(1, 2);	
	//cout << result << endl;				//输出结果为3(函数结束局部变量ret被释放,但&result指向的栈帧空间未被清理)
	//Add(3, 4);							//result的内容被修改为7
	/*int a = 1, b = 2;
	Swap(&a, &b);
	Swap(a, b);*/
	/*int a = 10;

	int& ra = a;
	ra = 20;

	int* pa = &a;
	*pa = 20;*/
int main()
{
	char a = 'a';
	char& ra = a;
	char* pa = &a;
	cout << sizeof(ra) << endl << sizeof(pa);
	return 0;
}