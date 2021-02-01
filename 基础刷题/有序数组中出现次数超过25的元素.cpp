1.最优解：利用排序数组的特性
class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == arr[i + size])
                return arr[i];
        }
        return -1;
    }
};
2.动态规划，排序数组，因此出现次数一定是连续的
class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        if (arr.size() == 1)
            return arr[0];
        int size = arr.size() / 4;
        int count = 1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                count++;
                if (count > size)
                    return arr[i];
            }
            else
                count = 1;
        }
        return -1;
    }
};
