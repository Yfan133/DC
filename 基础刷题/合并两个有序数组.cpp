class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0)
            return;
        int p = m + n - 1;
        --m;
        --n;
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[p] = nums1[m];
                p--;
                m--;
            }
            else
            {
                nums1[p] = nums2[n];
                p--;
                n--;
            }
        }
        if (m < 0)
        {
            while (n >= 0)
            {
                nums1[p--] = nums2[n--];
            }
        }
    }
};