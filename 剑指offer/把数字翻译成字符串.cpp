class Solution
{
    //1 8 8 2 2
    //18 8 2 2
    //18 8 22
    //1 8 8 22
public:
    int translateNum(int num) //18822   4��
    {
        int dp[2] = { 1,1 };
        string ar = to_string(num);
        for (int i = 1; i < ar.size(); i++)
        {
            int c = dp[1];
            string tmp = ar.substr(i - 1, 2);
            if (tmp >= "10" && tmp <= "25")
                c += dp[0];               //�����������������10��25�ķ�Χ�ڣ���dp[1]=dp[0]+dp[1]��
            dp[0] = dp[1];                //����dp��0��1�л�ֵҪ�����ж�������棬��Ȼ������
            dp[1] = c;
        }
        return dp[1];
    }
};