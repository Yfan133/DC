//双向链表始终不更改头指针内容，所以有的函数不需要传地址
#ifndef _DCIST_H_
#define _DCIST_H_

#include "main.h"
typedef struct DCListNode	//双循环链表
{
	ElemType data;
	struct DCListNode* next;
	struct DCListNode* prev;
}DCListNode;
typedef DCListNode* DCList;


void DCListPushBack(DCList* phead, ElemType x);
void DCListPushFront(DCList* phead, ElemType x);
void DCListShow(DCList phead);
void DCListPopBack(DCList* phead);
void DCListPopFront(DCList* phead);
void DCListSort(DCList phead);
void DCListRverse(DCList phead);
void DCListClear(DCList* phead);
void DCListDestroy(DCList* phead);
void DCListInit(DCList* phead);
///////////////////////////////////////////
DCListNode* _BuyNode(ElemType v)
{
	DCListNode* _S = (DCListNode*)malloc(sizeof(DCListNode));
	assert(_S != NULL);
	_S->data = v;
	_S->next = _S->prev = _S;
	return _S;
}
void DCListInit(DCList *phead)
{
	*phead=_BuyNode(NULL);
}
void DCListPushBack(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *S = _BuyNode(x);
	DCListNode* head = *phead;

	S->prev = head->prev;
	S->next = head;
	S->prev->next = S;
	head->prev = S;
}
void DCListPushFront(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode* S = _BuyNode(x);
	DCListNode* head = *phead;
	S->prev = head;
	S->next = head->next;
	head->next = S;
	S->next->prev = S;
}
void DCListShow(DCList phead)
{
	assert(phead != NULL);
	DCListNode* p = phead->next;
	while (p != phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("OVER!\n");
}
void DCListPopBack(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* p = (*phead)->prev;
	DCListNode* head = *phead;
	if (head->next == head)
	{
		printf("链表为空无法尾删....\n");
		return;
	}
	p->prev->next = head;
	head->prev = p->prev;
	free(p);
}
void DCListPopFront(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* head = *phead;
	DCListNode* p = (*phead)->next;
	if (head->next == head)
	{
		printf("链表为空无法头删....\n");
		return;
	}
	p->next->prev = head;
	head->next = p->next;
}
void DCListSort(DCList phead)
{
	assert(phead != NULL);
	DCListNode* p = phead->next;
	DCListNode* q = p->next;
	DCListNode* tmp = phead->next;
	if (p == phead || q == phead) {
		return;
	}
	p->next = phead;
	phead->prev = p;
	while (q != phead)
	{
		p = q;
		q = q->next;
		while (p->data > tmp->data && tmp != phead) {
			tmp = tmp->next;
		}
		p->next = tmp;
		p->prev = tmp->prev;
		tmp->prev = p;
		p->prev->next = p;
		tmp = phead->next;
	}
}
void DCListRverse(DCList phead)
{
	assert(phead != NULL);
	DCListNode* p = phead->next;
	DCListNode* q = p->next;
	if (p == phead || q == phead)
		return;
	p->next = phead;
	phead->prev = p;
	p = q;
	q = q->next;
	while (p != phead)
	{
		p->prev = phead;
		p->next = phead->next;
		phead->next = p;
		p->next->prev = p;
		p = q;
		q = q->next;
	}
}
void DCListClear(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* head = *phead;
	DCListNode* p = (*phead)->next;
	while (p != head) 
	{
		p->next->prev = head;
		head->next = p->next;
		free(p);
		p = head->next;
	}
}
void DCListDestroy(DCList* phead)
{
	assert(phead!=NULL);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;
}
DCListNode* DCListFind(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode* p = phead->next;
	while (p->data != key && p != phead) {
		p = p->next;
	}
	if (p == phead)
		return NULL;
	return p;
}
void DCListEraseByVal(DCList *phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode* p = DCListFind(*phead, key);
	if (p == NULL)
		return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}
void DCListInsertByVal(DCList* phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode* p = *phead;
	while (p != NULL && p->data > key)
	{

	}
}
#endif
