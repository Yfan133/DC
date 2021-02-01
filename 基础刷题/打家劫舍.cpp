class Solution {
public:
    int robCount(vector<int> nums)
    {
        int cur = 0, pre = 0, tmp;
        for (int i : nums)
        {
            tmp = cur;  //tmp����cur��ǰ��״̬
            cur = max(pre + i, cur);    //curȡ pre + i (cur��ǰһ����+��һ����) �� cur �нϴ����
            pre = tmp;  //pre��¼cur��һ��״̬
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
