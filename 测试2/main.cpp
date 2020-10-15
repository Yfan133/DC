#include<iostream>
using namespace std;
#pragma warning (disable:4996)
int main()
{
    float x1 = 92.0000, x2 = 22.3;
    double x3 = 92.0000, x4 = 22.3;
    printf("%.4f %.4lf", x1 * x2, x3 * x4);
    return 0;
}
