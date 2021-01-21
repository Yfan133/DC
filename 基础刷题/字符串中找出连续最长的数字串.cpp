#include <iostream>
#include <string>
using namespace std;
int main()
{
    string res, cur, str;
    cin >> str;
    int i = 0;
    while (i < str.size())
    {
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
            cur.push_back(str[i++]);
        if (cur.size() > res.size())
            res = cur;
        if (cur.size() != 0)
            cur.clear();
        i++;
    }
    cout << res << endl;
    return 0;
}
