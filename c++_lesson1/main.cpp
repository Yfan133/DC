//#include <iostream>
//#include <string.h>
//#pragma warning (disable:4996)
//
//namespace old_string
//{
//    class string
//    {
//    public:
//        string(const char* str = "")
//        {
//            if (str == nullptr)
//                str = "";
//            _str = new char[strlen(str) + 1];
//            strcpy(_str, str);
//        }
//        string(const string& s)
//            :_str(new char[s.size() + 1])
//        {
//            strcpy(_str, s.c_str());
//        }
//        ~string()
//        {
//            if (_str)
//            {
//                delete[] _str;
//                _str = nullptr;
//            }
//        }
//        string& operator=(const string& s)
//        {
//            if (this != &s)
//            {
//                // 1.�ͷžɿռ�
//                delete[] _str;
//                // 2.�����¿ռ�
//                _str = new char[s.size() + 1];
//                strcpy(_str, s.c_str());
//            }
//            return *this;
//        }
//        int size()const
//        {
//            return strlen(_str);
//        }
//        char* c_str()const
//        {
//            return _str;
//        }
//    private:
//        char* _str;
//    };
//}
//namespace new_string
//{
//    class string
//    {
//    public:
//        string(const char* str = "")
//        {
//            if (str == nullptr)
//                str = "";
//            _str = new char[strlen(str) + 1];
//            strcpy(_str, str);
//        }
//        string(const string& s)
//            :_str(nullptr)
//        {
//            string strTemp(s.c_str());
//            std::swap(_str, strTemp._str);
//        }
//        ~string()
//        {
//            if (_str)
//            {
//                delete[] _str;
//                _str = nullptr;
//            }
//        }
//        string& operator=(string s)
//        {
//            std::swap(_str, s._str);
//            return *this;
//        }
//        int size()const
//        {
//            return strlen(_str);
//        }
//        char* c_str()const
//        {
//            return _str;
//        }
//    private:
//        char* _str;
//    };
//}
//new_string::string Test()
//{
//    new_string::string tmp("qwer");
//    new_string::string p = "asdf";
//    return tmp;
//}
//int main()
//{
//    old_string::string s("qwer");
//    old_string::string ss("asdf");
//    ss = s;
//    old_string::string sp(s);
//    Test();
//    return 0;
//}
#include <iostream>
using namespace std;

int main()
{
	// ���췽��
	string str1;
	string str2("qwer");
	string str3(10, 'a');
	string str4(str2);
	// ��������
	int size = str2.size();
	int length = str2.length();
	int capacity = str2.capacity();
	str2.reserve(30);
	capacity = str2.capacity();
	str2.resize(10, 'a');
	str2.reserve(20);
	capacity = str2.capacity();
	str2.reserve(15);
	capacity = str2.capacity();
	str2.reserve(10);
	capacity = str2.capacity();
	// Ϊ�����string������ܣ����ڲ�������һ���̶���С�����飬��СΪ16
	// ���reserve new <= 15 ����������С��15
	// ���reserve new > 15 �������
	return 0;
}