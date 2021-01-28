#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable:4996)

//int main()
//{
//	map<string, int> board;
//	board.insert(make_pair("oo", 45));
//	board.insert(make_pair("apple", 1));
//	board.insert(make_pair("bana", 2));
//	for (auto it : board)
//		cout << it.first << " " << it.second << endl;
//	board["apple"] = 5;
//	return 0;
//}

void EnterBow(long long n, long long r)
{
    n = n / 2 / 3.14;
    if (r < n)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
int main()
{
    long long n, r;
    cin >> n >> r;
    EnterBow(n, r);
    return 0;
}