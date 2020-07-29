#ifndef _SLIST_H_
#define _SLIST_H_

#include "main.h"
typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

typedef SListNode* SList;
void SListPushBack(SList* phead, ElemType x);
void SListPushFront(SList* phead, ElemType x);
void SListShow(SList phead);
void SListPopBack(SList* phead);
void SListPopFront(SList* phead);
void SListSort(SList* phead);
void SListRverse(SList* phead);

void SListInit(SList* phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
void SListPushBack(SList *phead,ElemType x)
{
	assert(phead != NULL);
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	SListNode* p = *phead;
	if (p == NULL)		//插入节点为第一个节点时
		*phead = s;
	else
	{
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = s;
	}
}
void SListPushFront(SList* phead, ElemType x)
{
	assert(phead != NULL);
}
void SListShow(SList phead)
{
	assert(phead != NULL);
	SListNode* p = phead;
	while (p != NULL) {
		printf("%d->", p ->data);
		p = p->next;
	}
	printf("OVER!\n");
}
void SListPopBack(SList* phead)
{
	assert(phead != NULL);
}
void SListPopFront(SList* phead)
{
	assert(phead != NULL);
}
void SListSort(SList* phead) 
{
	assert(phead != NULL);
	SListNode* p = *phead;
	SListNode* q = p->next;
	SListNode* prev = NULL;
	SListNode* tmp = *phead;
	if (q == NULL) {
		return;
	}
	p->next = NULL;
	while (q != NULL) {
		p = q;
		q = q->next;
		while (tmp != NULL && p->data > tmp->data) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL) {
			p->next = tmp;
			tmp = *phead = p;
		}
		else {
			p->next = tmp;
			prev->next = p;
		}
		prev = NULL;
		tmp = *phead;
	}
}
void SListRverse(SList* phead)
{
	assert(phead != NULL);
	SListNode* p=*phead;
	SListNode* q = p->next;
	if (q == NULL) {
		return;
	}
	p->next = NULL;
	while (q != NULL) {
		p = q->next;
		q->next = *phead;
		*phead = q;
		q = p;
	}
	printf("反转数据成功...\n");
}
#endif "_SLIST_H_"// !_SLIST_H_
