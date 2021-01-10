#include <iostream>
#include <string>
using namespace std;
string addSum(string& s1, string& s2)
{
	string res;					// ��
	int i = s1.size() - 1;		// ��ʶs1��λ��
	int j = s2.size() - 1;		// ��ʶs2��λ��
	int car = 0;				// ��λ
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			car += s1[i] - '0';
		if (j >= 0)
			car += s2[j] - '0';
		res.push_back(car % 10 + '0');
		car /= 10;
		i--;
		j--;
	}
	if (car)
		res += '1';
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addSum(s1, s2) << endl;
	}
	return 0;
}