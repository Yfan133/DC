class Solution {
public:
    int cuttingRope(int n)
    {
        if (n < 4)
            return n - 1;
        int as = n / 3;
        int mod = n % 3;
        if (mod == 0)
            return pow(3, as);
        else if (mod == 1)
            return pow(3, as - 1) * 4;
        else
            return pow(3, as) * mod;
    }
};