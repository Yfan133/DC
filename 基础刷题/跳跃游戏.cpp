class Solution
{
public:
    bool serch(vector<int>& arr, int start, vector<int>& board)
    {
        if (start < 0 || start > arr.size() - 1 || board[start] == 1)
            return false;
        board[start] = 1;
        if (arr[start] == 0)
            return true;
        return serch(arr, start - arr[start], board) || serch(arr, start + arr[start], board);
    }
    bool canReach(vector<int>& arr, int start)
    {
        vector<int> board(arr.size(), 0);
        return serch(arr, start, board);
    }
};
