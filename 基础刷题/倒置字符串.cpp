1.
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string ar;
	getline(cin, ar);
	string res;
	int left = ar.size() - 1;
	int right = left;
	while (left >= 0)
	{
		while (left >= 0 && ar[left] != ' ')
			left--;
		res += ar.substr(left + 1, right - left);
		if (left >= 0)
			res += ' ';
		left--;
		right = left;
	}
	cout << res << endl;
	return 0;
}
2.
#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
