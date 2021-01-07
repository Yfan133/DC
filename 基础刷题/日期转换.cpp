#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int main()
{
    int board[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    int y, m, d;
    while (cin >> y >> m >> d)
    {
        int res = 0;
        res += board[m - 1];
        res += d;
        if (isLeapYear(y) && m > 2)
            res += 1;
        cout << res << endl;
    }
    return 0;
}