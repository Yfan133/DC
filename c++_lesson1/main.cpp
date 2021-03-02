//////#include <iostream>
//////#include <string.h>
//////#pragma warning (disable:4996)
//////
//////namespace pj_string
//////{
//////	class string
//////	{
//////	public:
//////		typedef char* iterator;
//////	public:
//////		string(const char* str = "")
//////		{
//////			if (str == nullptr)
//////				str = "";
//////			_capacity = _size = strlen(str);
//////			_str = new char[_size + 1];
//////			strcpy(_str, str);
//////		}
//////		string(size_t n, char ch)
//////			:_str(new char[n + 1]), _size(n), _capacity(n)
//////		{
//////			memset(_str, ch, n);
//////			_str[_size] = '\0';
//////		}
//////		string(const string& s)
//////			:_str(new char[s.capacity() + 1])
//////			,_size(s.size())
//////			,_capacity(s.capacity())
//////		{
//////			strcpy(_str, s._str);
//////		}
//////		~string()
//////		{
//////			delete[] _str;
//////			_str = nullptr;
//////			_size = _capacity = 0;
//////		}
//////		string& operator=(string s)
//////		{
//////			std::swap(_str, s._str);
//////			return *this;
//////		}
//////		size_t size()const
//////		{
//////			return _size;
//////		}
//////		size_t capacity()const
//////		{
//////			return _capacity;
//////		}
//////		char* c_str()const
//////		{
//////			return _str;
//////		}
//////		bool empty()const
//////		{
//////			return 0 == _size;
//////		}
//////		void resize(size_t new_size, char ch = char())
//////		{
//////			size_t old_size = size();
//////			if (new_size > old_size)
//////			{
//////				if (new_size > _capacity)
//////					reserve(new_size);
//////				memset(_str + old_size, ch, new_size - old_size);
//////			}
//////			_size = new_size;
//////			_str[new_size] = '\0';
//////		}
//////		void reserve(size_t n)
//////		{
//////			if (n > _capacity)
//////			{
//////				char* newstr = new char[n + 1];
//////				strcpy(newstr, _str);
//////				delete _str;
//////				_str = newstr;
//////				_capacity = n;
//////			}
//////		}
//////		iterator begin()
//////		{
//////			return _str;
//////		}
//////		iterator end()
//////		{
//////			return _str + _size;
//////		}
//////		void push_back(char ch)
//////		{
//////			*this += ch;
//////		}
//////		string& operator+=(char ch)
//////		{
//////			if (size() == capacity())
//////				reserve(capacity() * 2);
//////			_str[_size++] = ch;
//////			_str[_size] = '\0';
//////		}
//////		string& operator+=(const char* str)
//////		{
//////			size_t len = strlen(str);
//////			if (size() + len > capacity())
//////			{
//////				char* newstr = new char[_size + len + 1];
//////				strcpy(newstr, _str);
//////				delete _str;
//////				_str = newstr;
//////			}
//////			strcat(_str + _size, str);
//////			_capacity = _size += len;
//////			return *this;
//////		}
//////		string& operator+=(const string& s)
//////		{
//////			*this += s.c_str();
//////			return *this;
//////		}
//////	private:
//////		char* _str;
//////		size_t _size;
//////		size_t _capacity;
//////		static size_t npos;
//////	};
//////	size_t string::npos = -1;
//////}
//////void Test1()
//////{
//////	pj_string::string str("qwer");
//////	pj_string::string str1 = str;
//////	pj_string::string str2(str);
//////}
//////pj_string::string Test2()
//////{
//////	pj_string::string str("wqer");
//////	return str;
//////}
//////void Test3(pj_string::string str)
//////{
//////
//////}
//////int main()
//////{
//////	Test1();
//////	Test2();
//////	pj_string::string str("qwer");
//////	Test3(str);
//////	return 0;
//////}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <functional>
//#include <algorithm>
//using namespace std;
//
//typedef bool(*Handler_)(int a, int b);
//bool Greater(int a, int b)
//{
//	return a > b;
//}
//struct Compare
//{
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//class Date
//{
//public:
//	Date(const int& a)
//		: a_(a)
//	{}
//	int GetA()const 
//	{
//		return a_;
//	}
//private:
//	int a_;
//};
//struct Com
//{
//	bool operator()(Date* d1, Date* d2)
//	{
//		return d1->GetA() < d2->GetA();
//	}
//};
//void Test1()
//{
//	// 默认按照大堆的方法less
//	priority_queue<int, vector<int>> q;
//	// 建立小堆
//	priority_queue<int, vector<int>, greater<int>> q1;
//	// 函数指针建立小堆
//	priority_queue<int, vector<int>, Handler_> q2(Greater);
//	// 仿函数建立小堆
//	priority_queue<int, vector<int>, Compare> q3;
//	q3.push(1);
//	q3.push(2);
//	q3.push(3);
//	q3.push(4);
//	q3.push(5);
//}
//void Test2()
//{
//	priority_queue<Date*, vector<Date*>, Com> q;
//	Date d1(10);
//	Date d2(20);
//	Date d3(50);
//	Date d4(15);
//	Date d5(90);
//	Date d6(60);
//	Date d7(70);
//	Date d8(55);
//	Date d9(56);
//
//	q.push(&d1);
//	q.push(&d2);
//	q.push(&d3);
//	q.push(&d4);
//	q.push(&d5);
//	q.push(&d6);
//	q.push(&d7);
//	q.push(&d8);
//	q.push(&d9);
//}
//int main()
//{
//	vector<int> arr = { 1,2,3,6,8,10 };
//	Test1();
//	Test2();
//	//sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
//	return 0;
//}
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
//int main()
//{
//	TestMyPriorityQueue1();
//	TestMyPriorityQueue2();
//	return 0;
//}





















#if 0
// 模板函数里面：const T 和 T const 类型是一样的，若T是int*则，都是 int* const pt;
template <class T>
void Test(T const pt)
{
	*pt = 100;
	//p = nullptr;
}
int main()
{
	int a = 2;
	int* p = &a;
	Test(p);
	return 0;
}
#endif
// 全特化：将所有模板参数都进行特化
// 偏特化：只将部分模板参数进行特化，只要传的模板参数符合特化类型，则走偏特化版本，否则走类模板
// 特点：1.部分参数实例化  2.模板参数限制更加严格，例如 class Date<T1*, T2*>，传参指针则走偏特化版本



// 偏特化的应用：类型萃取
class String
{
public:
	// 构造
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	// 拷贝构造
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	// 析构
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	// 赋值运算符重载:现代法
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
private:
	char* _str;
};

#if 0
template <class T>
void Copy(T& dst, const T& src, size_t size)
{
	// 内存拷贝：优点：效率高  缺点：设计内存资源管理是浅拷贝
	memcpy(dst, src, size * sizeof(T));

	// 深拷贝：优点：一定不会出错  缺点：效率太低
	for (int i = 0; i < size; i++)
		dst[i] = src[i];
}
#endif 

// 类型萃取
struct True_Type
{};
struct False_Type
{};
// 其它类型
template <class T>
struct TypeTraits
{
	typedef False_Type PODTYPE;
};
// 内置类型：偏特化处理
template<>
struct TypeTraits<int>
{
	typedef True_Type PODTYPE;
};
template<>
struct TypeTraits<char>
{
	typedef True_Type PODTYPE;
};
template<>
struct TypeTraits<double>
{
	typedef True_Type PODTYPE;
};
template<>
struct TypeTraits<short>
{
	typedef True_Type PODTYPE;
};

template <class T>
void Copy(T* dst, const T* src, size_t size, True_Type)
{
	// 内置类型
	memcpy(dst, src, size * sizeof(T));
}
template <class T>
void Copy(T* dst, const T* src, size_t size, False_Type)
{
	// 其他类型
	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];
}
template <class T>
void Copy(T* dst, const T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::PODTYPE());
}
int main()
{
	int arr1[] = { 1,2,3,4 };
	int arr2[4] = { 0 };
	Copy(arr2, arr1, 4);

	String s[] = { "111", "222", "333" };
	String p[3];
	Copy(p, s, 3);
	return 0;
}


// 分离编译：一个项目由多个源文件共同实现，而每个源文件单独编译生成目标文件，最后将目标文件链接起来形成单一的可执行文件，称为分离编译模式
// 若模板类型的声明和定义不在同一个文件中，则链接会找不到
// 解决：1.显示实例化  2.将声明和定义放到一个 .hpp 文件中