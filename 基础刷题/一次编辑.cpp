class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first == second) {
            return true;
        }
        const int len1 = first.size();
        const int len2 = second.size();
        if (abs(len1 - len2) > 1) {
            return false;
        }
        int i = 0, j = len1 - 1, k = len2 - 1;
        while (i < len1 && i < len2 && first[i] == second[i]) { // i´Ó×óÖÁÓÒÉ¨Ãè
            ++i;
        }
        while (j >= 0 && k >= 0 && first[j] == second[k]) { // j¡¢k´ÓÓÒÖÁ×óÉ¨Ãè
            --j;
            --k;
        }
        return j - i < 1 && k - i < 1;
    }
};