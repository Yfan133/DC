#include<iostream>
using namespace std;
#pragma warning (disable:4996)
int main()
{
    char target;
    int sum_a = 0, sum_b = 0;
    while ((target = getchar()) != '0')
    {
        if (target == 'A')
            sum_a++;
        else if (target == 'B')
            sum_b++;
    }
    if (sum_a > sum_b)
        cout << 'A';
    else if (sum_a < sum_b)
        cout << 'B';
    else
        cout << 'E';
    return 0;
}