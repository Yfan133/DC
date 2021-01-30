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
        cout << "���죺" << this << endl;
    }
    ~Test()
    {
        delete p_;
        cout << "������" << this << endl;
    }
private:
    int* p_;
};

int main()
{
    Test* p1 = (Test*)malloc(sizeof(Test));
    Test* p2 = new Test;
    Test* p3 = new Test[2];
    
    delete p1;      // ���������mallocû�е��ù��캯��
    delete[] p1;    // ���������mallocû�е��ù��캯��

    free(p2);       // �ڴ�й©��freeû�е�����������

    free(p3);       // ��������������ռ�ֻ�ͷ���һ����
    delete p3;      // ��������������ռ�ֻ�ͷ���һ����
    return 0;
}