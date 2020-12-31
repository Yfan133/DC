#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<int> vc(num, 0);
	for (int i = 0; i < num; i++)
		cin >> vc[i];
	int res = vc[0];
	int tmp;
	for (int i : vc)
	{
		tmp += i;
		tmp = max(tmp, i);
		res = max(res, tmp);
	}
	cout << res << endl;
	return 0;
}
