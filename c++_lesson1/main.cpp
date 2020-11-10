#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
#pragma warning (disable:4996)
//template<class T>
//class Seqlist
//{
//public:
//	Seqlist(int capacity = 5)				//����
//		:_base(new T[capacity])
//		, _capacity(capacity)
//		, _size(0)
//	{}
//	Seqlist(const Seqlist<T>& tmp)			//��������
//	{
//		_capacity = tmp._capacity;
//		_base = new T[_capacity];
//		for (int i = 0; i < tmp._size; i++)
//		{
//			_base[i] = tmp._base[i];
//		}
//		_size = tmp._size;
//	}		
//	~Seqlist();								//�������������ⶨ��
//	Seqlist<T>& operator=(const Seqlist<T>& tmp)	//��ֵ���������
//	{}
//	T& operator[](int data)							//������[]���أ�base[n]�ĺ���
//	{
//		assert(data < _size);
//		return _base[data];
//	}
//	void SeqPush(const T data)						//β��
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
//Seqlist<T>::~Seqlist()	//������ʵ�ֶ���ĺ�������Ҫ��ģ������б�
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

////��ͳ��
//class String
//{
//public:
//	String(const char* ptr = "")					//���죬ע������б�const char*�����ٵ��¿ռ�strlen+1��strlen�������'\0'
//	{
//		if (ptr == nullptr)
//			ptr = "";
//		_str = new char[strlen(ptr) + 1];			
//		strcpy(_str, ptr);
//	}
//	String(const String& tmp)							//�������죬const String&���ͣ���ʼ��ʱ���ٿռ�
//		:_str(new char[strlen(tmp._str)+1])
//	{
//		strcpy(_str, tmp._str);
//	}
//	~String()										//�������������пգ���Ϊ�����ͷſռ䣬����ֹҰָ��
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//String& operator=(const String& tmp)			//��ֵ��������أ���������String& �Ͳ����б�const String&��Ϊ�˷�ֹ�ڴ�й¶Ӧ�����ͷžɿռ䣬�ٿ����¿ռ�
//{
//	if (*this != tmp)
//	{
//		delete[] _str;
//		_str = new char[strlen(tmp._str) + 1];
//		strcpy(_str, tmp._str);
//	}
//	return *this;
//}
//private:
//	char* _str;
//};
//�ִ�����
//class String
//{
//public:
//	String(const char* ptr = "");
//	String(const String& tmp);
//	~String();
//	String& operator=(String tmp)	//ע�⣬����������һ����ʱ������Ȼ�󽻻�ָ�򣬳�����Զ��������������ͷ���ʱ����
//	{
//		std::swap(_str, tmp._str);
//		return *this;
//	}
//private:
//	char* _str;
//};
//
//String::String(const char* ptr)		//ע�⣬ȱʡ�����б�ֻ�ܷ��������ĵط�������ĵط����ܸ�ȱʡ
//{
//	if (ptr == nullptr)
//		ptr = "";
//	_str = new char[strlen(ptr) + 1];
//	strcpy(_str, ptr);
//}
//String::String(const String& tmp)	//ע�⣬Ӧ�ó�ʼ��_strΪnullptr����������������ܵ���_str�������ֵ(Ұָ��)����������ʱ����������ʱ�����δ���
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
//	String s2;
//	String s3(nullptr);
//	String s4(s1);
//	String s5(NULL);
//	s1 = s4;
//}

//ģ��ʵ��STL��string
//Ϊʲô���������[]��ҪŪ��һ��const
namespace bit
{
	class string
	{
	public:
		string(const char* ptr = "")
		{
			if (ptr == nullptr)
				ptr = "";
			_str = new char[strlen(ptr) + 1];
			_size = 0;
			_capacity = 15;
		}
		string(const string& tmp)
			:_str(new char[strlen(tmp._str)+1])
			,_size(tmp._size)
			,_capacity(tmp._capacity)
		{

		}
		~string()
		{

		}

	private: 
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}