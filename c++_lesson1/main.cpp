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
//#include <memory>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// auto_ptr��Ȩ��ת�ƣ�����ȫ
// unique_ptr����ֹ�����͸�ֵ
// shared_ptr�����Կ����͸�ֵ����һ�����ü���ȥ�����ж��ٸ�����
// weak_ptr�����shared_ptr��ѭ����������
template <class T>
class smartPtr
{
public:
	smartPtr(T* ptr)
		: _ptr(ptr)
	{
		// �����ʱ�򴴽�

	}
	~smartPtr()
	{
		// ������ʱ������
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}
	smartPtr(smartPtr<T>& sp)
		: _ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}
	smartPtr<T>& operator=(smartPtr<T>& sp)
	{
		if (this != &sp)
		{
			delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
class Date
{
public:
	int _year = 1;
};
void Test1()
{
	smartPtr<int> sp(new int(1));
	smartPtr<int> sp1(new int(2));

	// ��������
	smartPtr<int> sp2(sp);
	// ��ֵ����
	sp1 = sp2;

	// ����ָ������ָ��Ĳ���
	smartPtr<Date> sp3(new Date);
	cout << (*sp3)._year << endl;
	cout << sp3->_year << endl;
}
void Test2()
{
	auto_ptr<Date> ap(new Date);
	cout << ap->_year << endl;
	// ����ʱ����Ȩ��ת��
	auto_ptr<Date> ap1(ap);
	cout << ap1->_year << endl;

	// ת��֮������ָ�벻��ӵ����Դ
	cout << ap->_year << endl;	// ���﷢������ָ��Ϊ��
}
void Test3()
{
	unique_ptr<Date> up(new Date);
	// unique_ptr<Date> up1(up);	// ���ﱻ��ֹ��,����������ɾ������
	unique_ptr<Date> up2(new Date);
	// up2 = up;	// ����Ҳ����ֹ�ˣ���ֵ������ɾ������
}
// ģ��ʵ�� unique_ptr
template <class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr)
		: _ptr(ptr)
	{}
	~Unique_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	// ��ֹ����
	Unique_ptr(const Unique_ptr<T>& up) = delete;
	Unique_ptr<T>& operator=(const Unique_ptr<T>& up) = delete;
private:
	T* _ptr;
};
void Test4()
{
	shared_ptr<Date> sp(new Date);
	cout << sp.use_count() << endl;
	shared_ptr<Date> sp1(sp);
	cout << sp.use_count() << endl;
	shared_ptr<Date> sp2(new Date);
	sp2 = sp;
	cout << sp.use_count() << endl;
}

#include <mutex>
// ģ��ʵ�� shared_ptr
template <class T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr)	// ���ﲻ����const��ԭ����ΪҪ��ptr��_ptr��ֵ����_ptr��T*���͡�
		: _ptr(ptr)
		, use_count(new int(1))
		, _mtx(new mutex)
	{}
	~Shared_ptr()
	{
		if (subRef() == 0)
		{
			delete _ptr;
			delete use_count;
			delete _mtx;
			use_count = nullptr;
			_ptr = nullptr;
		}
	}
	Shared_ptr(const Shared_ptr<T>& sp)
		: _ptr(sp._ptr)
		, use_count(sp.use_count)
		, _mtx(sp._mtx)
	{
		addRef();
	}
	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		// if (this != &sp) ����Ӧ���ж�˫���������Դ�Ƿ���ͬ
		if (_ptr != sp._ptr)
		{
			if (subRef() == 0)	// �̰߳�ȫ�汾
			{
				delete _ptr;
				delete use_count;
				delete _mtx;
			}
			_ptr = sp._ptr;
			use_count = sp.use_count;
			_mtx = sp._mtx;
			addRef();
		}
		return *this;
	}
	int getUseCount()
	{
		return *use_count;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	int addRef()
	{
		_mtx->lock();
		++(*use_count);
		_mtx->unlock();
		return *use_count;
	}
	int subRef()
	{
		_mtx->lock();
		--(*use_count);
		_mtx->unlock();
		return *use_count;
	}
private:
	T* _ptr;
	int* use_count;
	mutex* _mtx;
};
void Test5()
{
	Shared_ptr<Date> sp1(new Date);
	Shared_ptr<Date> sp2(new Date);
	cout << sp1.getUseCount() << endl;
	Shared_ptr<Date> sp3(sp1);
	cout << sp1.getUseCount() << endl;
	sp2 = sp1;
	cout << sp1.getUseCount() << endl;
}
#include <thread>
void func(Shared_ptr<Date> sp, int n)
{
	for (int i = 0; i < n; i++)
	{
		Shared_ptr<Date> copy(sp);
	}
}
void TestThread()	// ��ʵ��ݴ����и����⣺��������
{
	Shared_ptr<Date> sp(new Date);
	cout << sp.getUseCount() << endl;
	int n;
	cin >> n;
	thread t1(func, sp, n);
	thread t2(func, sp, n);

	t1.join();
	t2.join();
	cout << sp.getUseCount() << endl;
}
template <class T>
struct ListNode
{
	~ListNode()
	{
		cout << "����" << endl;
	}
	shared_ptr<ListNode<T>> prev;
	shared_ptr<ListNode<T>> next;
};
void Test6()
{
	// �������ã��ҵ������ͷţ���������ͷţ�������ͷŲ�����Դ
	shared_ptr<ListNode<int>> sp(new ListNode<int>);
	shared_ptr<ListNode<int>> sp1(new ListNode<int>);
	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;

	sp->prev = sp1;
	sp1->next = sp;

	cout << sp.use_count() << endl;
	cout << sp1.use_count() << endl;
}
template <class T>
struct freeM
{
	void operator()(T* ptr)
	{
		free(ptr);
		cout << "free" << endl;
	}
};
void Test7()
{
	// ����ɾ������shared_ptr ֻ��ʹ��deleteɾ�����������malloc����new[]����Ҫ����ɾ����
	freeM<int> fm;
	shared_ptr<int> sp((int*)malloc(sizeof(int)));
}
int _QSort1(vector<int>& arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
			--right;
		arr[left] = arr[right];
		while (left < right && arr[left] < key)
			++left;
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}
int _QSort(vector<int>& arr, int left, int right)
{
	// �������м�ֵ

	int key = arr[left];
	int pos = left;
	for (int i = left + 1; i <= right; ++i)
	{
		if (arr[i] <= key)
		{
			++pos;
			if (pos != i)
				swap(arr[pos], arr[i]);
		}
	}
	swap(arr[left], arr[pos]);
	return pos;
}
#include <stack>
void QuickSortNor(vector<int>& arr, int left, int right) 
{
	stack<int> stc;
	stc.push(left);
	stc.push(right);
	while (!stc.empty())
	{
		int end = stc.top();
		stc.pop();
		int begin = stc.top();
		stc.pop();

		int pos = _QSort1(arr, begin, end - 1);
		
		if (begin < pos - 1)
		{
			stc.push(begin);
			stc.push(pos);
		}
		if (end > pos + 1)
		{
			stc.push(pos + 1);
			stc.push(end);
		}
	}
}
void QuickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int pos = _QSort1(arr, left, right - 1);
	QuickSort(arr, left, pos);
	QuickSort(arr, pos + 1, right);
}

void MergeSort(vector<int>& arr, int left, int right)
{

}
class Solution {
public:
	int ans = 0;
	void MergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
	{
		if (left >= right)
			return;
		int mid = left + (right - left) / 2;
		MergeSort(nums, left, mid, tmp);
		MergeSort(nums, mid + 1, right, tmp);

		int begin1 = left, begin2 = mid + 1;
		int pos = left;
		while (begin1 <= mid && begin2 <= right)
		{
			if (nums[begin1] <= nums[begin2])
				tmp[pos++] = nums[begin1++];
			else
			{
				tmp[pos++] = nums[begin2++];
				ans += (mid - begin1 + 1);
			}
		}
		while (begin1 <= mid)
			tmp[pos++] = nums[begin1++];
		while (begin2 <= right)
			tmp[pos++] = nums[begin2++];
		for (int i = left; i <= right; ++i)
			nums[i] = tmp[i];
	}
	int reversePairs(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> tmp(n);
		MergeSort(nums, 0, n - 1, tmp);
		return ans;
	}
};

int main()
{
	vector<int> arr{ 9,5,10,2,3,5,1 };
	Solution a;
	int n = arr.size();
	vector<int>tmp(n);
	a.MergeSort(arr, 0, n - 1, tmp);
	// QuickSort(arr, 0, arr.size());
	// QuickSortNor(arr, 0, arr.size());
	// Test1();
	// Test2();
	// Test3();
	// Test4();
	// Test5();
	// TestThread();
	// Test6();
	// Test7();

	return 0;
}