/*
resize扩大步骤：
	1.申请新空间
	2.拷贝旧空间内容
	3.释放旧空间
课后调研：
	1.strtok
	2.为什么不选择以固定步长进行扩容？
		成倍的扩容方式可以保证常数的时间复杂度，而固定步长却只能达到O(n)的时间复杂度，因此采用成倍的方式进行扩容
	3.为什么vs1.5倍，Linux2倍
		如果以大于两倍的方式进行扩容，那么新申请的空间会大于之前分配内存的总和，导致原始分配的内存不能被使用
深浅拷贝概念：类被创建出来默认生成6个成员函数：构造，拷贝构造，析构，赋值运算符重载，两个&的重载
	浅拷贝：
		1.拷贝构造，赋值运算符重载没有显示定义会造成浅拷贝
		2.将一个对象中的内容原封不动的拷贝到另一个对象中，用了同一块物理内存，在释放时会产生6号信号 SIGABRT 而崩溃，double free
	深拷贝：内存地址不同，但存储的内容一模一样
博客写string.h里面的库函数,strcpy、strcmp
*/
/*
下面实现string类：
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
list底层就是对链表的封装
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

list的迭代器不是原生态的指针，因为it++要能实现到达下一个节点，因此不能是原生态指针(例如:int* p，p++并不是指向下一个节点)
	根本原因：链表底层不是连续的空间,vector、string底层都是连续的空间
封装迭代器的类中需要提供的方法：
	1.构造函数---通过构造函数构造一个迭代器的对象与元素结合
	2.迭代器需要进行比较
	3.迭代器具有指针类似的操作：解引用  ->
	4.迭代器要能移动： 前置++和-- 后置++和--  --操作单链表无法实现
给一个容器增加迭代器：
	1.将指针封装成一个迭代器的类
	2.在容器中给迭代器类型重新命名 typedef 迭代器类型
	3.在容器中类中增加begin()/end()
后置++这里返回值：为什么不引用，因为tmp是临时创建出来的，返回时应该重新拷贝一份

list里面的迭代器本质是一个结构体ListIterator，类的别名是iterator。这个类中封装了一系列类似指针的操作

vector和list的区别：
相同点：都是STL提供的序列式容器，包含在std的命名空间中
不同点：
				 vector            list               string
1.底层结构      顺序表(连续)     链表(不连续)       顺序表且最后为\0''(连续)
2.空间利用率      较高           很低(指针四字节)      较高	 注意：考虑扩容就不一定了，双倍扩容
3.插入/删除效率   较低(元素搬移)    较高               较低
4.元素访问效率    较高(下标访问)    较低(查找)         较高
5.迭代器          原生态指针        对指针的封装       原生态指针
6.

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