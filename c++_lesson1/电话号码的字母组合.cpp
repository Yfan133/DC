class Solution {
public:
    vector<string> board = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> res;
    string st;
    void dfs(string digits, int n)
    {
        if (n == digits.size())
        {
            res.push_back(st);
            //st.pop_back();
            return;
        }
        for (int i = 0; i < board[digits[n] - '0'].size(); i++)
        {
            st.push_back(board[digits[n] - '0'][i]);
            dfs(digits, n + 1);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;
        dfs(digits, 0);
        return res;
    }
};