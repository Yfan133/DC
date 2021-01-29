#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//#define fib(a, b) a + b
string Add(string& a, string& b)
{
    string res;
    int car = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || car)
    {
        int l = 0;
        int r = 0;
        if (i >= 0)
            l = a[i] - '0';
        if (j >= 0)
            r = b[j] - '0';
        int sum = l + r + car;
        car = sum / 10;
        res.push_back(sum % 10 + '0');
        i--;
        j--;
    }
    return res;
}
int main()
{
    // 两边之和大于第三边
    string s1, s2, s3;
    while (cin >> s1 >> s2)
    {
        if (s1.size() > s2.size() || s1 > s2)
            swap(s1, s2);
        cin >> s3;
        if (s2.size() > s3.size() || s2 > s3)
            swap(s2, s3);
        string res = Add(s1, s2);
        if (res.size() > s3.size())
            cout << "Yes" << endl;
        else if (res.size() == s3.size())
        {
            if (res > s3)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}