/*
为什么把vector和string分开，vector也是任何类型数据都可以放？
	1.字符串默认要给'\0'，这是规定的，而vector放整型数据不需要'\0'
    2.string里面封装了对strlen,strcpy等各种接口需要'\0'
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
	根本原因：链表底层不是连续的空间而是一个个封装的节点,vector、string底层都是连续的空间
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
迭代器模式
1.概念
	是一种设计模式(经验思想的总结),设计一种结构便于遍历容器中的数据，而不会暴露容器实现细节
2.作用
	是STL中算法和容器之间的纽带，算法是通用类型的必须通过迭代器使用，与数据类型和数据结构都无关
3.迭代器由谁来实现，如何实现
	1.谁实现的容器谁实现迭代器
	2.根据底层数据结构，遍历规则
		a.封装迭代器的类
			对原生态指针进行的管理
			指针类似操作：operator*()、operator->()
			迭代器移动：
			迭代器比较：
		b.取别名
		c.增加begin()/end()家口
4.迭代器失效
5.举例：vector，list
6.如何解决：
	在可能造成迭代器失效的地方都重新给迭代器赋值
*/

/*
容器简介：一些模板类的集合，和普通模板类不同的是，容器封装了组织数据的方法和算法
分类：
	1.序列式容器：底层数据的存储是线性的，这类容器对存储的元素不会排序
		string：动态顺序表，末尾是'\0'
		vector：动态顺序表
		list：带头结点的双向循环链表
		priority_que：vector + 堆算法的封装
	2.关联式容器：组织底层数据时，是以键值对形式存储的
		map：映射容器-》底层红黑树
		set：集合容器-》
		multimap：多重映射容器
		multiset：多重集合容器
	3.无序关联式容器：
		unordered_map：哈希映射-》
		unordered_set：哈希集合
		unordered_multimap：哈希多重映射
		unordered_multiset：哈希多重集合
容器适配器：
	stack(栈)：由于其特点：后进后出，插入/删除最后一个元素，底层使用了vector
	queue(队列)：由于其特性：先进后出，插入:尾部,删除:头部，底层使用了list
	STL中使用的是 deque双端队列
*/

/*
堆的概念：
	将集合中的数据放置在一维数组中(完全二叉树)，必须满足：如果树中任意节点比其子节点都大，则是大堆
堆的特性：
	堆顶元素一定是最大的
优先级队列模板参数列表：
	template<class T, class Container = vector<T>, class Com = less<T>>
	priority_queue<int, vector<int>, greater<int>> ar;创建一个小堆
	priority_queue<int, vector<int>, Less> ar;		  创建一个大堆
	prio
class priority;
问题：
	1.默认采用vector作为容器
	2.默认按照less对priority_queue中的元素进行比较，创建出来的是一个大堆
	3.创建小堆，应该怎么设置比较方式
		设置比较方式：
		1.函数指针，typedef bool (*Handler_)(Data,Data)
		2.仿函数(函数对象)：可以像函数一样使用，其本质是一个对象！！
		3.lambda表达式

问题：如果push的时候传的是地址，那么默认的比较方式，会对指针地址进行比较，得不到对象成员比较的结果
	解决：自己写比较方式：写一个仿函数，比较对象成员的大小


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

1.理解什么是仿函数，怎么使用仿函数
2.什么是函数指针，怎么使用

模拟实现：
	容量适配器:
	stack           ----》vector
	queue           ----》list
	priority_queue	----》vector 和 堆算法	
都是容量适配器，其实就是将容器封装一下，接口提供给用户，类似(最小栈,最大队列)

设计模式：迭代器，适配器

STL实现：stack、queue和priority_queue使用的是deque双端队列
	deque可进行双端的插入和删除，都是O(1)的时间复杂度，底层实现是连续空间
		
	问题：为什么连续空间进行头插，时间复杂度也为O(1)?
		答：底层实现时，使用了多段连续的空间保证数据的存储，(头插的话反向填充)，再来一个类似Linux中的页表映射的东西叫map，用来管理地址
	可以画个图：map存储各个连续空间的首地址，迭代器中有4个指针，分别是cur, first, last, node -> map

双端队列优点：1.插入、删除效率很高
			  2.扩容效率也很高：相对于vector的扩容-》开辟，拷贝，释放三个步骤而言，效率更高只需要开辟新空间并使用
缺点：遍历效率太低，但stack和queue都不能遍历，因此STL为了追求高性能采取了deque

为什么STL使用双端队列而不是vector和list
	对于vector：扩容时优点很大
	对于queue：deque底层空间连续，避免了大量的内存碎片
*/


/*
堆的创建方法：
	1.找到最后一个非叶子分支
	2.向下调整，直到调整到根节点
	3.大堆创建完成
删除算法：
	1.将根节点和最后一个节点进行交换
	2.size--，将根节点向下调整
插入算法：
	 1.将新增节点插入最后一个位置
	 2.向上调整，直到根节点或者小于父节点
*/
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
	list<int> l1{ 1,2,3 };
	auto it = find(l1.begin(), l1.end(), 2);
	return 0;
}