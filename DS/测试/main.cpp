#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<list>
#include <algorithm>
//#include<stack>
using namespace std;
#pragma warning(disable:4996)
//int Quick(vector<int>& arr, int left, int right)
//{
//	
//}
//void QuickSort(vector<int>& arr,int left,int right)
//{
//	
//}
//int main()
//{
//	vector<int> arr = { 49,38,56,75,12,99,68,75,49 };
//	QuickSort(arr, 0, arr.size());
//	return 0;
//}


bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
int removeCoveredIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(), cmp);
    int res = intervals.size();
    int max = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (max > intervals[i][1])
            res--;
        else
            max = intervals[i][1];
    }
    return res;
}
int main()
{
    vector<vector<int>> vv = { {1,4},{3,6},{2,8},{4,5} };
    removeCoveredIntervals(vv);
	return 0;
}
//void fun(const int& a,const int& b)
//{
//	cout << a << ' ' << b << endl;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int x = 0;
//	int y = 0;
//	fun(i++, i);	//第一个参数：i的一份临时值  第二个参数：i的一份拷贝
//	fun(j++, ++j);	
//	fun(++x, x++);
//	fun(++y, ++y);
//	return 0;
//}
