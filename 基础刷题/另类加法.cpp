class UnusualAdd {
public:
    int addAB(int A, int B)
    {
        // write code here
        //1.�Ȳ���λ���^
        //2.��ֻ��λ���&<<1
        //3.ֻҪ��λΪ0��ѭ������
        while (B != 0)
        {
            int car = A ^ B;
            B = (A & B) << 1;
            A = car;
        }
        return A;
    }
};