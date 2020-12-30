class Solution
{
public:
    // 共识：
    // +/- 必须在起始或者前一个位置必须有e
    // . 前面不能有e
    // . 和 e 最多只能有一个
    // e的后面代表幂，因此只能含有数字
    // 判断一个字符串是否是数字，只需判断is_num
    bool isNumber(string s)
    {
        if (s.size() == 0)
            return false;
        auto it = s.begin();
        while (it != s.end() && *it == ' ')
            it = s.erase(it);
        while (s.size() != 0 && s[s.size() - 1] == ' ')
            s.erase(s.end() - 1);
        if (s.size() == 0)
            return false;
        bool is_num = false, is_e = false, is_dot = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+' || s[i] == '-')  // 该位置为起始，或者前一个位置是e、E
            {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (s[i] == 'e' || s[i] == 'E')   //第一次出现，并且前面要是数字
            {
                if (is_e || !is_num)
                    return false;
                is_e = true;
                is_num = false;     //只要e出现则要清空数字
            }
            else if (s[i] >= '0' && s[i] <= '9')   //数字可以出现在任何位置
            {
                is_num = true;
            }
            else if (s[i] == '.')       //前面不能有e或.，前后必须有数字
            {
                if (is_dot || is_e)
                    return false;
                is_dot = true;
            }
            else
                return false;
        }
        return is_num;
    }
};