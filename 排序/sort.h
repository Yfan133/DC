#include"common.h"
//�ȶ�����������ͬ�����������λ�ò���
//�ⲿ����һ�����ȷ�����棬һ����һ��������
//�ڲ�����ֱ�����ڴ�������
//������ࣺ1)���ֶΣ�����,����,ѡ��,�鲢,����
//			2)��ʱ�䣺������ o(n^2),�Ƚ����� o(log),�������� o()
//ֱ�Ӳ�������
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