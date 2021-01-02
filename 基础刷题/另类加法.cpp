class UnusualAdd {
public:
    int addAB(int A, int B)
    {
        // write code here
        //1.先不进位相加^
        //2.再只进位相加&<<1
        //3.只要进位为0则循环结束
        while (B != 0)
        {
            int car = A ^ B;
            B = (A & B) << 1;
            A = car;
        }
        return A;
    }
};