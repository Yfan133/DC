#include<iostream>
#include<assert.h>
#include<string.h>
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

class String
{
public:
	String(const char* ptr = "")
	{
		if (ptr == nullptr)
			ptr = "";
		_str = new char[strlen(ptr) + 1];
		strcpy(_str, ptr);
	}
	String(const String& tmp)
	{
		_str = new char[strlen(tmp._str)];
		strcpy(_str, tmp._str);
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	String& operator=(const String& tmp)
	{
		_str = new char[strlen(tmp._str)];
		//str
	}
private:
	char* _str;
};
int main()
{
	String s1("qwer");
	String s2;
	String s3(nullptr);
	String s4(s1);
}