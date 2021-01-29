/*
* 查询Linux下栈空间的大小
* C/C++内存分布图解析？
* 为什么要分区？

C语言内存管理：
	相同点：malloc,calloc,realloc
		malloc，calloc，realloc返回值类型都是void*，接收时必须强转(type*)，并且申请完毕要进行判空
	区别：
		malloc(size);
		calloc(num, size);并会给内容初始化成0
		realloc(void* p, size_t size);将p指向的堆空间大小调整到size字节(扩容或缩小)，如果p指针为NULL，则realloc功能和malloc相似，直接申请空间并返回void*
		若扩容很大，且新空间会占用其它未释放的内存空间，编译器会在内存新开一个空间并把原空间数据拷贝过来，然后释放原空间

C++内存管理：
	C++中使用malloc申请空间造成的问题：
		1.用malloc在堆上创建的对象，并不是真正的对象因为没有调用构造函数，而是与类空间大小相同的东西，在free是
	C++动态内存管理方式：
		1.申请单个类型的空间：new   释放单个类型空间：delete
		2.申请连续类型的空间：new[] 释放连续类型空间：delete[]
	使用示例：
		int* p1=new int(10);					 用10初始化
		int* p2=new int[10]{1,2,3,4,5,6,7,8,9,0};申请连续空间并初始化
		delete p1；A
		delete[] p2;
	malloc和new的区别：
		new是C++中的一个关键字，malloc是库函数内的，因此要头文件引入
		new不需要判空，malloc必须判空，new内部实现不存在返回空的情况
	用new构造对象
		Test* p1=new Test(100);					//会调用构造函数(类内成员t被初始化成1)，因此生成的为对象
		Test* p2=(Test*)malloc(sizeof(Test));	//不会调用(类内成员t没有初始化)，因此只能称为和类类型大小相同的堆空间
		delete p1;								//会调用析构函数，清理
		free(p2);								//只会释放开辟的空间
	小结：
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
元素访问：支持随机访问+operator[](size_t index)--->跟assert用法差不多
						at--->很少用，错误时报异常out_of_range
string类型的对象遍历
1.for()
2.范围for：auto 内部实现也是迭代器
3.迭代器：

创建string s("hello world");创建一个字符串类型
长度s.length();--->不带'\0'
长度s.size();--->和length用法一致，为什么加size，因为容器中有很多写的size，为了让参数同一，加了个size成员
清空s.clear();清空后字符串里仍有一个'\0'，但size=0
扩大或缩小有效长度s.resize(size_t n, char c);修改有效元素(size)到n个，扩大并用c来扩充，若扩大size大于或者等于容量则容量增大。缩小到n，则有效元素减少(size)，后面的内容丢失，但容量不变
				  s.resize(size_t n);没有给出扩充字符c，扩容到n，则用'\0'补全。缩小一般用不传参的
resize扩大步骤：和顺序表的扩容一样,申请新空间，拷贝原空间内容，释放原空间
扩大容量s.reserve(size_t newcapacity);修改容量(capacity)到n个，若n<=原始容量，且n>15则不会发生任何变化，若n<=15则容量才会缩小到15
若n>原始容量，则容量变大

vs中sizeof(string)==28和预期12字节多了16字节，vs为了提高string类型的性能，内部管理了一个固定大小的数组16字节,因此用户在构造string类型对象时，如果有效字符个数小于等于15个时，利用自己内部静态数组保存信息
，超过15个则动态开辟，这样小于等于15就能直接使用，大大的提高了效率
下来调研：strtok
用a.Swap()而不用Swap()原因？
个人猜想：自己定义的函数运行时开辟额外的函数调用栈浪费时间空间
怎么将string类型转换成c里面的字符类型？
int value=atoi(s.c_str());
其他方法？

STL解决问题：
1.找一个字符串的子串
	先获取特定子串的位置，用
2.找最后一个单词(每个单词中间以空格分割，多行输入)
	cin是以空格为结束标志的，无法接收空格分割的
	解决：1.用gets()可以，但太浪费空间了
		  2.getline(cin，s);
	多行输入while(getline(cin,s))
3.将用户所给的单词输出
	while(cin>>year>>month>>day)

s1>s2,这种比较和strcmp
课后调研：
为什么不选择以固定步长进行扩容？
成倍的扩容方式可以保证常数的时间复杂度，而固定步长却只能达到O(n)的时间复杂度，因此采用成倍的方式进行扩容
为什么vs1.5倍，Linux2倍
如果以大于两倍的方式进行扩容，那么新申请的空间会大于之前分配内存的综合，导致原始分配的内存不能被使用

iterator:迭代器 sub:子
push_back：插入一个字符
append：追加字符串  
+=：追加字符串
find  找到返回该字符串的位置，否则返回npos(可能其本质就是0)
substr：从某个位置开始截取后面n个字符串（子字符串）
erase
问题：再C语言中"qwer"是const类型的字符常量，为什么这里可以直接传
个人猜测：编译器会强转成char*类型
循环接收一行
while（getline（cin，s））；
while（cin>>s）；

如果能预见到容量大概是多少，最好先把容量设置好，避免一边插入一边扩容降低效率。
字符串比大小是：从前到后按asc码一个个比较,string s1,s2;s1<s2的比较规则和strcmp相同

类被创建出来默认生成6个成员函数：构造，拷贝构造，析构，赋值运算符重载，两个&的重载
其中拷贝构造，赋值运算符重载没有显示定义会造成浅拷贝
浅拷贝：将一个对象中的内容原封不动的拷贝到另一个对象中，用了同一块物理内存，在释放时会产生6号信号而崩溃，double free
深拷贝：内存地址不同，但存储的内容一模一样
博客写string.h里面的库函数,strcpy、strcmp
下面实现一个string类：
古代版：
	构造：参数列表应该缺省，还应该判断是否传进来的是nullptr空指针，是则生成空字符串（即把\0放进去），strcpy（）会将'\0'也拷贝
	析构：判空
	拷贝构造：杜绝浅拷贝，在初始化时先开辟空间
	赋值运算符重载：杜绝浅拷贝，先释放原本空间，再新开辟tmp大小的空间，把tmp内容拷贝过去，并修改原空间，注意防止自己给自己赋值

现代版：
	每个函数里都有开辟、拷贝，复用性低，因此可以用swap函数进行改进，交换两个指针的指向。
	但string类作为函数返回值时，临时拷贝构造的对象的_str不为nullptr，因此析构时发生释放了未知空间，代码崩溃。
	问题：为什么string作为返回值类型时，_str有地址(随机值)？
		因为没有初始化，它有时候给的nullptr，有时候给的随机值
	解决：拷贝构造函数初始化时给this->_str赋空
	构造：常规操作
	拷贝构造：初始化时赋空，构造一个临时对象，交换临时的和this
	析构：常规操作
	赋值运算符重载：参数列表是临时拷贝构造的一份，在函数里交换指向并返回，临时在函数结束时析构

写时拷贝技术：浅拷贝+引用计数
*/
//string类的基本操作：
//容量：
//size() / capacity() / empty()
//
//
//修改：
//operator+=(ch / const char* / string)
//push_back(ch)
//insert()
//erase()
//遍历：
//for () + 下标
//范围for
//迭代器 begin() / end()
//特殊操作：
//c_str()
//find(ch, pos = 0)  可以不给pos默认从开头，给的话从给的位置开始
//rfind(ch / const char* / string, pos)
//substr(pos, n)从pos截取n个字符串
//isalpha();判断是否是字母，大小写都行
/*
迭代器失效原因：
1.引起扩容的操作
	push_back()/+=/
2.其它方式
	erase()/clear()/swap()...
如何解决：在使用前给迭代器重新赋值

解决浅拷贝引起的double free：
	1.深拷贝：传统版，现代版
	2.写时拷贝：浅拷贝的基础上，其中对象销毁或者修改时，给修改的对象新开辟一块空间

为什么把vector和string分开，vector也是任何类型数据都可以放？
	1.字符串默认要给'\0'，这是规定的，而vector放整型数据不需要'\0'
    2.string里面封装了对strlen,strcpy等各种接口需要'\0'

vector底层：start、finish、end_of_storage
迭代器iterator底层就是指针，一般用两个itrator配合使用，意思是一段数据。

遍历方式：
	1.for(auto it:ar)
	2.vector<int>::iterator it=ar.begin()
		while(it!=ar.end())		//end是最后一个位置的后面，非法位置
		{
			++it;				//对于迭代器一般都要前置++
		}
	3.for(int i=0;i<ar.size();++i)
容量操作：
	size(),capacity(),empty()
	resize(n，data)；将有效元素设置为size个，多的用num赋值
		1.n <= size; 将vector有效元素个数缩小为n
		2.n>size；多的用num赋值
			扩容方式：开辟新空间，拷贝元素，释放旧空间
	注意：若没有给data，默认给0。string是给\0
	reserve(newcapacity)；
		new>old：扩大容量
		old>new：则容量不变
		string里面若缩小到>=15,则容量不变，<15则缩小
元素操作
0.front(),back()：这两个接口返回的是引用，而begin()，end()返回的是迭代器(地址)
1.vector的扩容机制：vs1.5倍，Linux2倍
2.在使用vector和string时一定要先把容量设置好，避免一边插入一边扩容，降低效率
3.push_back()的插入机制是拷贝一份，如果是类对象则拷贝构造一份
4.insert(iterator， nums，data)；在iterator的位置插入。为什么要用迭代器呢？？
  erase(iterator_1，iterator_2)；
修改操作：
	swap()交换两个vector的机制？？

面试：迭代器失效原因：
vector的迭代器失效：本质是：指针失效-->指针如果指向一段非法的空间(该空间已经被释放了)
1.可能导致扩容的resize(),
2.用erase()删除之后,it失效。
vs里面规定迭代器指向的被释放，该迭代器就失效了，其实可能有效
解决：在有可能引起迭代器失效的位置之后，重新给迭代器赋值
代码：使用迭代器将vector的元素都删除，erase的返回值是迭代器，且是删除位置的后面那个位置的迭代器

vector二维数组用法：vector<vector<int>> ar(5,vector<int>(5,{}))
*/


/*
list链表的封装
list为什么带头结点并且是循环链表：
	1.头删和头插方便，找尾方便
	2.end的位置就是头结点(最后一个元素的后面)
怎么查找一个元素：
	find(begin(),end(),data);
insert的三种方式
	insert(pos,data)/insert(pos,n,data)/insert(pos,first,last)
特殊操作
	remove(data);删除所有值为data的元素
	remove_if(Pre):按照指定条件进行删除，传入函数指针

在写链表前问清楚:是否带头结点
list的迭代器不是原生态的指针，因为it++要能实现到达下一个节点，因此
即T* 和 Node*都不行

封装迭代器的类中需要提供的方法：
	1.构造函数---通过构造函数构造一个迭代器的对象与元素结合
	2.迭代器需要进行比较
	3.迭代器具有指针类似的操作：解引用  ->
	4.迭代器要能移动： 前置++和-- 后置++和--  --操作单链表无法实现
给一个容器增加迭代器：
	1.将指针封装成一个迭代器的类
	2.在容器中给迭代器类型重新命名 typedef 迭代器类型
	3.
后置++这里返回值：为什么不引用，因为tmp是临时创建出来的，返回时应该重新拷贝一份

list里面的迭代器本质是一个类ListIterator，类的别名是iterator。这个类中封装了一系列类似指针的操作


vector和list的共性和差异：
		vector         list
共性： 

*/


/*
优先级队列模板参数列表：
template<class T, class Container = vector<T>, class Com = less<T>>
priority_queue<int, vector<int>, greater<int>> ar;创建一个小堆
priority_queue<int, vector<int>, Less> ar;		  创建一个大堆
prio
class priority;
问题：
	1.为什么使用vector存储元素
	2.默认按照less对priority_queue中的元素进行比较，创建出来的是一个大堆
	3.创建小堆，应该怎么设置比较方式
	设置比较方式：
		1.函数指针，typedef bool (*Handler_)(Data,Data)
		2.仿函数(函数对象)：可以像函数一样使用，其本质是一个对象！！
		3.lambda表达式

bool operator< (const Data a)
{
	return 
}
问题：如果push的时候传的是地址，那么


接口：
	构造：
	priority_queue();
	priority_queue(first, last);	左闭右开
	操作：
	void push(const T& data);
	void pop();
	const T& top()const; 获取堆顶元素，不能修改，const修饰
*/
/*
创建堆：
1.找调整位置：(size - 1) / 2 ；--->size=nums.size()-1;
2.for循环，每个位置都向下调整
3.进入调整函数，记录当前父节点位置，然后向下调整
	左孩子：left = root * 2 + 1； 
问题：为啥在删除操作的时候，不直接 while(child > 0 && .....);

每次加<int>是给模板设置类型，


1.理解什么是仿函数，怎么使用仿函数
2.什么是函数指针，怎么使用

模拟实现：
	容量适配器:
	stack           ----》vector
	queue           ----》list
	priority_queue	----》vector 和 堆算法	
	都是容量适配器，其实就是将容器封装一下，接口提供给用户，类似(最小栈,最大队列)
STL实现：stack、queue和priority_queue使用的是deque双端队列
	deque可进行双端的插入和删除，都是O(1)的时间复杂度
		问题：连续空间为什么头插，时间复杂度也为O(1)?
		答：多端连续的空间保证数据的存储，(头插的话反向填充)，再来一个类似Linux中的页表的东西叫map，用来管理地址
	可以画个图：map存储各个连续空间的首地址，迭代器中有4个指针，分别是cur, first, last, node -> map

双端队列优点：1.插入、删除效率很高
			  2.扩容效率也很高
缺点：遍历效率低，但stack和queue都不能遍历，因此STL为了追求高性能采取了deque

为什么STL使用双端队列而不是vector和list
	对于vector：扩容时优点很大
	对于queue：
*/