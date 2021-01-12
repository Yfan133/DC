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
        // ���� board[i][j]Ϊ�棬��ȥ�жϸ�λ���Ƿ���Ч�������λ����Ч�´��жϸ�ʱ����ʡȥ���ж�λ�ú����ĵ��ÿ��� 
        board[i][j] = true;
        if (isCorrect(i, j, k))
        {
            res++;
            // �Ż���ֻ��Ҫ���Һ�����
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
