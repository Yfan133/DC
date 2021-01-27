#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//#define fib(a, b) a + b
bool RightPos(int value, int pos)
{
    if (value & 1)
    {
        return pos & 1;
    }
    if (pos == 0)
        return true;
    return !(pos & 1);
}
void oddInOddEvenInEven(vector<int>& arr, int len)
{
    int left = 0, right = 1;
    while (left < len && right < len)
    {
        while (left < len && RightPos(arr[left], left))
            left += 2;
        while (right < len && RightPos(arr[right], right))
            right += 2;
        if (left < len && right < len)
            swap(arr[left], arr[right]);
    }
}
int main()
{
    vector<int> arr = { 1,2,3,4 };
    oddInOddEvenInEven(arr, 4);
    return 0;
}