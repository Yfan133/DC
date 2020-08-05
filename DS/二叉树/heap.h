#ifndef _HEAP_H_
#define _HEAP_H_

#include"common.h"
#define HEAP_DEFAULT_SIZE 20
typedef int HeapElemType;
typedef struct HeapNode
{
	HeapElemType* base;
	size_t capacity;
	size_t size;
}HeapNode;
////////////////////////////////////////////////////////////////
void HeapInit(HeapNode* php);
void HeapCreate(HeapNode* php, int ar[], int n);
void HeapInsert(HeapNode* php, HeapElemType x);
void HeapErase(HeapNode* php);
void HeapShow(HeapNode* php);
bool HeapEmpty(HeapNode* php);
HeapElemType HeapTop(HeapNode* php);
void HeapSort(HeapNode* php, int ar[], int n);
void HeapShiftUp(HeapNode* php, int start);
void HeapShiftDown(HeapNode* php, int start, int n);
///////////////////////////////////////////////////////////////
void HeapInit(HeapNode* php)
{
	assert(php != NULL);
	php->capacity = HEAP_DEFAULT_SIZE;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType) * HEAP_DEFAULT_SIZE);
	memset(php, 0, sizeof(HeapElemType) * php->capacity);
	php->size = 0;
}
void HeapCreate(HeapNode* php, int ar[], int n)
{
	php->capacity = n;
	php->base = (HeapElemType*)malloc(sizeof(HeapElemType) * php->capacity);
	assert(php->base != NULL);
	for (int i = 0; i < n; ++i)
		php->base[i] = ar[i];
	php->size = n;

	//堆调整
	int curpos = n / 2 - 1; //找到最后一个分支
	while (curpos >= 0)
	{
		HeapShiftDown(php, curpos, n);
		curpos--;
	}
}
void HeapShiftDown(HeapNode* php, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1 < n && php->base[j] > php->base[j + 1]) //寻求左右子树中的最小值
			j++;
		if (php->base[i] > php->base[j])
		{
			Swap(&php->base[i], &php->base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
#endif // !_HEAP_H_

