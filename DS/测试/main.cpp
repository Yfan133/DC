#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//int main()
//{
//	int a;
//	float b, c, d;
//	scanf("%2d%3f%4f", &a, &b, &c);
//	scanf("%f", &d);
//	printf("%d, %f, %f", a, b, c);
//	printf("\n%f", d);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	printf("%d %d\n", i++, i++);	//21 i==3
//	printf("%d %d\n", ++i, ++i);	//55 i==5
//	printf("%d %d\n", ++i, i++);	//75
//	printf("%d %d\n", i++, ++i);	//89
//	return 0;
//}
vector<int> res;
vector<char> board = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
void dfs(int index, int n, string& str)
{
    if (index == n)
    {
        int tmp = atoi(str.c_str());
        if (tmp != 0)
            res.push_back(tmp);
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        str.push_back(board[i]);
        dfs(index + 1, n, str);
        str.pop_back();
    }
}
vector<int> printNumbers(int n)
{
    string str;
    dfs(0, n, str);
    return res;
}
int main()
{
    printNumbers(3);
	return 0;
}