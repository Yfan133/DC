#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//#define fib(a, b) a + b

vector<vector<int>> board;
vector<vector<int>> step;
vector<vector<int>> min_step;
void Way2out(int i, int j, int n, int m)
{
    // 进行剪枝：1.不能走到棋盘外 2.不走回头路 3.不能碰壁
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 1)
        return;
    step.push_back(vector<int>{ i, j });
    if (i == n - 1 && j == m - 1)
    {
        if (min_step.empty() || min_step.size() > step.size())
            min_step = step;
        return;
    }
    board[i][j] = 1;    //标记走过
    Way2out(i - 1, j, n, m);
    Way2out(i + 1, j, n, m);
    Way2out(i, j - 1, n, m);
    Way2out(i, j + 1, n, m);
    board[i][j] = 0;
    step.pop_back();
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        board.resize(n, vector<int>(m, 0));
        //vector<vector<int>> board(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
            }
        }
        Way2out(0, 0, n, m);
        for (auto i : min_step)
            cout << '(' << i[0] << ',' << i[1] << ')' << endl;
    }
    return 0;
}