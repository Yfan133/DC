#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && str[i] != '"')
            tmp.push_back(str[i]);
        else
        {
            if (str[i] == ' ' && !tmp.empty())
                vec.push_back(tmp);
            else
            {
                i++;
                while (i < str.size() && str[i] != '"')
                {
                    tmp.push_back(str[i]);
                    i++;
                }
                i++;
                vec.push_back(tmp);
            }
            tmp.clear();
        }
    }
    if (!tmp.empty())
        vec.push_back(tmp);
    cout << vec.size() << endl;
    for (auto it : vec)
        cout << it << endl;
    return 0;
}
