class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)     //sort的比较函数一定要设置成static修饰的静态成员，防止隐含的this指针
    {
        return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int res = n;
        int max = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (max >= intervals[i][1])
                res--;
            else
                max = intervals[i][1];
        }
        return res;
    }
};
有三个注意点：(影响效率)
1.sort的比较函数一定要static修饰
2.cmp的参数列表一定要引用，不用开辟新空间提高效率
3.for循环里尽量不要每次都判定 i < intervals.size() 这样会降低效率
    4.比较函数是bool类型，返回"结果为真的情况"
