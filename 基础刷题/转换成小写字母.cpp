class Solution {
public:
    string toLowerCase(string str)
    {
        if (str.size() == 0)
            return str;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                // 32(ʮ����) -> 10 0000(������)
                //str[i] += 32;
                //str[i] = str[i] - 'A' + 'a';
                str[i] |= (1 << 5);
            }
        }
        return str;
    }
};