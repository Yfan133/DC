class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) { return s.length(); }

        int res = -1, right = 0;
        unordered_set<char> store;

        for (int left = 0; left < s.length(); ++left) {
            while (right < s.length() && !store.count(s[right])) {
                store.insert(s[right]);
                ++right;
            }

            res = max(res, right - left);
            store.erase(s[left]);

            if (right >= s.length()) { break; }
        }

        return res;
    }
};