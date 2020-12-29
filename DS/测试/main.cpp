#include <iostream>
#include <set>
#include <vector>
using namespace std;
int robCount(vector<int> nums)
{
    int cur = 0, pre = 0, tmp;
    for (int i : nums)
    {
        tmp = cur;  //tmp保存cur当前的状态
        cur = max(pre + i, cur);    //cur取前个数加后个数 he 当前较大的数
        pre = tmp;  //把cur上次的状态重新赋值给pre
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
int main()
{
    vector<int> vc = { 1, 5, 1, 2, 6, 9 };
    rob(vc);
	return 0;
}