class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)     //sort�ıȽϺ���һ��Ҫ���ó�static���εľ�̬��Ա����ֹ������thisָ��
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
������ע��㣺(Ӱ��Ч��)
1.sort�ıȽϺ���һ��Ҫstatic����
2.cmp�Ĳ����б�һ��Ҫ���ã����ÿ����¿ռ����Ч��
3.forѭ���ﾡ����Ҫÿ�ζ��ж� i < intervals.size() �����ή��Ч��
    4.�ȽϺ�����bool���ͣ�����"���Ϊ������"
