class Solution
{
    //1 8 8 2 2
    //18 8 2 2
    //18 8 22
    //1 8 8 22
public:
    int translateNum(int num) //18822   4种
    {
        int dp[2] = { 1,1 };
        string ar = to_string(num);
        for (int i = 1; i < ar.size(); i++)
        {
            int c = dp[1];
            string tmp = ar.substr(i - 1, 2);
            if (tmp >= "10" && tmp <= "25")
                c += dp[0];               //如果两个数加起来在10到25的范围内，则dp[1]=dp[0]+dp[1]；
            dp[0] = dp[1];                //这里dp的0和1切换值要放在判断语句外面，不然会少算
            dp[1] = c;
        }
        return dp[1];
    }
};