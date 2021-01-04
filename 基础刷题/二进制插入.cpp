1. 这里保证了 i - j + 1 必定是 0
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i)
    {
        // write code here
        return n | m << j;
    }
};
2. 如果不保证 i - j + 1 为 0
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
