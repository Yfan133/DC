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
//    // δ��գ�ת��ʧ��
//    ss << val_2;
//    ss >> s;
//    
//    cout << s << endl;
//    return 0;
//}
//// ת����ָ���������͵�string����ת����һ�Σ�
#include <iostream>
#include <queue>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    // 1.����һֻ����ѣ�����һֻС����
    priority_queue<int, vector<int>, less<int>> Q1;     // ����ѣ����ڴ��һ���С����
    priority_queue<int, vector<int>, greater<int>> Q2;  // С���ѣ����ڴ��һ��ϴ����
    int flag = 0;
    MedianFinder() {}

    void addNum(int num) {
        if (flag & 1)
        {
            // ����������С����������ݣ���ȡ������е����ֵ
            Q1.push(num);
            num = Q1.top();
            Q1.pop();
            Q2.push(num);
        }
        else
        {
            // ż�������������������ݣ���ȡС�����е���Сֵ
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
// 37����
