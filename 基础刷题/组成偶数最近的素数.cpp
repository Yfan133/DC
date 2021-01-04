#include <iostream>
#include <algorithm>
using namespace std;

bool isPrm(int tar)
{
    int tmp = sqrt(tar);
    for (int i = 2; i <= tmp; i++)
    {
        if (tar % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = n / 2; i > 0; --i)
        {
            if (isPrm(i) && isPrm(n - i))
            {
                cout << i << endl << n - i << endl;
                break;
            }
        }
    }
    return 0;
}
