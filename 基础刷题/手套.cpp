class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right)
    {
        // write code here
        // 1.当左右手套其中为0时，另一只的一定要拿
        // 2.因此只需要统计每只手套中不为0的手套数量，再减去最小的数
        int l_sum = 0, l_min = INT_MAX;
        int r_sum = 0, r_min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (left[i] * right[i] == 0)
                sum += left[i] + right[i];
            else
            {
                l_sum += left[i];
                r_sum += right[i];
                l_min = min(left[i], l_min);
                r_min = min(right[i], r_min);
            }
        }
        return sum + min(l_sum + 1 - l_min, r_sum + 1 - r_min) + 1;
    }
};
