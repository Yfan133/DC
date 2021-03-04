//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <deque>
//#include <list>
//#include <sstream>
//using namespace std;
//int main()
//{
//    string s;
//    stringstream ss;
//    int val_1 = 10;
//    ss << val_1;
//    ss >> s;
//    
//    //ss.str("");
//    //ss.clear();
//    
//
//    double val_2 = 12.3;
//    // 未清空，转化失败
//    ss << val_2;
//    ss >> s;
//    
//    cout << s << endl;
//    return 0;
//}
//// 转化是指：其它类型到string，若转化过一次，
#include <iostream>
#include <queue>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    // 1.左手一只大根堆，右手一只小根堆
    priority_queue<int, vector<int>, less<int>> Q1;     // 大根堆，用于存放一半较小的数
    priority_queue<int, vector<int>, greater<int>> Q2;  // 小根堆，用于存放一半较大的数
    int flag = 0;
    MedianFinder() {}

    void addNum(int num) {
        if (flag & 1)
        {
            // 奇数个：往小根堆里插数据，先取大根堆中的最大值
            Q1.push(num);
            num = Q1.top();
            Q1.pop();
            Q2.push(num);
        }
        else
        {
            // 偶数个：往大根堆里插数据，先取小根堆中的最小值
            Q2.push(num);
            num = Q2.top();
            Q2.pop();
            Q1.push(num);
        }
        flag ^= 1;
    }

    double findMedian() {
        double ans = (double)Q1.top() + (double)Q2.top();
        return ans / 2;
    }
};
int main()
{
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    double k =m.findMedian();
    m.addNum(3);
    int p = m.findMedian();
    return 0;
}
// 37互娱
