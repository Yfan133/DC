#include"main.h"
//this指针的生命周期比函数要长

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
//	{}		
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
//	s2.SeqPush(1.0);
//	return 0;
//}
int main()
{
	int arr[100];
	memset(arr, 0, sizeof(arr));
	return 0;
}

//#include<string>
//int main()
//{
//	string a("hello world");
//	a.resize(15, 'p');
//	a.resize(10, 'p');
//	a.resize(5);
//	a.reserve(15);
//	a.reserve(5);
//	a.erase(a.begin(), a.begin() + 3);
//	//为什么我这里没有减小容量
//	return 0;
//}
