#pragma once
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