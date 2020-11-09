#include<iostream>
#include<string>
using namespace std;

void Test(void* t)
{
	cout << "void*" << endl;
}
void Test(int t)
{
	cout << "int" << endl;
}
int main()
{
	int* p = NULL;
	int* pt = nullptr;
	Test(NULL);
	Test(nullptr);
	return 0;
}