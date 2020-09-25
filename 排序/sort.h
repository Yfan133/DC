#include"common.h"
//�ȶ�����������ͬ�����������λ�ò���
//�ⲿ����һ�����ȷ�����棬һ����һ��������
//�ڲ�����ֱ�����ڴ�������
//������ࣺ1)���ֶΣ�����(O(n^1.3)---O(n^2)),����,ѡ��(O(n^2)),�鲢,����
//			2)��ʱ�䣺������ o(n^2),�Ƚ����� o(log),�������� o()
void PrintList(int* ar, int left, int right)
{
	for (int i = left; i < right; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}
//ֱ�Ӳ�������(�����˿���)
void InsertSort(int* ar, int left, int right)
{
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
void InsertSort_2(int* ar, int left, int right)//���ڱ�λ�Ĳ�������
{
	for (int i = left + 1; i < right; ++i)
	{
		ar[0] = ar[i];
		int end = i;
		while (ar[0] < ar[end - 1])
		{
			ar[end] = ar[end - 1];
			--end;
		}
		ar[end] = ar[0];
	}
}
//�۰뷨ֱ�Ӳ����������Ѿ��ź�˳����������۰����λ�ò���
void BinInsertSort(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int tmp = ar[i];
		int target = i;
		int low = left;
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
//��·��������(������ţƤ,��ʵЧ�ʺܵ�)
void TwoWayInsertSort(int* ar, int left, int right)
{

}
//ϣ��shell����(���ȶ�����)����С��������ʹ�������������С�����ݻ�������
void ShellInsert(int* ar, int left, int right)
{
	int dk = right - left;
	while(dk > 1)
	{
		dk = dk / 3 + 1;
		for (int i = left + dk; i < right; ++i)
		{
			if (ar[i] < ar[i - dk])
			{
				int tmp = ar[i];
				int end = i;
				while (end >= left && ar[end - dk] > tmp)
				{
					ar[end] = ar[end - dk];
					end -= dk;
				}
				ar[end] = tmp;
			}
		}
	}
}
//ֱ��ѡ������
void SelectSort(int* ar, int left, int right)
{
	for (int i = left; i < right - 1; ++i)//i<right-1:����Сֵ�ź����,���һ�������ֵ
	{
		int pos = i;
		int min = ar[i];
		for (int j = i + 1; j < right; ++j)
		{
			if (ar[j] < min)
			{
				pos = j;
				min = ar[j];
			}
		}
		if (pos != i)
			Swap(&ar[pos], &ar[i]);
	}
}
//������
void HeapSort(int* ar, int left, int right)
{

}
//ð������
void BubbleSort(int* ar, int left, int right)
{
	int n = right - left;
	for (int i = left; i < n - 1; ++i)
	{
		for (int j = left; j < n - i - 1; ++j)
		{
			if (ar[j] > ar[j + 1])
				Swap(&ar[j], &ar[j + 1]);
		}
	}
}
void BubbleSort_1(int* ar, int left, int right)//ð�ݸĽ�
{
	int n = right - left;
	for (int i = left; i < n - 1; ++i)
	{
		bool quit = true;
		for (int j = left; j < n - i - 1; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
				quit = false;
			}
		}
		if (quit)
			break;
		else
			quit = true;
	}
}
void TestSort(int* ar, int left, int right)
{
	//InsertSort(ar, left, right);
	//InsertSort_1(ar, left, right);
	//BinInsertSort(ar, left, right);
	//SelectSort(ar, left, right);
	//BubbleSort(ar, left, right);
	BubbleSort_1(ar, left, right);
	//ShellInsert(ar, left, right);
}
void TestSortEfficiency()
{
	int n = 30000;
	int* a = (int*)malloc(sizeof(int) * n);
	int* a1 = (int*)malloc(sizeof(int) * n);
	int* a2 = (int*)malloc(sizeof(int) * n);
	int* a3 = (int*)malloc(sizeof(int) * n);
	int* a4 = (int*)malloc(sizeof(int) * n);
	int* a5 = (int*)malloc(sizeof(int) * n);
	int* a6 = (int*)malloc(sizeof(int) * n);
	int* a7 = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
		a6[i] = a[i];
		a7[i] = a[i];
	}
	time_t start = clock();
	InsertSort(a, 0, n);
	time_t end = clock();
	printf("InsertSort: %u\n", end - start);

	start = clock();
	InsertSort_1(a1, 0, n);
	end = clock();
	printf("InsertSort_1: %u\n", end - start);

	start = clock();
	BinInsertSort(a2, 0, n);
	end = clock();
	printf("BinInsertSort: %u\n", end - start);

	start = clock();
	SelectSort(a3, 0, n);
	end = clock();
	printf("SelectSort: %u\n", end - start);

	start = clock();
	BubbleSort(a4, 0, n);
	end = clock();
	printf("BubbleSort: %u\n", end - start);

	start = clock();
	BubbleSort_1(a5, 0, n);
	end = clock();
	printf("BubbleSort_1: %u\n", end - start);

	start = clock();
	ShellInsert(a6, 0, n);
	end = clock();
	printf("ShellInsert: %u\n", end - start);

}

