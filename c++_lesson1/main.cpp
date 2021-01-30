#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable:4996)
class Test
{
public:
    Test(int val = 0)
        :p_(new int(val))
    {
        cout << "构造：" << this << endl;
    }
    ~Test()
    {
        delete p_;
        cout << "析构：" << this << endl;
    }
private:
    int* p_;
};

int main()
{
    Test* p1 = (Test*)malloc(sizeof(Test));
    Test* p2 = new Test;
    Test* p3 = new Test[2];
    
    delete p1;      // 程序崩溃，malloc没有调用构造函数
    delete[] p1;    // 程序崩溃，malloc没有调用构造函数

    free(p2);       // 内存泄漏，free没有调用析构函数

    free(p3);       // 程序崩溃，连续空间只释放了一部分
    delete p3;      // 程序崩溃，连续空间只释放了一部分
    return 0;
}