class Solution {
public:
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
};