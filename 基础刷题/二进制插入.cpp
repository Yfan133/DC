1. ���ﱣ֤�� i - j + 1 �ض��� 0
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i)
    {
        // write code here
        return n | m << j;
    }
};
2. �������֤ i - j + 1 Ϊ 0
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i)
    {
        // write code here
        int tmp = m;
        int setZero = 0;
        while (tmp)
        {
            setZero <<= 1;
            setZero |= 1;
            tmp >>= 1;
        }
        for (; tmp < j; tmp++)
        {
            setZero <<= 1;
            m <<= 1;
        }
        return n & (~setZero) | m;
    }
};
