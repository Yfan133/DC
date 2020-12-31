#include<iostream>
#include<string>
using namespace std;
bool isbackstring(string& ar)
{
	int left = 0;
	int right = ar.size() - 1;
	while (left < right)
	{
		if (ar[left] != ar[right])
			return false;
		left++;
		right--;
	}
	return true;
}
int main()
{
	string a, b;
	cin >> a >> b;
	int count = 0;
	for (int i = 0; i <= a.size(); i++)
	{
		string c(a);
		c.insert(i, b);
		if (isbackstring(c))
			count++;
	}
	cout << count << endl;
	return 0;
}
