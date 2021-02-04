#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int main()
{
    map<string, int> table;
    table.insert(make_pair<string, int>("Æ»¹û", 2));
    table.insert(pair<string, int>("Àõ×Ó", 3));
    auto it = table.begin();
    cout << (*it).second << endl;
    cout << it->first << " " << it->second << endl;
    return 0;
}