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
//#pragma pack(4)
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;
public:
	// 成员函数
	// 看起来该函数有三个参数，实际上有4个参数
	// 另外一个参数是：隐藏的this指针
	// 在写代码期间，用户不用显式给出this指针，编译器在编译代码时，会自动加上this指针的参数
	void InitStudent(char name[],char gender[], int age)
	{
	//	// 不能给this指针来进行赋值----Student* const this
	//	//                          类类型* const
	//	//this = nullptr;

	//	cout << this << endl;

	//	// 有了this指针，成员函数就知道现在是在操作那个对象
	//	// 注意：对成员变量的操作都是通过this指针来进行的
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	// 注意：成员函数如果在类内部类进行定义，成员函数可能会被编译器当成内联函数来对待
	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(s1) << endl;
	return 0;
}
//什么是结构体内存对齐？为什么需要内存对齐？
//为了提高程序性能，数据结构(尤其是栈)在内存中对齐。未对齐的内存处理器要访问两次，对齐的内存访问一次
//默认对齐参数？如何对齐设置？默认对齐设置可以设置为任意值吗？
//vs:8字节       #prgma pack(4)     必须设置成2的n次方
//怎么求结构体内成员变量的起始偏移量？offsetof(AA.c)模拟实现（百度笔试题）
//
//什么是大小端？写一个程序判断机器的大小端？（多种方法）说一个情景要考虑大小端问题。大小端和操作系统有没有关系
//#pragma pack(4)
//#pragma pack()恢复默认值
