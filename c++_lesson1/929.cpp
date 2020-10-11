//this指针存储在哪？
//this指针可以为空nullptr
//

#include"main.h"
/*
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
	void InitStudent(const char name[],const char gender[], int age)
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
//int main()
//{
//	Student s1;
//	s1.InitStudent("Peter", "男", 18);
//
//	s1.PrintStudent();
//	
//	cout << sizeof(s1) << endl;
//	return 0;
//}
//什么是结构体内存对齐？为什么需要内存对齐？
//为了提高程序性能，数据结构(尤其是栈)在内存中对齐。未对齐的内存处理器要访问两次，对齐的内存访问一次
//默认对齐参数？如何对齐设置？默认对齐设置可以设置为任意值吗？
//vs:8字节       #prgma pack(4)     必须设置成2的n次方
//怎么求结构体内成员变量的起始偏移量？offsetof(AA.c)模拟实现（百度笔试题）
//
//什么是大小端？写一个程序判断机器的大小端？（多种方法）说一个情景要考虑大小端问题。大小端和操作系统有没有关系
//#pragma pack(4)
//#pragma pack()恢复默认值
//
////////////////////////////////////////////////////////////////////////////
/*
一个类中有6个默认的成员函数：1.初始化和清理(构造函数和析构函数)
构造函数前不能加返回值类型，void也不行，在对象的生命周期内只调用一次，对象实例化时由编译器自动调用对应的构造函数并设置初始值
构造函数可以重载（对象实例化但不初始化时）Data(){}
Data d3();这样做编译器会认为它是函数的声明
用户没有显示定义任何构造函数---显示：用户没有写，编译器会自动生成一个无参的默认构造函数
Data d；类中没有显示定义构造函数，但类任然可以创建对象，编译器会调用Data类的无参默认构造函数
但当类中显示定义了构造函数时，编译器不会生成默认构造函数
无参的构造函数和全缺省的构造函数不能同时定义，当定义无初始值对象时，编译器不知道该调用无参还是全缺省
创建哪个类的对象编译器就会调用哪个类的构造函数

析构函数:没有返回值类型
~SeqList()
*/