#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<list>
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

/*



*/
//int length_go(string& code)
//{
//    size_t size = code.size();
//    if (size <= 4)
//        return 5;
//    if (size >= 8)
//        return 25;
//    return 10;
//}
//int other_go(string& code)
//{
//    int al[2] = { 0 };    //用两个标志位存储大小写
//    int dig = 0;
//    int ch = 0;
//    int res = 0;
//    for (int i = 0; i < code.size(); i++)
//    {
//        if (code[i] >= 'A' && code[i] <= 'Z')
//            al[0] = 1;
//        else if (code[i] >= 'a' && code[i] <= 'z')
//            al[1] = 1;
//        else if (code[i] >= '0' && code[i] <= '9')
//            dig++;
//        else
//            ch++;
//    }
//    //字母
//    if (al[0] == 1 && al[1] == 1)res += 20;
//    else if (al[0] == 1 || al[1] == 1)res += 10;
//    //数字
//    if (dig > 1)res += 20;
//    else if (dig == 1)res += 10;
//    //符号
//    if (ch > 1)res += 25;
//    else if (ch == 1)res += 10;
//    //奖励
//    if (al[0] == 1 && al[1] == 1 && dig > 0 && ch > 0)res += 5;
//    else if ((al[0] == 1 || al[1] == 1) && dig > 0 && ch > 0)res += 3;
//    else if (dig > 0 && (al[0] == 1 || al[1] == 1))res += 2;
//    return res;
//}
//int main()
//{
//    string code;
//    while (getline(cin, code))
//    {
//        int goal = 0;
//        goal += length_go(code);
//        goal += other_go(code);
//        if (goal >= 90)cout << "VERY_SECURE" << endl;
//        else if (goal >= 80)cout << "SECURE" << endl;
//        else if (goal >= 70)cout << "VERY_STRONG" << endl;
//        else if (goal >= 60)cout << "STRONG" << endl;
//        else if (goal >= 50)cout << "AVERAGE" << endl;
//        else if (goal >= 25)cout << "WEEK" << endl;
//        else cout << "VERY_WEEK" << endl;
//    }
//    return 0;
//}



