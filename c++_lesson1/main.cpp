//#include<iostream>
//using namespace std;
//#pragma warning (disable:4996)
#include"vc.h"
int main()
{
	bit::vector<int> v0;
	bit::vector<int> v1(5);
	bit::vector<int> v2(v1.begin(), v1.end());
	bit::vector<int> v3(v1);
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(5);
	v0.pop_back();
	v0.swap(v1);
	v0.insert(v0.begin(), 99);
	v0.erase(v0.begin());
	return 0;
}