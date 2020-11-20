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
//	String& operator=(const String& tmp)			//��ֵ��������أ���������String& �Ͳ����б�const String&��Ϊ�˷�ֹ�ڴ�й¶Ӧ�����ͷžɿռ䣬�ٿ����¿ռ�
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
//	String s2 = s1;
//	String s3;
//	s3 = s1;
//}

//ģ��ʵ��STL��string
//Ϊʲô���������[]��ҪŪ��һ��const
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		//����
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
		//������
		iterator begin()						//s1.begin()���ص����ַ�����ʼλ��
		{
			return _str;
		}
		iterator end()						//s1.end()���ص�λ�����ַ���������'\0'���ڵ�λ��
		{
			return _str + _size;
		}
		//////////////////////////////////////////////////
		//����
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
				char* tmp = new char[n];		//���ϴ����ģ��ں����������ᱻ�ͷţ�����ڴ�й¶һ�㶼�Ǻ����ڶ�̬����δ�����ͷŵ�
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		/////////////////////////////////////////////////////////////
		//Ԫ�ط���
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
		//�޸�
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
			//if(_capacity<_size)			//Ϊʲô������������һֱpush_back���������Ϊԭ�ռ䱻�ͷ��ˣ������µĿռ䣬�µ�capacity
			_capacity = _size;
			return *this;
		}
		string& operator+=(const string& tmp)
		{
			*this += tmp._str;				//strcat������ֱ�ӽ������ĵ�ַ���ӵ�һ�𣬶��ǰ�char* str2��һ����������str1����ȥ�����str1Ҫ���㹻�Ŀռ�
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
		string& clear()					//��գ�ֻ��Ҫ����ЧԪ�صĸ�����0��������_str[0]='\0'
		{
			_size = 0;
			_str[0] = '\0';
		}
		///////////////////////////////////////////////////////////////////
		///�������
		const char* c_str()const		//����ֱ�ӷ��ص�_str�ĵ�ַ����˲��������ַ���൱�ڲ���string �ַ���
		{
			return _str;
		}
		size_t find(char ch, size_t pos = 0)				//����
		{
			while (pos < _size)
			{
				if (_str[pos] == ch)
					return pos;
				pos++;
			}
			return npos;
		}
		size_t rfind(char ch, size_t pos = npos)			//������ң�������pos����posĬ�ϵ�����Ϊnpos
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
		string substr(size_t pos, size_t n = npos)	//������ˣ��Ǵ�pos��ʼ��ȡn���ַ�
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