#include <iostream>

using namespace std;
// f(n) = f(n - 1) + f(n - 2);
int RitCount(int mounth)
{
    if (mounth < 3)
        return 1;
    // dp[0]:代表下个月可生产
    // dp[1]:代表可生产
    int res;
    int dp[2] = { 1, 1 };
    for (int i = 3; i <= mounth; i++)
    {
        res = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = res;
    }
    return res;
}
int main()
{
    int mounth;
    while (cin >> mounth)
    {
        cout << RitCount(mounth) << endl;
    }
    return 0;
}
