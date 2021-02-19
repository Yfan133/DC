//#include <iostream>
//#include <string.h>
//#pragma warning (disable:4996)
//
//namespace pj_string
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//	public:
//		string(const char* str = "")
//		{
//			if (str == nullptr)
//				str = "";
//			_capacity = _size = strlen(str);
//			_str = new char[_size + 1];
//			strcpy(_str, str);
//		}
//		string(size_t n, char ch)
//			:_str(new char[n + 1]), _size(n), _capacity(n)
//		{
//			memset(_str, ch, n);
//			_str[_size] = '\0';
//		}
//		string(const string& s)
//			:_str(new char[s.capacity() + 1])
//			,_size(s.size())
//			,_capacity(s.capacity())
//		{
//			strcpy(_str, s._str);
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = _capacity = 0;
//		}
//		string& operator=(string s)
//		{
//			std::swap(_str, s._str);
//			return *this;
//		}
//		size_t size()const
//		{
//			return _size;
//		}
//		size_t capacity()const
//		{
//			return _capacity;
//		}
//		char* c_str()const
//		{
//			return _str;
//		}
//		bool empty()const
//		{
//			return 0 == _size;
//		}
//		void resize(size_t new_size, char ch = char())
//		{
//			size_t old_size = size();
//			if (new_size > old_size)
//			{
//				if (new_size > _capacity)
//					reserve(new_size);
//				memset(_str + old_size, ch, new_size - old_size);
//			}
//			_size = new_size;
//			_str[new_size] = '\0';
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* newstr = new char[n + 1];
//				strcpy(newstr, _str);
//				delete _str;
//				_str = newstr;
//				_capacity = n;
//			}
//		}
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		void push_back(char ch)
//		{
//			*this += ch;
//		}
//		string& operator+=(char ch)
//		{
//			if (size() == capacity())
//				reserve(capacity() * 2);
//			_str[_size++] = ch;
//			_str[_size] = '\0';
//		}
//		string& operator+=(const char* str)
//		{
//			size_t len = strlen(str);
//			if (size() + len > capacity())
//			{
//				char* newstr = new char[_size + len + 1];
//				strcpy(newstr, _str);
//				delete _str;
//				_str = newstr;
//			}
//			strcat(_str + _size, str);
//			_capacity = _size += len;
//			return *this;
//		}
//		string& operator+=(const string& s)
//		{
//			*this += s.c_str();
//			return *this;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//		static size_t npos;
//	};
//	size_t string::npos = -1;
//}
//void Test1()
//{
//	pj_string::string str("qwer");
//	pj_string::string str1 = str;
//	pj_string::string str2(str);
//}
//pj_string::string Test2()
//{
//	pj_string::string str("wqer");
//	return str;
//}
//void Test3(pj_string::string str)
//{
//
//}
//int main()
//{
//	Test1();
//	Test2();
//	pj_string::string str("qwer");
//	Test3(str);
//	return 0;
//}
#include <iostream>
using namespace std;
namespace my_list
{
	class list
	{
	public:

	private:

	};
}