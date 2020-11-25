#include<iostream>
#include<string>
#include<vector>
#include<queue>
//#include<stack>
using namespace std;
#pragma warning(disable:4996)
//int Quick(vector<int>& arr, int left, int right)
//{
//	
//}
//void QuickSort(vector<int>& arr,int left,int right)
//{
//	
//}
//int main()
//{
//	vector<int> arr = { 49,38,56,75,12,99,68,75,49 };
//	QuickSort(arr, 0, arr.size());
//	return 0;
//}

    vector<double> dicesProbability(int n)
    {
        int dp[15][70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++)               //n=2
        {
            for (int j = i; j <= 6 * i; j++)         //从2开始到12结束。
            {
                for (int cur = 1; cur <= 6; cur++)
                {
                    if (j - cur <= 0)
                    {
                        break;
                    }
                    dp[i][j] += dp[i - 1][j - cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i++) 
        {
            ret.push_back(dp[n][i] * 1.0 / all);
        }
        return ret;
    }

int main()
{
    dicesProbability(2);
    return 0;
}

