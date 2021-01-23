class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        int l = 0, r = 0;
        while (l < name.size() && r < typed.size())
        {
            if (name[l] != typed[r])
            {
                if (r > 0 && typed[r] == typed[r - 1])
                    r++;
                else
                    return false;
            }
            else
            {
                l++;
                r++;
            }
        }
        if (l != name.size())
            return false;
        while (r < typed.size())
        {
            if (typed[r] != typed[r - 1])
                return false;
            r++;
        }
        return true;
    }
};