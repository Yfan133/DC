#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
string Sum(string& num1, string& num2)
{
    int size = num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1;
    string res(size, '0');    //设置容量123 1 4 124
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int car = 0;        //进位
    --size;
    while (i >= 0 || j >= 0 || car != 0)
    {
        int l = 0;
        int r = 0;
        if (i >= 0)
            l = num1[i] - '0';
        if (j >= 0)
            r = num2[j] - '0';
        int sum = l + r + car;
        car = sum - 10;
        res[size] = sum % 10 + '0';
        --size;
        --i;
        --j;
    }
    if (res[0] == '0')
        res.erase(res.begin());
    //reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string a, b;
    while (cin >> a)
    {
        cin >> b;
        cout << Sum(a, b) << endl;
    }
    return 0;
}