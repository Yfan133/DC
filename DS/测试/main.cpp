#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s("abcde");
	string s1;
	string s2;
	s1 = s.substr(2, s.size());
	return 0;
}
//void Test(void* t)
//{
//	cout << "void*" << endl;
//}
//void Test(int t)
//{
//	cout << "int" << endl;
//}
//int main()
//{
//	int* p = NULL;
//	int* pt = nullptr;
//	Test(NULL);
//	Test(nullptr);
//	return 0;
//}