class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        // 1.先整体旋转，再找到分界点局部旋转
        // if (k == 0)
        //     return;
        // k = k % nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        // 2.双倍数组
        // if (k == 0)
        //     return;
        // vector<int> board(nums.size() * 2);
        // for (int i = 0; i < board.size(); i++)
        // {
        //     board[i] = nums[i % nums.size()];
        // }
        // k = k % nums.size();
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     nums[i] = board[nums.size() - k + i];
        // }

        // 3.模拟每次旋转

    }
};