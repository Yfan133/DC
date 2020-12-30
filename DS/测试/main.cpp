#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
bool isMatch(string s, string p)
{
    int l = 0, r = 0;
    while (l < s.size() && r < s.size())
    {
        if (s[l] == p[r])
        {
            l++;
            r++;
        }
        else
        {
            if (p[r] == '.')
            {
                p[r] = s[l];
                l++;
                r++;
            }
            else if (p[r] == '*')
            {
                int pos_s = l + 1;
                int pos_p = r + 1;
                //先统计 s 中从位置 l 开始相同的字符
                while (pos_s < s.size() && s[pos_s] == s[l])
                {
                    pos_s++;
                }
                int s_len = pos_s - l;
                while (pos_p < p.size() && p[pos_p] == p[r - 1])
                {
                    pos_p++;
                }
                int p_len = pos_p - r;
                if (p_len > s_len + 1)
                    return false;
                l = pos_s;
                r = pos_p;
            }
            else    //防止 aab c*a*b 的情况
            {
                if (r + 1 < p.size() && p[r + 1] == '*')
                {
                    r += 2;
                }
                else
                    return false;
            }
        }
    }
    return l == s.size() && r == p.size();
}
int main()
{
    isMatch(string("aab"), string("c*a*b"));
	return 0;
}