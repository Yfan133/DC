#include <iostream>
using namespace std;

int CotOne(int n)
{
    int res = 0;
    while (n)
    {
        res++;
        n = n & (n - 1);
    }
    return res;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << CotOne(n) << endl;
    }
    return 0;
}
