#include <iostream>
using namespace std;

int Mindiv(int m, int n)
{
    //     1.շת�����
    //     int mod;
    //     while(mod = m % n)
    //     {
    //         m = n;
    //         n = mod;
    //     }
    //     return n;
    //    2.�������
    while (m != n)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }
    return m;
    return 0;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << num1 * num2 / Mindiv(num1, num2) << endl;
    return 0;
}