class Solution {
public:
    int res = 0;
    bool isCorrect(int x, int y, int k)
    {
        int count = 0;
        while (x || y)
        {
            if (x)
            {
                count += x % 10;
                x /= 10;
            }
            if (y)
            {
                count += y % 10;
                y /= 10;
            }
        }
        return count <= k;
    }
    void movingboard(int m, int n, int k, int i, int j, vector<vector<bool>>& board)
    {
        if (i < 0 || i == m || j < 0 || j == n || board[i][j])
            return;
        // 先让 board[i][j]为真，再去判断该位置是否有效，如果该位置无效下次判断该时，就省去了判断位置函数的调用开销 
        board[i][j] = true;
        if (isCorrect(i, j, k))
        {
            res++;
            // 优化：只需要向右和下走
            movingboard(m, n, k, i + 1, j, board);
            movingboard(m, n, k, i, j + 1, board);
        }
    }
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool>> board(m, vector<bool>(n, false));
        movingboard(m, n, k, 0, 0, board);
        return res;
    }
};
