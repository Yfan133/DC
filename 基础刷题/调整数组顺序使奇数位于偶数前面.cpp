class Solution {
public:
    void reOrderArray(vector<int>& array)
    {
        int l = 0, r = array.size() - 1;
        while (l < r)
        {
            while (l < r && array[l] % 2 == 1)    //该数为奇
                l++;
            if (array[l + 1] % 2 == 0)    //如果下一个也为偶数，则倒着来
            {
                while (l < r && array[r] % 2 == 0)
                    r--;
                if ()
            }
            else    //下一个为奇数，则交换两数位置
            {
                swap(array[l], array[l + 1]);
                l++;
            }
        }
    }
};
