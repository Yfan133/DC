class Solution {
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
            return n;
        int digit = 1;    //λ��
        long start = 1;    //��λ������ʼ��ֵ         //ע�����ﶼӦ�����ó�long����Ϊint���Ｋ��֮�������Сѭ��������һ��
        long count = 9;    //��λ�����ܹ����ٸ�
        while (n > count)
        {
            n -= count;
            digit++;    //1,2,3....
            start *= 10;  //1,10,100.....
            count = 9 * start * digit;    //9,180,2700
        }
        long num = start + (n - 1) / digit;      //ע��������ģ��digit
        int offset = (n - 1) % digit;         //����Ҳ��ģ��digit
        string num_str = to_string(num);  //ת�����ַ���
        return int(num_str[offset] - '0');
    }
};