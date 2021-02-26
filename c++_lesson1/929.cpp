
/*
堆的概念：
	将集合中的数据放置在一维数组中(完全二叉树)，必须满足：如果树中任意节点比其子节点都大，则是大堆
堆的特性：
	堆顶元素一定是最大的
优先级队列模板参数列表：
	template<class T, class Container = vector<T>, class Com = less<T>>
	priority_queue<int, vector<int>, greater<int>> ar;创建一个小堆
	priority_queue<int, vector<int>, less<int>> ar;		  创建一个大堆
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
	priority_queue(first, last);
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
#include <queue>
using namespace std;
int main()
{
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(10);
	q.push(1);

	return 0;
}