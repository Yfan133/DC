#include <iostream> 
#include <vector> 
using namespace std;
int main()
{
	int n; cin >> n;
	vector<int> ar;
	ar.resize(n);
	for (int& i : ar)
		cin >> i;
	int res = 0;
	int i = 0;
	while (i < n)
	{
		if (ar[i] < ar[i + 1])
		{
			while (i < n - 1 && ar[i] <= ar[i + 1]) //这里一定是<=，如果遇到等于也跳过 
				i++;
			res++;
			i++; //这里就是为什么不会越界，在查找完一次子序列之后，i++两次指向子序列下一个元素。 
		}
		else if (ar[i] > ar[i + 1])
		{
			while (i < n - 1 && ar[i] >= ar[i + 1])
				i++;
			res++;
			i++;
		}
		else
			i++; //如果第一个数就是和下一个相等则
	}
	cout << res << endl;
	return 0;
}
