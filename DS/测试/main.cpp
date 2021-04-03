
//#include <iostream>
//#pragma warning(disable:4996)
//using namespace std;
//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (str == nullptr)
//			str = "";
//		_capacity = _size = strlen(str);
//		_str = new char[_size + 1];
//		strcpy(_str, str);
//		printf("拷贝：%p\n", _str);
//	}
//	String(const String& s)
//		: _str(new char[s._size + 1])
//		, _size(s._size)
//		, _capacity(s._capacity)
//	{
//		strcpy(_str, s._str);
//		printf("拷贝构造：%p\n", _str);
//	}
//	// 移动构造
//	String(String&& s)
//	{
//		printf("移动构造：s：%p，str：%p\n", s._str, _str);
//		swap(_str, s._str);
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			printf("析构：%p\n", _str);
//			delete[] _str;
//			_size = _capacity = 0;
//			_str = nullptr;
//		}
//	}
//	// 现代法
//	String& operator=(String s)
//	{
//		printf("赋值重载：s：%p，str：%p\n", s._str, _str);
//		swap(_str, s._str);
//		_size = s._size;
//		_capacity = s._capacity;
//		return *this;
//	}
//	// 移动赋值
//	String& operator=(String&& s)
//	{
//		printf("移动赋值：s：%p，str：%p\n", s._str, _str);
//		swap(_str, s._str);
//		_size = s._size;
//		_capacity = s._capacity;
//		return *this;
//	}
//
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};
//
//
//String Test(String s)
//{
//	return s;
//}
//String Test2()
//{
//	String s("oo");
//	return s;
//}
//int main()
//{
//	String s1;
//	String s2("qwer");
//	s1 = s2;					// 赋值重载
//	
//	String s3 = String("op");	// 构造一个匿名对象并执行赋值重载 
//	String s4 = Test2();		// 
//}