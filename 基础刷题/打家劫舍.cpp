class Solution {
public:
    int robCount(vector<int> nums)
    {
        int cur = 0, pre = 0, tmp;
        for (int i : nums)
        {
            tmp = cur;  //tmp保存cur当前的状态
            cur = max(pre + i, cur);    //cur取 pre + i (cur的前一个数+后一个数) 和 cur 中较大的数
            pre = tmp;  //pre记录cur上一次状态
        }
        return cur;
    }
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        return max(robCount(vector<int>(nums.begin(), nums.end() - 1)), robCount(vector<int>(nums.begin() + 1, nums.end())));
    }

};
