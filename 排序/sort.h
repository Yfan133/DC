#include"common.h"
//�ȶ�����������ͬ�����������λ�ò���
//�ⲿ����һ�����ȷ�����棬һ����һ��������
//�ڲ�����ֱ�����ڴ�������
//������ࣺ1)���ֶΣ�����,����,ѡ��,�鲢,����
//			2)��ʱ�䣺������ o(n^2),�Ƚ����� o(log),�������� o()
void PrintList(int* ar,int length)
{
	while (length-- > 0)
	{
		printf("%d ", *ar);
		ar++;
	}
	printf("\n");
}
//ֱ�Ӳ�������(�����˿���)
void InsertSort(int* ar, int left, int right)
{
	assert(ar != NULL);
	for (int i = left + 1; i < right; ++i)
	{
		int target = i;
		while (target > left && ar[target - 1] > ar[target])
		{
			Swap(&ar[target - 1], &ar[target]);
			--target;
		}
	}
}
void InsertSort_1(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int tmp = ar[i];
		int target = i;
		while (target > left && ar[target - 1] > tmp)
		{
			ar[target] = ar[target - 1];
			--target;
		}
		ar[target] = tmp;
	}
}
//�۰뷨ֱ�Ӳ�������
void BinInsertSort(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int tmp = ar[i];
		int target = i;
		int low = 0;
		int high = i - 1;
		while(low <= high)
		{
			int mid = (low + high) / 2;
			if (ar[mid] > tmp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		while (target > low)
		{
			ar[target] = ar[target - 1];
			--target;
		}
		ar[low] = tmp;
	}
}
void TestSort(int* ar, int left, int right)
{
	//InsertSort(ar, left, right);
	InsertSort_1(ar, left, right);
	//BinInsertSort(ar, left, right);
}
void TestSortEfficiency(int* ar, int left, int right)
{
	int n = 1000;
	int* a = (int*)malloc(sizeof(int) * n);
	int* a1 = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
	}
	time_t start = clock();
	InsertSort(ar, 0, n);
	time_t end = clock();
	printf("InsertSort: %u\n", end - start);

	start = clock();
	InsertSort_1(ar, 0, n);
	end = clock();
	printf("InsertSort_1: %u\n", end - start);

	start = clock();
	BinInsertSort(ar, 0, n);
	end = clock();
	printf("BinInsertSort_2: %u\n", end - start);
}

