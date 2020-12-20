#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int> ar;
	ar.insert(5);
	if (ar.find(5) == ar.end())
		printf("hh");
	return 0;
}