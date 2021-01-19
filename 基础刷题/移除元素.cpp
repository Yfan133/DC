class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] == val)
            {
                while (right >= left && nums[right] == val)
                    right--;
                if (left < right)
                {
                    nums[left] = nums[right];
                    left++;
                    right--;
                }
            }
            else
                left++;
        }
        return left;
    }
};