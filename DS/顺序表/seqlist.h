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

void SeqListInit(SeqList* plist);//��ʼ��
void SeqListDestory(SeqList* plist);//���
void SeqListPushBack(SeqList* plist, ElemType x);//ͷ��
void SeqListPushFront(SeqList* plist, ElemType x);//β��
void SeqListPrint(SeqList* plist);//��ӡ
void SeqListPopBack(SeqList* plist);//βɾ
bool SeqListInsertByPos(SeqList* plist, int pos, ElemType x);//��λ��
int  SeqListFind(SeqList* ps, ElemType x);//����
void SeqListPopFront(SeqList* plist);//ͷɾ
void SeqListEraseByPos(SeqList* plist, int pos);//��λɾ

void SeqListClear(SeqList* plist);//���
void SeqListSort(SeqList* plist);//����
bool SeqListInsertByVal(SeqList* plist, ElemType x);//������
void SeqListEraseByVal(SeqList* plist, ElemType key);//����ɾ
void SeqListReverse(SeqList* plist);//��ת

size_t SeqListLength(SeqList* plist);
size_t SeqListCapacity(SeqList* plist);

bool _Inc(SeqList* plist, size_t new_capacity)//����
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
		printf("˳��������޷�β��.\n");
		return;
	}
	plist->base[plist->size++] = x;
}
void SeqListPushFront(SeqList* plist,ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)) {
		printf("˳��������޷�ͷ��.\n");
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
		printf("˳���Ϊ���޷�βɾ.\n");
		return;
	}
	plist->size--;
}
void SeqListPopFront(SeqList* plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("˳���Ϊ���޷�ͷɾ.\n");
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
		printf("˳�������,%d ������ %d λ�ò���.\n", x, pos);
		return false;
	}
	if (pos > plist->size || pos < 0) {
		printf("Ҫ�����λ��[%d]�ǷǷ�λ��, %d ���ܲ���.\n", pos, x);
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
		printf("˳�������,%d ���ܲ���.\n", x);
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
		printf("˳���Ϊ���޷���%d��λ��ɾ��.\n",pos);
		return;
	}
	if (pos < 0 || pos >= plist->size) {
		printf("��λ�÷Ƿ��޷�ɾ��.\n");
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