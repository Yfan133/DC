//为什么要内存对齐？
//默认对齐参数？如何对齐设置？默认对齐设置可以设置为任意值吗？
//vs:8字节       #prgma pack(4)     必须设置成2的n次方
//怎么求结构体内成员变量的起始偏移量？offsetof(AA.c)模拟实现（百度笔试题）
//什么是大小端？写一个程序判断机器的大小端？（多种方法）说一个情景要考虑大小端问题。大小端和操作系统有没有关系？
////////////////////////////////////////////////////////////////////////////
/*
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
static可以修饰变量和函数
函数：改变函数的链接属性，表明该函数只能在当前文件中使用
普通变量：全局：该变量具有文件作用域
		  局部：该变量为全局变量
成员变量：变成类的属性

静态成员变量必须在类外进行初始化,没有包含在具体的对象中，所有对象共享的且只有一个，是类的属性因此不影响sizeof的值
public:
	static int count;  静态成员变量，是类的属性
初始化：int Date::_count = 0;
不创建对象访问静态成员变量:cout<<Date::_count<<endl; (->等价于) cout<<d1._count<<endl;

count一般设置为private
那怎么在类外调用count：static int GetCount(){return _count;}  静态成员函数
通过调用成员函数Date::GetCount();返回count
静态成员函数内没有隐藏的this指针，因此函数体内不能有非静态成员变量和成员函数(普通成员变量在成员函数内访问都是通过this指针)
静态成员函数默认调用约定_cdecl	默认调用约定_thiscall
静态成员函数内不能访问非静态的，但非静态成员函数内可以访问静态的

输出运算符<<重载后调用是反的，因为第一个参数为隐藏的this指针，因此不能重载为成员函数，左操作数和右操作数
void operator<<(Date* const this,ostream& _cout)
{
	_cout<<_year;
}
d1<<cout;  -> d1.operator(cout);
运算符重载为全局函数
ostream& operator<<(ostream& _cout,const Date& d)
{
	_cout<<d._year;
	return _cout;
}
cout<<d1;   -> operator(_cout,d1);
加上返回值之后可以多组输出cout<<d1<<10;相当于d1调用了我们重载的函数，10调用了系统内置函数
但成员变量私有化后，运算符重载不能直接调用，解决：类中写Get函数这样写浪费时间空间，友元函数
friend ostream& operator<<(ostream& _cout,const Date& d);
友元函数可以访问类的私有和受保护成员
友元函数不是类的成员函数
友元类不是相互的，也不具有传递性
内部类和外部类没有关系
sizeof(外部类)大小跟内部类没关系
class List
{
	struct ListNode
	{
		ListNode(int data)
	}
}
*/
//问题：静态成员变量存放在哪？猜想：全局数据区

/*
动态内存管理，内存分布
查询Linux下栈和堆的默认空间大小
内核				共4G
环境变量，环境参数
栈					栈帧：存放函数的参数，局部变量，寄存器的信息 (函数结束，栈帧释放)
共享区
堆					堆区：动态内存申请，malloc,calloc,realloc，必须用free释放
数据区				全局变量，被static修饰的数据  (生命周期和程序一致，程序退出数据清空)
代码区				代码和只读常量
数据类型不同，对数据的管理方式也不同，所以要划分不同区域
总结：sizeof和strlen的区别？
malloc，calloc，realloc返回值类型都是void*，接收时必须强转(type*)
malloc(size);
calloc(num,size);并会给内容初始化成0
realloc(*p,size);将p指向的堆空间大小调整到size字节(扩容或缩小)，如果p指针为NULL，则realloc功能和malloc相似，直接申请空间并返回void*
若扩容很大，且新空间会占用其它未释放的内存空间，编译器会新开一个空间并把原空间数据拷贝过来，然后释放原空间

*/
