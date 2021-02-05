// write your code here cpp
#include <iostream>
using namespace std;
int main()
{
    // ��̬�滮������ÿ�����ô��������
    // 1.���a�ô���ʣ��(n-1)���˻��õ�a
    // 2.��b�õ���a������b�����ֿ��ܱ�a�õ���Ҳ���ܱ�ʣ�µ�(n-2)�����õ�
    // ���i�����ô������У�dp[i] = (i-1) * (dp[i-1]+dp[i-2]);
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