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
////////////////////////////////////////////////////////////////////////
void PrintArray(int ar[], int left, int right)
{
	for (int i = left; i < right; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}

//ֱ�Ӳ�������
void InsertSort(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int end = i;
		while (end > left && ar[end] < ar[end - 1])
		{
			Swap(&ar[end], &ar[end - 1]);
			end--;
		}
	}
}

void InsertSort_1(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int tmp = ar[i];
		int end = i;
		while (end > left && tmp < ar[end - 1])
		{
			ar[end] = ar[end - 1];
			end--;
		}
		ar[end] = tmp;
	}
}

//�ڱ�λ��ֱ�Ӳ�������
void InsertSort_2(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		ar[0] = ar[i]; // �ڱ�λ
		int end = i;
		while (ar[0] < ar[end - 1])
		{
			ar[end] = ar[end - 1];
			end--;
		}
		ar[end] = ar[0];
	}
}

//�۰��������
void BinInsertSort(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		int tmp = ar[i];
		int low = left;
		int high = i - 1;
		while (low <= high)
		{
			int m = (low + high) / 2;
			if (tmp < ar[m])
				high = m - 1;
			else
				low = m + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			ar[j + 1] = ar[j];
		ar[high + 1] = tmp;
	}
}

//��·��������
void TwoWayInsertSort(int* ar, int left, int right)
{
	int n = right - left;
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp != NULL);

	tmp[0] = ar[left];
	int first = 0, finish = 0;

	for (int i = left + 1; i < right; ++i)
	{
		if (ar[i] < tmp[first])
		{
			first = (first - 1 + n) % n;
			tmp[first] = ar[i];
		}
		else if (ar[i] > tmp[finish])
		{
			tmp[++finish] = ar[i];
		}
		else
		{
			int end = finish;
			while (ar[i] < tmp[end])
			{
				tmp[(end + 1) % n] = tmp[end];
				end = (end - 1 + n) % n;
			}
			tmp[(end + 1) % n] = ar[i];
			finish++;
		}
	}

	int k = 0;
	for (int i = first; k < n; ++k)
	{
		ar[k] = tmp[i];
		i = (i + 1) % n;
	}

	free(tmp);
	tmp = NULL;
}

//Shell����
/*
void ShellInsert(int *ar, int n, int dk)
{
	for(int i=dk; i<n; ++i)
	{
		if(ar[i] < ar[i-dk])
		{
			int tmp = ar[i];
			int j;
			for(j=i-dk; j>=0 && tmp<ar[j]; j-=dk)
			{
				ar[j+dk] = ar[j];
			}
			ar[j+dk] = tmp;
		}
	}
}
int dlta[] = {5,3,2,1};
void ShellSort(int *ar, int n, int dlta[], int t)
{
	for(int k=0; k<t; ++k)
		ShellInsert(ar, n, dlta[k]);
}
void ShellInsert(int *ar, int left, int right, int dk)
{
	for(int i=left+dk; i<right; ++i)
	{
		if(ar[i] < ar[i-dk])
		{
			int tmp = ar[i];
			int end = i-dk;
			while(end>=left && tmp<ar[end])
			{
				ar[end+dk] = ar[end];
				end -= dk;
			}
			ar[end+dk] = tmp;
		}
	}
}
int dlta[] = {5,3,2,1};  //����ĵ�
void ShellSort(int *ar, int left, int right)
{
	int t = sizeof(dlta) / sizeof(dlta[0]);
	for(int k=0; k<t; ++k)
		ShellInsert(ar, left, right, dlta[k]);
}
*/

void ShellSort(int* ar, int left, int right) //10
{
	int dk = right - left;
	while (dk > 1)
	{
		dk = dk / 3 + 1; //6667  2223  742  248  83  27 10 4 2 1
		for (int i = left + dk; i < right; ++i)
		{
			if (ar[i] < ar[i - dk])
			{
				int tmp = ar[i];
				int end = i - dk;
				while (end >= left && tmp < ar[end])
				{
					ar[end + dk] = ar[end];
					end -= dk;
				}
				ar[end + dk] = tmp;
			}
		}
	}
}

//ֱ��ѡ������
int GetMinIndex(int* ar, int left, int right)
{
	int min_val = ar[left];
	int index = left;

	for (int i = left + 1; i < right; ++i)
	{
		if (ar[i] < min_val)
		{
			min_val = ar[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int* ar, int left, int right)
{
	for (int i = left; i < right - 1; ++i)
	{
		int index = GetMinIndex(ar, i, right);
		if (index != i)
			Swap(&ar[index], &ar[i]);
	}
}

//������
void _ShiftDown(int* ar, int left, int right, int curpos)
{
	int i = curpos;
	int j = 2 * i + 1 + left;

	int n = right - left;
	while (j < n)
	{
		if (j + 1 < n && ar[j] < ar[j + 1])
			j++;
		if (ar[i] < ar[j])
		{
			Swap(&ar[i], &ar[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void HeapSort(int* ar, int left, int right)
{
	//�������
	int n = right - left;
	int cur = n / 2 - 1 + left;
	while (cur >= 0)
	{
		_ShiftDown(ar, left, right, cur);
		cur--;
	}

	//����
	int end = right - 1;
	while (end > left)
	{
		Swap(&ar[left], &ar[end]);
		end--;
		_ShiftDown(ar, left, end, left);
	}
}

void _ShiftDown_1(int* ar, int left, int right, int curpos)
{
	int i = curpos;
	int j = 2 * i + 1 + left;

	int n = right - left;
	int tmp = ar[i];
	while (j < n)
	{
		if (j + 1 < n && ar[j] < ar[j + 1])
			j++;

		if (tmp < ar[j])
		{
			ar[i] = ar[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}

	ar[i] = tmp;
}
void HeapSort_1(int* ar, int left, int right)
{
	//�������
	int n = right - left;
	int cur = n / 2 - 1 + left;
	while (cur >= 0)
	{
		_ShiftDown_1(ar, left, right, cur);
		cur--;
	}

	//����
	int end = right - 1;
	while (end > left)
	{
		Swap(&ar[left], &ar[end]);
		end--;
		_ShiftDown_1(ar, left, end, left);
	}
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
			{
				Swap(&ar[j], &ar[j + 1]);
			}
		}
	}
}
//ð������ĸĽ�����
void BubbleSort_1(int* ar, int left, int right)
{
	int n = right - left;
	bool is_swap = false; //���ڱ�־���������Ƿ��н������������˵����������δ������
						  //��û����˵�������Ѿ�����ֱ���˳�
	for (int i = left; i < n - 1; ++i)
	{
		for (int j = left; j < n - i - 1; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
				is_swap = true;
			}
		}
		if (!is_swap)
			break;
		else
			is_swap = false;
	}
}