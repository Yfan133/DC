class Board {
public:
    bool checkWon(vector<vector<int> > board)
    {
        // write code here
        // �����û�нݾ�����ÿ��λ�ö����һ��
        int row = board.size();
        //���ÿһ��
        int i;
        for (i = 0; i < row; i++)
        {
            if (board[i][0] + board[i][1] + board[i][2] == row)
                return true;
        }
        //���ÿһ��
        for (i = 0; i < row; i++)
        {
            if (board[0][i] + board[1][i] + board[2][i] == row)
                return true;
        }
        //���Խ���
        if (board[0][0] + board[1][1] + board[2][2] == row || board[0][2] + board[1][1] + board[2][0] == row)
            return true;
        return false;
    }
};
