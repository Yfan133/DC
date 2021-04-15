#include <iostream>
#include <vector>
using namespace std;
int minStep(int n)
{
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int step = INT_MAX;
		if (i % 3 == 0)
			step = min(step, dp[i / 3]);
		if (i % 2 == 0)
			step = min(step, dp[i / 2]);
		step = min(step, dp[i - 1]);
		step += 1;
		dp[i] = step;
	}
	return dp[n];
}
int main()
{
	int n = 10;
	int res = minStep(n);
	return 0;
}