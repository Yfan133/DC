class Solution
{
public:
    vector<string> res;
    void Arrange(string& s, int index)
    {
        if (index == s.size() - 1)
        {
            res.push_back(s);
            return;
        }
        int map[1024] = { 0 };    //��ϣ�����ڼ�飬�Ƿ��ظ�
        for (int i = index; i < s.size(); i++)   //ÿ��Ԫ�ض�Ҫ��һ�� index ��λ�ã�
        {
            if (map[s[i]] == 1)  //����ظ�continue
                continue;
            swap(s[i], s[index]);   //��������λ��
            Arrange(s, index + 1);
            swap(s[i], s[index]);   //��������

            map[s[i]] = 1;      //��λ�õĹ�ϣ������Ϊ1����ʾ��λ���Ѿ��й�Ԫ�� s[i]
        }
    }
    vector<string> permutation(string s)
    {
        if (s.size() == 0)
            return res;
        Arrange(s, 0);
        return res;
    }
};