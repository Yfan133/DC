#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> dp(M + 1, 0);
    dp[N] = 1;
    for (int i = N; i < M; i++)
    {
        if (dp[i] == 0)                    //如果当前石板为0，则说明不可能从该跳板往后跳
            continue;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)                // 如果是约数则进行
            {
                int num1 = i + j;        // 约数中较小数
                int num2 = i + i / j;    // 约数中较大数
                if (num1 > M)             // 若较小数都大于M则直接跳出
                    break;
                if (dp[num1] == 0)
                    dp[num1] = dp[i] + 1;
                else
                    dp[num1] = min(dp[num1], dp[i] + 1);
                if (num2 <= M)
                {
                    if (dp[num2] == 0)
                        dp[num2] = dp[i] + 1;
                    else
                        dp[num2] = min(dp[num2], dp[i] + 1);
                }
            }
        }
    }
    cout << dp[M] - 1 << endl;
    return 0;
}
