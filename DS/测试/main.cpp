#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string a("qwer");
	string b;
	b += a.substr(0, 0);
	b += a.substr(4);
	return 0;
}