#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int res = 0;
        int count = 0;
        while (num)
        {
            if (num & 1)    //���num���bitΪ1
            {
                count++;
                res = max(res, count);
            }
            else
                count = 0;
            num >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}
