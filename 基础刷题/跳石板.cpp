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
        if (dp[i] == 0)                    //�����ǰʯ��Ϊ0����˵�������ܴӸ�����������
            continue;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)                // �����Լ�������
            {
                int num1 = i + j;        // Լ���н�С��
                int num2 = i + i / j;    // Լ���нϴ���
                if (num1 > M)             // ����С��������M��ֱ������
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
