#include<iostream>
using namespace std;


int main()
{
	int num = 10;
	int data = 0;
	int* arr = (int*)malloc(sizeof(int)*10);
	memset(arr, 0, sizeof(int)*10);
	int brr[10] = { 1,2,2,4,4,4,4,4,4,5 };
	for (int i = 0; i < num; i++)
	{
		++arr[brr[i]];
		if (arr[brr[i]] > (num / 2))
			data = brr[i];
	}
	return 0;
}