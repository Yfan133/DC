#include <iostream>
#include <string.h>
#pragma warning (disable:4996)

namespace old_string
{
    class string
    {
    public:
        string(const char* str = "")
        {
            if (str == nullptr)
                str = "";
            _str = new char[strlen(str) + 1];
            strcpy(_str, str);
        }
        string(const string& s)
            :_str(new char[s.size() + 1])
        {
            strcpy(_str, s.c_str());
        }
        ~string()
        {
            if (_str)
            {
                delete[] _str;
                _str = nullptr;
            }
        }
        string& operator=(const string& s)
        {
            if (this != &s)
            {
                // 1.释放旧空间
                delete[] _str;
                // 2.拷贝新空间
                _str = new char[s.size() + 1];
                strcpy(_str, s.c_str());
            }
            return *this;
        }
        int size()const
        {
            return strlen(_str);
        }
        char* c_str()const
        {
            return _str;
        }
    private:
        char* _str;
    };
}
namespace new_string
{
    class string
    {
    public:
        string(const char* str = "")
        {
            if (str == nullptr)
                str = "";
            _str = new char[strlen(str) + 1];
            strcpy(_str, str);
        }
        string(const string& s)
            :_str(nullptr)
        {
            string strTemp(s.c_str());
            std::swap(_str, strTemp._str);
        }
        ~string()
        {
            if (_str)
            {
                delete[] _str;
                _str = nullptr;
            }
        }
        string& operator=(string s)
        {
            std::swap(_str, s._str);
            return *this;
        }
        int size()const
        {
            return strlen(_str);
        }
        char* c_str()const
        {
            return _str;
        }
    private:
        char* _str;
    };
}
new_string::string Test()
{
    new_string::string tmp("qwer");
    return tmp;
}
int main()
{
    old_string::string s("qwer");
    old_string::string ss("asdf");
    ss = s;
    old_string::string sp(s);
    Test();
    return 0;
}