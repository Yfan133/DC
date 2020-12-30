class Solution
{
public:
    // ��ʶ��
    // +/- ��������ʼ����ǰһ��λ�ñ�����e
    // . ǰ�治����e
    // . �� e ���ֻ����һ��
    // e�ĺ�������ݣ����ֻ�ܺ�������
    // �ж�һ���ַ����Ƿ������֣�ֻ���ж�is_num
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
            if (s[i] == '+' || s[i] == '-')  // ��λ��Ϊ��ʼ������ǰһ��λ����e��E
            {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (s[i] == 'e' || s[i] == 'E')   //��һ�γ��֣�����ǰ��Ҫ������
            {
                if (is_e || !is_num)
                    return false;
                is_e = true;
                is_num = false;     //ֻҪe������Ҫ�������
            }
            else if (s[i] >= '0' && s[i] <= '9')   //���ֿ��Գ������κ�λ��
            {
                is_num = true;
            }
            else if (s[i] == '.')       //ǰ�治����e��.��ǰ�����������
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