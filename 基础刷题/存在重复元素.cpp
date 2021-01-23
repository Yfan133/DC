class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // 1.hash”≥…‰£¨ ±º‰∏¥‘”∂»O(n)
        unordered_set<int> board;
        for (int it : nums)
        {
            if (board.find(it) != board.end())
                return true;
            board.insert(it);
        }
        return false;
    }
};