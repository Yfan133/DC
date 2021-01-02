#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

typedef int ElemType;

void Swap(ElemType& l, ElemType& r)
{
	int tmp = l;
	l = r;
	r = tmp;
}
typedef struct Minheap
{
	ElemType* base_;
	int size_;
	int capacity_;
}Minheap;

void HeapInit(Minheap* php, int sz);
void HeapCreate(Minheap* php, int ar[], int n);
void HeapInsert(Minheap* php, ElemType data);
void HeapErase(Minheap* php);
void HeapShow(Minheap* php);
bool HeapEmpty(Minheap* php);
ElemType HeapTop(Minheap* php);
void HeapSort(Minheap* php, int ar[], int n); 
void HeapShiftUp(Minheap* php, int start);
void HeapShiftDown(Minheap* php, int start, int n);
///////////////////////////////////////////////
void HeapInit(Minheap* php, int sz)
{
	assert(php != nullptr);
	php->base_ = (ElemType*)malloc(sizeof(int) * sz);
	memset(php->base_, 0, sizeof(ElemType) * sz);
	php->capacity_ = sz;
	php->size_ = 0;
}
void HeapCreate(Minheap* php, int ar[], int n)
{
	assert(php != nullptr);
	php->capacity_ = n;
	php->base_ = (ElemType*)malloc(sizeof(int) * php->capacity_);
	assert(php->base_ != nullptr);
	for (int i = 0; i < n; ++i)
		php->base_[i] = ar[i];
	php->size_ = n;
	int curpos = n / 2 - 1;
	while (curpos >= 0)
	{
		HeapShiftDown(php, curpos, n);
		curpos--;
	}
}
void HeapInsert(Minheap* php, ElemType data)
{
	assert(php != nullptr);
	if (php->capacity_ == php->size_)
	{
		printf("堆空间已满\n");
		return;
	}
	php->base_[php->size_] = data;
	HeapShiftUp(php, php->size_);
	php->size_++;
}
//从堆底取一个元素再向下调整
void HeapErase(Minheap* php)
{
	assert(php != nullptr);
	if (php->size_ == php->capacity_)
	{
		printf("堆以空无法删除\n");
		return;
	}
	php->size_--;
	php->base_[0] = php->base_[php->size_];
	HeapShiftDown(php, 0, php->size_);
}
void HeapShow(Minheap* php)
{
	assert(php != nullptr);
	for (int i = 0; i < php->size_; i++)
	{
		printf("%d ", php->base_[i]);
	}
	cout << endl;
}
bool HeapEmpty(Minheap* php)
{
	assert(php != nullptr);
	return php->size_ == 0;
}
ElemType HeapTop(Minheap* php)
{
	assert(php->base_ != nullptr && php->size_ > 0);
	return php->base_[0];
}
//把数组中的数从大到小排序，topK问题
void HeapSort(Minheap* php, int ar[], int n)
{
	//先创建出一个小堆
	HeapCreate(php, ar, n);
	//把堆顶的最小值，放在最后面，然再调整数组
	while (php->size_ > 0)
	{
		php->size_--;
		Swap(php->base_[0], php->base_[php->size_]);
		HeapShiftDown(php, 0, php->size_);
	}
	for (int i = 0; i < n; i++)
		ar[i] = php->base_[i];
}
void HeapShiftUp(Minheap* php, int start)
{
	//j = child, i = parent
	int j = start;
	int i = (j - 1) / 2;
	while (j > 0)
	{
		if (php->base_[j] < php->base_[i])
			Swap(php->base_[j], php->base_[i]);
		else
			break;
		j = i;
		i = (j - 1) / 2;
	}
}
void HeapShiftDown(Minheap* php, int start, int n)
{
	int i = start;
	int j = i * 2 + 1;
	while (j < n)
	{
		if (j + 1 < n && php->base_[j] > php->base_[j + 1])
			j++;
		if (php->base_[i] > php->base_[j])
		{
			Swap(php->base_[i], php->base_[j]);
			i = j;
			j = i * 2 + 1;
		}
		else
			break;
	}
}