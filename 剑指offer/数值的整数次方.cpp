class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) return 1;
        if (x == 0.0 && n < 0) return x; // ��x��0��n�Ǹ�����ʱ���������
        double res = 1.0;
        long exp = n; // ������long���������n=INT_MIN��-n�ͻ�Խ��
        if (n < 0)
        {
            x = 1 / x;
            exp = -exp;
        }
        while (exp)
        {
            // �����ݷ�����λ���㣩
            // ����n=9��9д�ɶ����ƾ���1001
            // ÿ��exp & 1 = 1��ʱ�򣬾�ִ�г˷�����
            if (exp & 1) res *= x;
            x *= x;
            exp >>= 1;
        }
        return res;
    }
};