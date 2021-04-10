#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int> nums)
    {
        vector<int> tails(nums.size()); // 代表长度为 k+1 尾部的元素
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 二分查找
            int left = 0, right = res; // res代表尾部元素数列的元素个数
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (tails[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            tails[left] = nums[i];
            if (res == right)
                res++;
        }
        return res;
    }
};
int main()
{
    Solution a;
    a.lengthOfLIS(vector<int>{7, 2, 3, 1, 5, 8, 9, 6});
	return 0;
}