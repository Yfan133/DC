#pragma once

#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable : 4996)
namespace my_que
{
	// 模板参数列表：T：元素类型  Container：底层数据组织格式  Com：比较方式
	template <class T, class Container = vector<T>, class Com = less<T>>
	class priority_que
	{
	public:
		priority_que()
		{}
		// 迭代器构造
		template <class Iterator>
		priority_que(Iterator begin, Iterator end)
			: _con(begin, end)
		{
			// 1.先插入数组，再从最后一个非叶子分支开始，对每个节点向下调整
			size_t n = _con.size() - 1;
			size_t node = (n - 1) >> 1;
			for (; node >= 0; --node)
			{
				_AdjustDown(node);
			}
		}
		void push(const T& data)
		{
			// 1.先插入数组最后，然后向上调整，直到根节点或者找到合适位置
			_con.push_back(data);
			size_t child = _con.size() - 1;
			while (child)
			{
				size_t parent = (child - 1) >> 1;
				if (Com()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
				}
				else
					return;
			}
		}
		void pop()
		{
			// 1.先交换首尾数据，删除尾部数据，然后将首数据向下调整
			if (_con.empty())
				return;
			swap(_con.front(), _con.back());
			_con.pop_back();
			_AdjustDown(0);
		}
		const T& top()const
		{
			return _con.front();
		}
		size_t size()const
		{
			return _con.size();
		}
		bool empty()const
		{
			return _con.empty();
		}
	private:
		void _AdjustDown(size_t parent)
		{
			// 1.找到左右子树中较大的
			// 2.交换
			// 3.循环直到越过元素总数
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && Com()(_con[child], _con[child + 1]))
					child += 1;
				if (Com()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					return;
			}
		}
	private:
		Container _con;
	};
}
void TestMyPriorityQueue1()
{
	my_que::priority_que<int> q;
	q.push(3);
	q.push(7);
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(6);
	q.push(5);

	cout << q.size() << endl;
	cout << q.top() << endl;

	q.pop();
	cout << q.size() << endl;
	cout << q.top() << endl;
}


template<class T>
class Greater
{
public:
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

void TestMyPriorityQueue2()
{
	my_que::priority_que<int, vector<int>, Greater<int>> q;
	q.push(3);
	q.push(7);
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(6);
	q.push(5);

	cout << q.size() << endl;
	cout << q.top() << endl;

	q.pop();
	cout << q.size() << endl;
	cout << q.top() << endl;
}

////////////////////////////////////////////////////////
#include <queue>
typedef bool(*Handler_)(int a, int b);
bool Greater(int a, int b)
{
	return a > b;
}
struct Compare
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
class Date
{
public:
	Date(const int& a)
		: a_(a)
	{}
	int GetA()const
	{
		return a_;
	}
private:
	int a_;
};
struct Com
{
	bool operator()(Date* d1, Date* d2)
	{
		return d1->GetA() < d2->GetA();
	}
};
void Test1()
{
	// 默认按照大堆的方法less
	priority_queue<int, vector<int>> q;
	// 建立小堆
	priority_queue<int, vector<int>, greater<int>> q1;
	// 函数指针建立小堆
	priority_queue<int, vector<int>, Handler_> q2(Greater);
	// 仿函数建立小堆
	priority_queue<int, vector<int>, Compare> q3;
	q3.push(1);
	q3.push(2);
	q3.push(3);
	q3.push(4);
	q3.push(5);
}
void Test2()
{
	priority_queue<Date*, vector<Date*>, Com> q;
	Date d1(10);
	Date d2(20);
	Date d3(50);
	Date d4(15);
	Date d5(90);
	Date d6(60);
	Date d7(70);
	Date d8(55);
	Date d9(56);

	q.push(&d1);
	q.push(&d2);
	q.push(&d3);
	q.push(&d4);
	q.push(&d5);
	q.push(&d6);
	q.push(&d7);
	q.push(&d8);
	q.push(&d9);
}