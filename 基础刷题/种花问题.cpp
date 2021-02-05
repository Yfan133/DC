class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)     //这个问题就是循环数组，检测该位置的前后是否有花，然后比较最终答案 
    {
        int count = 0;
        int sz = flowerbed.size();
        for (int i = 0; i < sz; i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == sz - 1 || flowerbed[i + 1] == 0))    //如果该位置的前后都是空的，则表示该位置可以种花
            {
                flowerbed[i] = 1;   //记得种花之后要把该位置设置为1
                count++;
            }
        }
        return count >= n;
    }
};
