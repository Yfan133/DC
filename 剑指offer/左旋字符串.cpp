class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        string s1, s2;
        s1 = s.substr(0, n);
        s2 = s.substr(n, s.size());
        return s2 + s1;
    }
};