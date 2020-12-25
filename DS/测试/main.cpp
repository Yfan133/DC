#include <iostream>
#include <set>
using namespace std;
#define mod 1000007
int mi(int x, int t)
{
    int r = 1;
    for (; t; t >>= 1) 
    {
        if (t & 1) //为奇数则进去
            r = (long long)r * x % mod;
        x = (long long)x * x % mod;
    }
    return r;
}
int cuttingRope(int n) 
{
    if (n < 4)
        return n - 1;
    int t = n / 3;
    int r = n % 3;
    if (r == 0) 
        return mi(3, t) % mod;
    else if (r == 1) 
        return (long long)mi(3, t - 1) * 4 % mod;
    else 
        return (long long)mi(3, t) * 2 % mod;
}
int main()
{
    mi(3, 5);
    //cuttingRope(100);
	return 0;
}