#include <iostream>
#include <algorithm>
using namespace std;

bool isPernum(int tar)
{
    int count = 1;
    for (int i = 2; i <= sqrt(tar); i++)
    {
        if (tar % i == 0)
        {
            if (i != sqrt(tar))
                count = count + tar / i + i;
            else
                count += i;
            if (count > tar)
                return false;
        }
    }
    return count == tar;
}
int CotpNum(int n)
{
    int res = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPernum(i))
            res++;
    }
    return res;
}
int main()
{
    int n;
    while (cin >> n)
    {
        cout << CotpNum(n) << endl;
    }
    return 0;
}