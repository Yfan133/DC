#include"common.h"
//�ȶ�����������ͬ�����������λ�ò���
//�ⲿ����һ�����ȷ�����棬һ����һ��������
//�ڲ�����ֱ�����ڴ�������
//������ࣺ1)���ֶΣ�����(O(n^1.3)---O(n^2)),����,ѡ��(O(n^2)),�鲢,����
//			2)��ʱ�䣺������ o(n^2),�Ƚ����� o(log),�������� o()
//�������򲢲��ǵ����Ŀ�������������С��ʱ����ֱ�Ӳ�������Ϻã���һ���ö����򣬸���һЩ�ÿ�������Ϻã��������������ǳ����ʱ��ܸ�Ч��
//��·��������
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
		int pos = i;
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
		while (pos > low)
		{
			ar[pos] = ar[pos - 1];
			--pos;
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
		dk = dk / 3 + 1;			//���д��dk/=3+1;����
		for (int i = left + dk; i < right; ++i)
		{
			int tmp = ar[i];			
			int end = i - dk;
			//int end = i;				//������Ҫ����д��Ч�ʱ����
			while (end >= left && ar[end] > tmp)
			{
				ar[end + dk] = ar[end];
				end -= dk;
			}
			ar[end + dk] = tmp;
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
//////////////////////////////////////////////////////////////////////////////
//��������
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
//��������
//hoare�汾
int _Partition_1(int* ar, int left, int right)
{
	int key = ar[left];
	while (left < right)
	{
		while (left < right && ar[right] >= key)
			right--;
		Swap(&ar[left], &ar[right]);
		while (left < right && ar[left] < key)
			left++;
		Swap(&ar[left], &ar[right]);
	}
	return left;
}
//�ڿӷ�
int _Partition_2(int* ar, int left, int right)
{
	int key = ar[left];
	while (left < right)
	{
		while (left < right && ar[right] >= key)
			right--;
		ar[left] = ar[right];
		while (left < right && ar[left] < key)
			left++;
		ar[right] = ar[left];
	}
	ar[left] = key;
	return left;
}
//ǰ��ָ�뷨
int _Partition_3(int* ar, int left, int right)
{
	int key = ar[left];
	int pos = left;
	for (int i = left + 1; i <= right; ++i)
	{
		if (ar[i] < key)
		{
			++pos;
			if (pos != i)
				Swap(&ar[pos], &ar[i]);
		}
	}
	ar[left] = ar[pos];
	ar[pos] = key;
	return pos;
}
#define MAXNUM 25
void QuickSort(int* ar, int left, int right)
{
	if (right - left <= MAXNUM)
		InsertSort(ar, left, right);
	else
	{
		if (left >= right - 1)
			return;
		int pos = _Partition_3(ar, left, right - 1);
		QuickSort(ar, left, pos);
		QuickSort(ar, pos + 1, right);
	}
}
#include"stack.h"
void QuickSortNoR(int* ar, int left, int right)//���õݹ�ʵ�ֿ�������
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, left);
	SeqStackPush(&st, right);
	while (!SeqStackIsEmpty(&st))
	{
		int end = SeqStackTop(&st);
		SeqStackPop(&st);
		int begin = SeqStackTop(&st);
		SeqStackPop(&st);
		int pos = _Partition_2(ar, begin, end - 1);
		if (begin < pos - 1)
		{
			SeqStackPush(&st, begin);
			SeqStackPush(&st, pos);
		}
		if (end > pos + 1)
		{
			SeqStackPush(&st, pos + 1);
			SeqStackPush(&st, end);
		}
	}
}
//�鲢����(��·�鲢)
void _MergeSort(int* ar, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	//�ȷֽ�
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);
	//�ٲ���
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] <= ar[begin2])
			tmp[i++] = ar[begin1++];
		else
			tmp[i++] = ar[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[i++] = ar[begin2++];
	memcpy(ar + left, tmp, sizeof(int) * (right - left + 1));
}
void MergeSort(int* ar, int left, int right)
{
	int n = right - left;
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp != NULL);
	_MergeSort(ar, left, right - 1, tmp);
	free(tmp);
	tmp = NULL;
}
//��������
#include"slist.h"
#define RADIX 10
SList list[RADIX];	//����3λ����
#define K 3		//���λ3
int GetValue(int value, int k)//��ȡÿһλ��ֵ
{
	int key = 0;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		--k;
	}
	return key;
}
void Contribute(int* ar, int left, int right, int k)//�ַ�
{
	for (int i = left; i <= right; ++i)
	{
		int index = GetValue(ar[i], k);
		SListPushBack(&list[index], ar[i]);
	}
}
void Collect(int* ar)//����
{
	int k = 0;
	for (int i = 0; i < RADIX; ++i)
	{
		while (!IsEmpty(list[i]))
		{
			ar[k++] = list[i]->data;
			SListPopFront(&list[i]);
		}
	}
}
void RadixSort(int* ar, int left, int right)
{
	for (int i = 0; i < RADIX; ++i)
		SListInit(&list[i]);
	for (int i = 0; i < K; ++i)
	{
		//�ַ�
		Contribute(ar, left, right - 1, i);
		
		//����
		Collect(ar);
	}
}
void TestSort(int* ar, int left, int right)
{
	//InsertSort(ar, left, right);
	//InsertSort_1(ar, left, right);
	//BinInsertSort(ar, left, right);
	//SelectSort(ar, left, right);
	//BubbleSort(ar, left, right);
	//BubbleSort_1(ar, left, right);
	ShellInsert(ar, left, right);
	//QuickSort(ar, left, right);
	//MergeSort(ar, left, right);
	//RadixSort(ar, left, right);
	//QuickSortNoR(ar, left, right);
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
	int* a8 = (int*)malloc(sizeof(int) * n);
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
		a8[i] = a[i];
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

	start = clock();
	QuickSort(a7, 0, n);
	end = clock();
	printf("QuickSort: %u\n", end - start);

	start = clock();
	RadixSort(a7, 0, n);
	end = clock();
	printf("RadixSort: %u\n", end - start);
}

