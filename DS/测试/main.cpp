#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996)
//
//int main()
//{
//	int a;
//	float b, c, d;
//	scanf("%2d%3f%4f", &a, &b, &c);
//	scanf("%f", &d);
//	printf("%d, %f, %f", a, b, c);
//	printf("\n%f", d);
//	return 0;
//}
int& add(int left, int right)
{
	int tmp = left + right;
	return tmp;
}

int main()
{
	//char* p = (char*)malloc(10);
	char p[15];
	strcpy(p, "qwer");
	//int& p = add(1, 2);
	//printf("%d", p);
	return 0;
}