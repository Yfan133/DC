#include"common.h"
//稳定排序：两个相同的数，排序后位置不变
//外部排序：一部分先放在外存，一部分一部分排序
//内部排序：直接在内存中排序
//排序分类：1)按手段：插入,交换,选择,归并,计数
//			2)按时间：简单排序 o(n^2),先进排序 o(log),基数排序 o()
//直接插入排序
void InsertSort(int* arr, int left, int right)
{
	assert(arr != NULL);
	for (int i = left + 1; i < right; ++i)
	{
		int target = i;
		while (target > left && arr[target - 1] > arr[target])
		{

		}
	}
}