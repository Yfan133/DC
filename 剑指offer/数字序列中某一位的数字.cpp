class Solution {
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
            return n;
        int digit = 1;    //位数
        long start = 1;    //该位数的起始数值         //注意这里都应该设置成long，因为int到达极限之后会变成最小循环着又来一遍
        long count = 9;    //该位的数总共多少个
        while (n > count)
        {
            n -= count;
            digit++;    //1,2,3....
            start *= 10;  //1,10,100.....
            count = 9 * start * digit;    //9,180,2700
        }
        long num = start + (n - 1) / digit;      //注意这里是模上digit
        int offset = (n - 1) % digit;         //这里也是模上digit
        string num_str = to_string(num);  //转换成字符串
        return int(num_str[offset] - '0');
    }
};