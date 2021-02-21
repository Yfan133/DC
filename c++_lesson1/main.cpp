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
////#include <iostream>
////using namespace std;
////namespace my_list
////{
////	template <class T>
////	struct ListNode
////	{
////		ListNode(const T& val = T())
////			: val_(val)
////			, pre_(nullptr)
////			, next_(nullptr)
////		{}
////		T val_;
////		ListNode* pre_;
////		ListNode* next_;
////	};
////	template <class T>
////	struct ListIterator
////	{
////		typedef ListNode<T> Node;
////		typedef ListIterator<T> Self;
////		ListIterator(Node* node = nullptr)
////			:_pNode(node)
////		{}
////		T& operator*()
////		{
////			return _pNode->val_;
////		}
////		T* operator->()
////		{
////			return &(operator*());
////		}
////		Self& operator++()	// 前置++
////		{
////			_pNode = _pNode->next_;
////			return *this;
////		}
////		Self operator++(int)	// 后置++
////		{
////			Self temp(_pNode);
////			_pNode = _pNode->next_;
////			return temp;
////		}
////		Self& operator--()	// 前置--
////		{
////			_pNode = _pNode->pre_;
////			return *this;
////		}
////		Self operator--(int)	// 后置--
////		{
////			Self temp(_pNode);
////			_pNode = _pNode->pre_;
////			return temp;
////		}
////		bool operator!=(const Self& it)const 
////		{
////			return _pNode != it._pNode;
////		}
////		bool operator==(const Self& it)const 
////		{
////			return _pNode == it._pNode;
////		}
////		Node* _pNode;
////	};
////	template <class T>
////	class list
////	{
////		typedef ListNode<T> Node;
////	public:
////		typedef ListIterator<T> iterator;
////		list()
////		{
////			CreateHead();
////		}
////		list(size_t n, const T& data = T())
////		{
////			CreateHead();
////			for(int i = 0; i < n; ++i)
////				push_back(data);
////		}
////		//template <class Iterator>
////		list(int* first, int* last)	// 迭代器构造必须采用模板，因为不同容器的迭代器实现可能不同
////		{
////			CreateHead();
////			while (first != last)
////			{
////				push_back(*first);
////				++first;
////			}
////		}
////		list(const list<T>& node)
////		{
////			CreateHead();
////			Node* cur = node.head_->next_;
////			while (cur != node.head_)
////			{
////				push_back(cur->val_);
////				cur = cur->next_;
////			}
////		}
////		~list()
////		{
////			Clear();
////			delete head_;
////			head_ = nullptr;
////		}
////		list<T>& operator=(list<T> node)
////		{
////			swap(head_, node.head_);
////			return *this;
////		}
////		iterator begin()
////		{
////			return iterator(head_->next_);
////		}
////		iterator end()
////		{
////			return iterator(head_);
////		}
////		size_t size()const
////		{
////			size_t count = 0;
////			Node* cur = head_->next_;
////			while (cur != head_)
////			{
////				cur = cur->next_;
////				count++;
////			}
////			return count;
////		}
////		bool empty()const
////		{
////			return head_->next_ == head_;
////		}
////		void resize(size_t n, const T& data = T())
////		{
////			size_t oldsize = size();
////			if (n > oldsize)
////			{
////				for (size_t i = oldsize; i < n; ++i)
////				{
////					push_back(data);
////				}
////			}
////			else
////			{
////				for (size_t i = n; i < oldsize; ++i)
////				{
////					pop_back();
////				}
////			}
////		}
////		void push_back(const T& data)
////		{
////			insert(end(), data);
////		}
////		void pop_back()
////		{
////			erase(--end());
////		}
////		void push_front(const T& data)
////		{
////			insert(begin(), data);
////		}
////		void pop_front()
////		{
////			erase(begin());
////		}
////		iterator insert(iterator pos, const T& data)
////		{
////			Node* node = new Node(data);
////			Node* posNode = pos._pNode;
////			
////			node->pre_ = posNode->pre_;
////			node->next_ = posNode;
////			posNode->pre_->next_ = node;
////			posNode->pre_ = node;
////			return iterator(node);
////		}
////		iterator erase(iterator pos)
////		{
////			if (pos == end())
////				return pos;
////			Node* node = pos._pNode;
////			Node* pRet = node->next_;
////			node->pre_->next_ = node->next_;
////			node->next_->pre_ = node->pre_;
////			delete node;
////			node = nullptr;
////			return iterator(pRet);
////		}
////		iterator erase(iterator begin, iterator end)
////		{
////			while (begin != end)
////			{
////				begin = erase(begin);
////			}
////			return begin;
////		}
////		void Clear()
////		{
////			erase(begin(), end());
////		}
////	private:
////		void CreateHead()
////		{
////			head_ = new Node;
////			head_->pre_ = head_;
////			head_->next_ = head_;
////		}
////	private:
////		Node* head_;
////	};
////}
////void Test1()
////{
////	my_list::list<int> l1;
////	my_list::list<int> l2(10, 5);
////	my_list::list<int> l3(l1);
////
////	int array[] = { 1,2,3,4,5 };
////	my_list::list<int> l4{ array, array + sizeof(array) / sizeof(array[0]) };
////
////	//auto it = l2.begin();
////	my_list::ListIterator<int> it = l4.begin();
////	while (it != l4.end())
////	{
////		cout << *it << " ";
////		it++;
////	}
////	cout << endl;
////	
////	// 如果想要让容器支持范围for循环，则必须实现begin/end的方法，以及迭代器++操作
////	for (auto e : l2)
////		cout << e << " ";
////	cout << endl;
////}
////void Test2()
////{
////	my_list::list<int> L;
////	L.push_back(1);
////	L.push_back(2);
////	L.push_back(3);
////	L.push_back(4);
////	L.push_back(5);
////
////	cout << L.size() << endl;
////	L.resize(10, 6);
////	for (auto e : L)
////		cout << e << " ";
////	cout << endl;
////
////	L.resize(4);
////	for (auto e : L)
////		cout << e << " ";
////	cout << endl;
////
////	L.push_front(0);
////	for (auto e : L)
////		cout << e << " ";
////	cout << endl;
////
////	L.pop_front();
////	for (auto e : L)
////		cout << e << " ";
////	cout << endl;
////
////	L.erase(L.begin());
////	for (auto e : L)
////		cout << e << " ";
////	cout << endl;
////
////	L.Clear();
////	if (L.empty())
////	{
////		cout << "ok" << endl;
////	}
////}
////int main()
////{
////	// 迭代器是对原生态指针的封装
////	Test1();
////	return 0;
////}
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
//	// 默认按照大堆的方法Less
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
