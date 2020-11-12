#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)
//class A
//{
//public:
//	A(const char* ptr = "")
//	{
//		_str = new char[strlen(ptr) + 1];
//		strcpy(_str, ptr);
//	}
//	void resize(size_t n)
//	{
//		char* tmp = new char[n];
//		strcpy(tmp, _str);
//		delete[] _str;
//		_str = tmp;
//	}
//	~A()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	char* a = new char[5];
//	a[0] = 'q';
//	a[1] = 'w';
//	a[2] = 'e';
//	a[3] = 'r';
//	a[4] = '\0';
//	char* b = (char*)"asdf";
//	char* c=new char[9];
//	strcpy(c, a);
//	strcat(c + 4, b);
//	delete[] a;
//
//	return 0;
//}
int main()
{

	int i = 0;
	int* p = &i;
	p = (char*)p;
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