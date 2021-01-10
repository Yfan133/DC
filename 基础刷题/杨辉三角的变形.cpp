#include <iostream>
#include <vector>
using namespace std;

int OddPos(int n)
{
    vector<int> board(2 * n - 1, 0);
    board[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < 2 * i - 1; j++)
        {
            board[j] = board[j - 1] + board[j];
            if (i == n && board[j] % 2 == 0)
            {
                return j + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << OddPos(n) << endl;
    }
    return 0;
}