class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        if (n == 4) return 4;
        long res = 1;
        while (n > 4)
        {
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }
        // ���n��ֵֻ�п����ǣ�2��3��4����2��3��4�ܵõ������˻�ǡǡ��������ֵ
        // ��Ϊ2��3����Ҫ�ټ��ˣ����˷�����С����4����2x2�����ģ�2x2ǡ�ɵ���4
        return res * n % 1000000007;
    }
};