#include<iostream>
#include<assert.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
#pragma warning (disable:4996)
//template<class T>
//class Seqlist
//{
//public:
//	Seqlist(int capacity = 5)				//构造
//		:_base(new T[capacity])
//		, _capacity(capacity)
//		, _size(0)
//	{}
//	Seqlist(const Seqlist<T>& tmp)			//拷贝构造
//	{
//		_capacity = tmp._capacity;
//		_base = new T[_capacity];
//		for (int i = 0; i < tmp._size; i++)
//		{
//			_base[i] = tmp._base[i];
//		}
//		_size = tmp._size;
//	}		
//	~Seqlist();								//析构函数在类外定义
//	Seqlist<T>& operator=(const Seqlist<T>& tmp)	//赋值运算符重载
//	{}
//	T& operator[](int data)							//操作符[]重载，base[n]的函数
//	{
//		assert(data < _size);
//		return _base[data];
//	}
//	void SeqPush(const T data)						//尾插
//	{
//		_base[_size] = data;
//		_size++;
//	}
//	void SeqPopBack()
//	{
//		_size--;
//	}
//	int SeqSize()
//	{
//		return _size;
//	}
//private:
//	T* _base;
//	int _size;
//	int _capacity;
//};
//template<class T>
//Seqlist<T>::~Seqlist()	//在类外实现定义的函数，需要加模板参数列表
//{
//	if (_base)
//	{
//		delete[] _base;
//		_capacity = 0;
//		_size = 0;
//	}
//}
//int main()
//{
//	Seqlist<int> s1(10);
//	Seqlist<double>s2(10);
//	s1.SeqPush(1);
//	s1.SeqPush(2);
//	s1.SeqPush(2);
//	s1.SeqPush(2);
//	Seqlist<int> s3 = s1;
//	s2.SeqPush(1.0);
//	Seqlist<double>s4 = s2;
//	return 0;
//}

////传统版
//class String
//{
//public:
//	String(const char* ptr = "")					//构造，注意参数列表const char*，开辟的新空间strlen+1，strlen不会计算'\0'
//	{
//		if (ptr == nullptr)
//			ptr = "";
//		_str = new char[strlen(ptr) + 1];			
//		strcpy(_str, ptr);
//	}
//	String(const String& tmp)							//拷贝构造，const String&类型，初始化时开辟空间
//		:_str(new char[strlen(tmp._str)+1])
//	{
//		strcpy(_str, tmp._str);
//	}
//	~String()										//析构函数，先判空，不为空则释放空间，并防止野指针
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//	String& operator=(const String& tmp)			//赋值运算符重载，返回类型String& 和参数列表const String&，为了防止内存泄露应该先释放旧空间，再开辟新空间
//	{
//		if (this != &tmp)
//		{
//			delete[] _str;
//			_str = new char[strlen(tmp._str) + 1];
//			strcpy(_str, tmp._str);
//		}
//		return *this;
//	}
//private:
//	char* _str;
//};
//现代法：
//class String
//{
//public:
//	String(const char* ptr = "");
//	String(const String& tmp);
//	~String();
//	String& operator=(String tmp)	//注意，这里是生成一份临时拷贝，然后交换指向，程序会自动调用析构函数释放临时对象
//	{
//		std::swap(_str, tmp._str);
//		return *this;
//	}
//private:
//	char* _str;
//};
//
//String::String(const char* ptr)		//注意，缺省参数列表只能放在声明的地方，定义的地方不能给缺省
//{
//	if (ptr == nullptr)
//		ptr = "";
//	_str = new char[strlen(ptr) + 1];
//	strcpy(_str, ptr);
//}
//String::String(const String& tmp)	//注意，应该初始化_str为nullptr，如果不这样做可能导致_str附上随机值(野指针)，交换给临时对象，在析构时产生段错误
//	:_str(nullptr)
//{
//	String ret(tmp._str);
//	std::swap(_str, ret._str);
//}
//String::~String()
//{
//	if (_str)
//	{
//		delete[] _str;
//		_str = nullptr;
//	}
//}
//int main()
//{
//	String s1("qwer");
//	String s2 = s1;
//	String s3;
//	s3 = s1;
//}

//模拟实现STL的string
//为什么重载运算符[]，要弄出一个const
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		//构造
		string(const char* ptr = "")
		{
			if (ptr == nullptr)
				ptr = "";
			_size = strlen(ptr);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, ptr);
		}
		string(size_t n, char ch)
			: _str(new char[n + 1])
			, _size(n)
			, _capacity(n)
		{
			memset(_str, n, ch);
			_str[_size] = '\0';
		}
		template<class iterator>
		string(iterator first, iterator last)
		{
			auto it = first;
			size_t count = 0;
			while (it != last)
			{
				count++;
				it++;
			}
			it = first;
			_size = _capacity = count;
			_str = new char[_capacity + 1];
			for(size_t i=0;i<_size;i++)
			{
				_str[i] = *it++;
			}
			_str[_size] = '\0';
		}
		string(const string& tmp)
			:_str(new char[strlen(tmp._str)+1])
			,_size(tmp._size)
			,_capacity(tmp._capacity)
		{
			strcpy(_str, tmp._str);
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_size = 0;
				_capacity = 0;
			}
		}
		string& operator=(const string& tmp)
		{
			if (this != &tmp)
			{
				delete[] _str;
				new char[strlen(tmp._str) + 1];
				strcpy(_str, tmp._str);
				_size = tmp._size;
				_capacity = tmp._capacity;
			}
			return *this;
		}
		///////////////////////////////////////////////////
		//迭代器
		iterator begin()						//s1.begin()返回的是字符串起始位置
		{
			return _str;
		}
		iterator end()						//s1.end()返回的位置是字符串最后面的'\0'所在的位置
		{
			return _str + _size;
		}
		//////////////////////////////////////////////////
		//容量
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		bool empty()
		{
			return 0 == _size;
		}
		void resize(size_t n, char ch)
		{
			if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				memset(_str + _size, ch, n - _size);
			}
			_size = n;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n];		//堆上创建的，在函数结束不会被释放，因此内存泄露一般都是函数内动态申请未主动释放的
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		/////////////////////////////////////////////////////////////
		//元素访问
		char& operator[](int index) 
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](int index)const
		{
			assert(index < _size);
			return _str[index];
		}
		////////////////////////////////////////////////////////////
		//修改
		void push_back(char ch)
		{
			if (_capacity == 0)
				reserve(15);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* ptr)
		{
			int len = strlen(ptr);
			char* tmp = new char[_size + len + 1];
			strcpy(tmp, _str);
			strcat(tmp + _size, ptr);
			delete[] _str;
			_str = tmp;
			_size += len;
			//if(_capacity<_size)			//为什么这样做，遇到一直push_back会崩溃，因为原空间被释放了，这是新的空间，新的capacity
			_capacity = _size;
			return *this;
		}
		string& operator+=(const string& tmp)
		{
			*this += tmp._str;				//strcat并不是直接将两个的地址连接到一起，而是把char* str2的一个个拷贝到str1里面去，因此str1要有足够的空间
			return *this;
			/*int len = tmp._size;
			char* ptr1 = new char[_size + len + 1];
			strcpy(ptr1, _str);
			char* ptr2 = new char[len + 1];
			strcpy(ptr2, tmp._str);
			strcat(ptr1 + _size, ptr2);
			_size += len;
			_capacity = _size;
			return *this;*/
		}
		string& insert(int pos, const char* ch)
		{
			int len = strlen(ch);
			char* tmp = (char*)malloc(_size + len + 1);
			strcpy(tmp, _str);
			strcpy(tmp + pos, ch);
			strcpy(tmp + pos + len, _str + pos);
			_size += len;
			_capacity = _size;
			delete[] _str;
			_str = tmp;
			return *this;
		}
		iterator erase(iterator pos)
		{

		}
		string& clear()					//清空，只需要将有效元素的个数清0，并且让_str[0]='\0'
		{
			_size = 0;
			_str[0] = '\0';
		}
		///////////////////////////////////////////////////////////////////
		///特殊操作
		const char* c_str()const		//这里直接返回的_str的地址，因此操作这个地址就相当于操作string 字符串
		{
			return _str;
		}
		size_t find(char ch, size_t pos = 0)				//查找
		{
			while (pos < _size)
			{
				if (_str[pos] == ch)
					return pos;
				pos++;
			}
			return npos;
		}
		size_t rfind(char ch, size_t pos = npos)			//反向查找，若不传pos，则pos默认的属性为npos
		{
			int cur = pos == npos ? _size - 1 : pos;
			while (cur >= 0)
			{
				if (_str[cur] == ch)
					return cur;
				cur--;
			}
			return npos;
		}
		string substr(size_t pos, size_t n = npos)	//这里错了，是从pos开始截取n个字符
		{
			n = n == npos ? _size : n;
			string s;
			while (pos <= n)
				s.push_back(_str[pos++]);
			return s;
		}
	private: 
		char* _str;
		size_t _size;
		size_t _capacity;
		static size_t npos;
	};
	size_t string::npos = -1;
}
int main()
{
	vector<vector<int>> ar(3, vector<int>{1,2,3});

	/*bit::string p("qwer");
	bit::string p1("addf");
	bit::string s = p.substr(0, 2);*/
	return 0;
}