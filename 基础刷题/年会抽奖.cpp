// write your code here cpp
#include <iostream>
using namespace std;
int main()
{
    // 动态规划，划分每个人拿错的子问题
    // 1.如果a拿错，则剩下(n-1)个人会拿到a
    // 2.若b拿到了a，，则b的名字可能被a拿到，也可能被剩下的(n-2)个人拿到
    // 因此i个人拿错的情况有：dp[i] = (i-1) * (dp[i-1]+dp[i-2]);
    long long WrongSec[21] = { 0, 0, 1 };
    long long AllSec[21] = { 0, 1, 2 };
    for (int i = 3; i < 21; i++)
    {
        WrongSec[i] = (i - 1) * (WrongSec[i - 1] + WrongSec[i - 2]);
        AllSec[i] = i * AllSec[i - 1];
    }
    int n;
    while (cin >> n)
    {
        double f = (double)WrongSec[n] / (double)AllSec[n] * 100;
        printf("%4.2f%\n", f);
    }
    return 0;
}