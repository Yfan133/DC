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

static修饰的成员变量在程序开始执行就被创建出来了，识别类时就创建出来，static具有文件作用域，必须在类外进行初始化
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
友元函数是在类外的函数所以没有this指针
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
Linux下栈空间大小8192kb=8M
Windows下栈空间  1024kb=1M
内核				共4G
环境变量，环境参数
栈					栈帧：存放函数的参数，局部变量，寄存器的信息 (函数结束，栈帧释放)
共享区
堆					堆区：动态内存申请，malloc,calloc,realloc，必须用free释放
数据区				全局变量，被static修饰的数据  (生命周期和程序一致，程序退出数据清空)
代码区				代码和只读常量
数据类型不同，对数据的管理方式也不同，所以要划分不同区域
总结：sizeof和strlen的区别？
sizeof开辟的空间大小
strlen遇到‘\0’停下
malloc，calloc，realloc返回值类型都是void*，接收时必须强转(type*)
malloc(size);
calloc(num,size);并会给内容初始化成0
realloc(*p,size);将p指向的堆空间大小调整到size字节(扩容或缩小)，如果p指针为NULL，则realloc功能和malloc相似，直接申请空间并返回void*
若扩容很大，且新空间会占用其它未释放的内存空间，编译器会在内存新开一个空间并把原空间数据拷贝过来，然后释放原空间

C++中用malloc在堆上创建的对象，并不是真正的对象因为没有调用构造函数，而是与类空间大小相同的东西，在free是
C++动态内存管理方式：申请单个类型的空间：new   释放单个类型空间：delete
					 申请连续类型的空间：new[] 释放连续类型空间：delete[]
int* p1=new int(10);					 用10初始化
int* p2=new int[10]{1,2,3,4,5,6,7,8,9,0};申请连续空间并初始化
delete p1；A
delete[] p2;
new是C++中的一个关键字，malloc是库函数内的，因此要头文件引入
new不需要判空，malloc必须判空，new内部实现不存在返回空的情况
Test* p1=new Test(100);					//会调用构造函数(类内成员t被初始化成1)，因此生成的为对象
Test* p2=(Test*)malloc(sizeof(Test));	//不会调用(类内成员t没有初始化)，因此只能称为和类类型大小相同的堆空间
delete p1;								//会调用析构函数，清理
free(p2);								//只会释放开辟的空间
new/delete  new/delete[]  malloc/free  一定要匹配使用，否则程序可能会崩溃或者内存泄露
写博客有没有内存泄露，如何检测内存泄露在哪，为什么自定义类型(类)没有匹配使用会崩溃？
new的工作方式：
1.申请堆空间（为什么new申请的空间不用判空）
	调用void* operator new(size_t size)申请空间--->内部使用了malloc，失败(内存资源占满)则调用_callnewh(size)函数(用户提供的解决内存不足措施)，用户实现了执行，失败则抛出bad_alloc异常
2.调用构造函数对申请的空间进行初始化
delete的工作方式：
1.调用析构函数，清理对象中资源
2.调用void operator delete(void* p);内部使用--->free() 释放空间
new T[N]
1.申请空间，调用void* operator new[](size_t size);申请空间
operator new[] --->内部调用了operator new函数
2.调用N次构造函数，初始化N个对象
delete[] p
1.调用N次析构函数对p所指向的空间资源进行清理
2.调用void operator delete[](void* p)对p所指向的空间进行释放 --->内部调用了operator delete函数

问题：既调用了析构函数释放空间，又调用delete释放空间，不会因为释放同一空间两次而崩溃吗？
析构是清理N个对象内部的资源(成员变量)，delete是释放空间（清除对象）

new/delete 是关键字，也可以成为操作符--new 操作符
在C++中一般不对四个operator进行重载，除非特殊要求，打印new创建的位置
用malloc开辟的类空间不能称为对象，可以用new(pt) Test(100)去用构造初始化
但不能直接用free()释放
pt->~Test();
free(pt);		先析构再释放就可以完成工作了
也就是说new 相当于---> 先malloc 再new+构造
	 delete 相当于---> 先析构   再free()
*/
//快捷键alt+鼠标拖动
//编译器中显示指针空间,监视p1,10
/*
malloc 创建的在内存上面有个结构体，保存所创建空间大小为32字节，下面4个字节以防越界
placement new ---定位new表达式
内存池---内存管理，创建的空间给类分配时，要定位new表达式，执行构造函数初始化成对象
new(地址)T(参数)： 1.调用operator new()函数  （用户重载后的，不用malloc）
				   2.
malloc申请的一定在堆上，new的可能在自由存储区上(用户把new重载之后，new可能在栈或者磁盘上开辟空间)
查资料：深度理解内存泄露
内存泄露：因错误造成程序未能释放不再使用的内存，造成丢失对该内存的使用，会使程序越来越卡
1.堆内存泄露
	
2.系统资源泄露
	
*/
/*
模板初阶：
全部用重载缺陷：
1.代码复用性较低
2.不好维护
3.不能将所有类型重载(自定义类型)
模板：可实现一些与类型无关的代码
泛型编程：与类型无关，与数据结构无关

*/