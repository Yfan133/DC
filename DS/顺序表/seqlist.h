#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define SEQLIST_C_SIZE 8

typedef struct SeqList
{
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;

void SeqListInit(SeqList* plist);//初始化
void SeqListDestory(SeqList* plist);//清除
void SeqListPushBack(SeqList* plist, ElemType x);//头插
void SeqListPushFront(SeqList* plist, ElemType x);//尾插
void SeqListPrint(SeqList* plist);//打印
void SeqListPopBack(SeqList* plist);//尾删
bool SeqListInsertByPos(SeqList* plist, int pos, ElemType x);//按位插
int  SeqListFind(SeqList* ps, ElemType x);//查找
void SeqListPopFront(SeqList* plist);//头删
void SeqListEraseByPos(SeqList* plist, int pos);//查位删

void SeqListClear(SeqList* plist);//清空
void SeqListSort(SeqList* plist);//排序
bool SeqListInsertByVal(SeqList* plist, ElemType x);//按数插
void SeqListEraseByVal(SeqList* plist, ElemType key);//查数删
void SeqListReverse(SeqList* plist);//反转

size_t SeqListLength(SeqList* plist);
size_t SeqListCapacity(SeqList* plist);

bool _Inc(SeqList* plist, size_t new_capacity)//扩容
{
#if 0
	assert(plist != NULL && new_capacity > plist->capacity);
	ElemType* new_base = (ElemType*)realloc(plist->base, sizeof(ElemType) * new_capacity); //realloc
	if (new_base == NULL)
		return false;
	free(plist->base);
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
#endif
	assert(plist != NULL && new_capacity > plist->capacity);
	ElemType* new_base = (ElemType*)malloc(sizeof(ElemType) * new_capacity);
	if (new_base == NULL)
		return false;
	memcpy(new_base, plist->base, sizeof(ElemType) * plist->capacity);
	free(plist->base);
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}
bool IsFull(SeqList* plist)
{
	assert(plist != NULL);
	return plist->size == plist->capacity;
}
bool IsEmpty(SeqList* plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}
void SeqListInit(SeqList* plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_C_SIZE;
	plist->size = 0;
	plist->base = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);
}
void SeqListDestory(SeqList* plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}
void SeqListPrint(SeqList* plist)
{
	assert(plist != NULL);
	size_t i = 0;
	for (; i<plist->size; ++i) {
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)) {
		printf("顺序表已满无法尾插.\n");
		return;
	}
	plist->base[plist->size++] = x;
}
void SeqListPushFront(SeqList* plist,ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)) {
		printf("顺序表已满无法头插.\n");
		return;
	}
	for (size_t i = plist->size; i > 0; --i) {
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}
void SeqListPopBack(SeqList* plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表为空无法尾删.\n");
		return;
	}
	plist->size--;
}
void SeqListPopFront(SeqList* plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表为空无法头删.\n");
		return;
	}
	for (size_t i=0; i < plist->size - 1; ++i) {
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
int SeqListFind(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	for (int i = 0; i < plist->size; ++i) {
		if (plist->base[i] == x)
			return i;
	}
	return -1;
}
bool SeqListInsertByPos(SeqList* plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)) {
		printf("顺序表已满,%d 不能在 %d 位置插入.\n", x, pos);
		return false;
	}
	if (pos > plist->size || pos < 0) {
		printf("要插入的位置[%d]是非法位置, %d 不能插入.\n", pos, x);
		return false;
	}
	size_t i = pos;
	while (i < plist->size) {
		plist->base[i + 1] = plist->base[i];
		++i;
	}
	plist->base[pos] = x;
	plist->size++;
	return true;
}
void SeqListClear(SeqList* plist)
{
	assert(plist != NULL);
	plist->size = 0;
}
void SeqListReverse(SeqList* plist)
{
	assert(plist != NULL);
	if (plist->size == 1)
		return;
	ElemType left = 0, right = plist->size - 1;
	while (left < right) {
		Swap(&plist->base[left], &plist->base[right]);
		++left;
		++right;
	}
}
void SeqListSort(SeqList* plist)
{
	assert(plist != NULL);
	size_t i = 0, j = 0;
	for (i = 0; i < plist->size-1; ++i) {
		for (j = 0; j < plist->size-i-1; j++) {
			if (plist->base[j] > plist->base[j + 1])
				Swap(&plist->base[j], &plist->base[j + 1]);
		}
	}
}
size_t SeqListLength(SeqList* plist)
{
	assert(plist != NULL);
	return plist->size;
}
size_t SeqListCapacity(SeqList* plist)
{
	assert(plist != NULL);
	return plist->capacity;
}
bool SeqListInsertByVal(SeqList* plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满,%d 不能插入.\n", x);
		return false;
	}
	size_t pos = plist->size - 1;
	while (pos >= 0 && x < plist->base[pos]) {
		plist->base[pos + 1] = plist->base[pos];
		pos--;
	}
	plist->base[pos + 1] = x;
	plist->size++;
	return true;
}
void SeqListEraseByPos(SeqList* plist, int pos)
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表为空无法在%d的位置删除.\n",pos);
		return;
	}
	if (pos < 0 || pos >= plist->size) {
		printf("该位置非法无法删除.\n");
		return;
	}
	size_t i = pos;
	while (i < plist->size) {
		plist->base[i] = plist->base[i + 1];
		++i;
	}
	plist->size--;
}
void SeqListEraseByVal(SeqList* plist, ElemType key)
{
	assert(plist != NULL);
	int pos = SeqListFind(plist, key);
	if (pos == -1)
		return;
	SeqListEraseByPos(plist, pos);
}
#endif "_SEQLIST_H_"// !_SEQLIST_H_