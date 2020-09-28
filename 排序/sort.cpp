//#include"sort.h"
#include"common.h"
int _quick(int* ar, int left, int right)
{
    int key = ar[left];
    while (left < right)
    {
        while (left<right && ar[right]>=key)
            right--;
        ar[left] = ar[right];
        while (left < right && ar[left] < key)
            left++;
        ar[right] = ar[left];
    }
    ar[left] = key;
    return left;
}
void QuickSort(int* ar, int left, int right)
{
    if (left >= right-1)
        return;
    int pos = _quick(ar, left, right - 1);
    QuickSort(ar, left, pos);
    QuickSort(ar, pos + 1, right);
}
int* sortArray(int* nums, int numsSize, int* returnSize)
{
    QuickSort(nums, 0, numsSize);
    returnSize = (int*)malloc(sizeof(int) * numsSize);
    memcpy(returnSize, nums, sizeof(int) * numsSize);
    return returnSize;
}
int main()
{
    int arr[]= { 49,38,65,97,76,13,27,49 };
    int length = sizeof(arr) / sizeof(arr[1]);
    int* br = (int*)malloc(sizeof(int) * length);
    sortArray(arr, length, br);
   
	//int arr[] = { 49,38,65,97,76,13,27,49 };
	////int arr[] = { 86,36,47,61,46,63,71,62,74,24 };
	//int length = sizeof(arr) / sizeof(arr[1]);
	//TestSort(arr, 0, length);
	//PrintList(arr, 0, length);
	////TestSortEfficiency();
	return 0;
}