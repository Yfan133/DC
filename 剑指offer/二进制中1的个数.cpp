class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        // 1.λ����
        int res = 0;
        while (n)
        {
            res++;
            n = n & (n - 1);
        }
        return  res;
    }
};
