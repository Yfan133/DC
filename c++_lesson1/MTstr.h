#pragma once
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