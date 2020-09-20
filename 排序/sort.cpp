#include"sort.h"
int main()
{
	int arr[] = { 49,38,65,97,76,13,27,49 };
	InsertSort(arr, 0, 8);
	printf("%d", *(arr+1));
	return 0;
}