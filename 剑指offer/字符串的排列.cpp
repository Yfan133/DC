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
        int map[1024] = { 0 };    //哈希表用于检查，是否重复
        for (int i = index; i < s.size(); i++)   //每个元素都要坐一次 index 的位置！
        {
            if (map[s[i]] == 1)  //如果重复continue
                continue;
            swap(s[i], s[index]);   //交换两个位置
            Arrange(s, index + 1);
            swap(s[i], s[index]);   //交换回来

            map[s[i]] = 1;      //该位置的哈希表设置为1，表示该位置已经有过元素 s[i]
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