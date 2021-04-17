class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int cnt[256] = { 0 };
        int ans = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            cnt[s[right]]++;
            while ((left != right) && (cnt[s[right]] > 1))
            {
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};