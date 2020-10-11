#include<iostream>
using namespace std;
#pragma warning (disable:4996)
int main()
{
    float price, pay;
    int month, date, coupon;
    scanf("%f %d %d %d", &price, &month, &date, &coupon);
    if (month == 11 && date == 11)
    {
        pay = price * 0.7;
        if (coupon)
            pay -= 50;
    }
    else if (month == 12 && date == 12)
    {
        pay = price * 0.8;
        if (coupon)
            pay -= 50;
    }
    if (pay < 0)
        cout << 0.00;
    else
        cout << pay;
    return 0;
}