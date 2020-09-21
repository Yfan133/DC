#include"sort.h"
int main()
{
	int arr[] = { 49,38,65,97,76,13,27,49 };
	int length = sizeof(arr) / sizeof(arr[1]);
	//TestSort(arr, 0, length);
	//PrintList(arr, length);
	TestSortEfficiency(arr, 0, length);
	return 0;
}