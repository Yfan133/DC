class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        // 1.��������ת�����ҵ��ֽ��ֲ���ת
        // if (k == 0)
        //     return;
        // k = k % nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        // 2.˫������
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

        // 3.ģ��ÿ����ת

    }
};