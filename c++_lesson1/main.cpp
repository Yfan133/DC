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
//	// Ĭ�ϰ��մ�ѵķ���less
//	priority_queue<int, vector<int>> q;
//	// ����С��
//	priority_queue<int, vector<int>, greater<int>> q1;
//	// ����ָ�뽨��С��
//	priority_queue<int, vector<int>, Handler_> q2(Greater);
//	// �º�������С��
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
	// ģ������б�T��Ԫ������  Container���ײ�������֯��ʽ  Com���ȽϷ�ʽ
	template <class T, class Container = vector<T>, class Com = less<T>>
	class priority_que
	{
	public:
		priority_que()
		{}
		// ����������
		template <class Iterator>
		priority_que(Iterator begin, Iterator end)
			: _con(begin, end)
		{
			// 1.�Ȳ������飬�ٴ����һ����Ҷ�ӷ�֧��ʼ����ÿ���ڵ����µ���
			size_t n = _con.size() - 1;
			size_t node = (n - 1) >> 1;
			for (; node >= 0; --node)
			{
				_AdjustDown(node);
			}
		}
		void push(const T& data)
		{
			// 1.�Ȳ����������Ȼ�����ϵ�����ֱ�����ڵ�����ҵ�����λ��
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
			// 1.�Ƚ�����β���ݣ�ɾ��β�����ݣ�Ȼ�����������µ���
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
			// 1.�ҵ����������нϴ��
			// 2.����
			// 3.ѭ��ֱ��Խ��Ԫ������
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
#include <thread>
#include <atomic>

unsigned long long a = 0;
void func()
{

}
int main()
{

	return 0;
}