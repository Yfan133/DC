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
            if (num & 1)    //如果num最后bit为1
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
