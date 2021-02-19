class Solution
{
public:
    bool isalpha(char data)
    {
        return(data >= 'a' && data <= 'z' || data >= 'A' && data <= 'Z');
    }
    void swap(char& left, char& right)
    {
        char tmp = left;
        left = right;
        right = tmp;
    }
    string reverseOnlyLetters(string S)
    {
        if (S.empty())
            return S;
        char* pleft = (char*)S.c_str();
        char* pright = pleft + (S.length() - 1);
        while (pleft < pright)
        {
            while (pleft < pright)
            {
                if (isalpha(*pleft))
                    break;
                ++pleft;
            }
            while (pleft < pright)
            {
                if (isalpha(*pright))
                    break;
                --pright;
            }
            swap(*pleft, *pright);
            pleft++;
            pright--;
        }
        return S;
    }
};