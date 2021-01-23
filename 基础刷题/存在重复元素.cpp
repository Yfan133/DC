class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // 1.hashӳ�䣬ʱ�临�Ӷ�O(n)
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