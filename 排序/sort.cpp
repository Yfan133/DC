#include"sort.h"
int main()
{
	int arr[] = { 3,-1 };
	//int arr[] = { 86,36,47,61,46,63,71,62,74,24 };
	int length = sizeof(arr) / sizeof(arr[1]);
	TestSort(arr, 0, length);
	PrintList(arr, 0, length);
	//TestSortEfficiency();
	return 0;
}