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
// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
