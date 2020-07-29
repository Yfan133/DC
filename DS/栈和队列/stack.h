#ifndef _STACK_H_
#define _STACK_H_

#include"main.h"
#define STACK_DEFAULT_SIZE 8
typedef struct SeqStack
{
	ElemType* base;//栈空间
	ElemType capacity;
	ElemType top;
}SeqStack;

void SeqStackInit(SeqStack* pst);
void SeqStackPush(SeqStack* pst, ElemType x);
void SeqStackPop(SeqStack* pst);
//ElemType SeqStackTop(SeqStack* pst); //取栈顶元素
void SeqStackTop(SeqStack* pst, ElemType* top_val);
void SeqStackShow(SeqStack* pst);
void SeqStackDestroy(SeqStack* pst);
int  SeqStackSize(SeqStack* pst);

bool _inc(SeqStack* pst, ElemType new_capacity)
{
	assert(pst != NULL && new_capacity > pst->capacity);
	ElemType* new_base = (ElemType*)realloc(pst->base, sizeof(ElemType) * new_capacity);
	if (new_base == NULL)
		return false;
	pst->base = new_base;
	pst->capacity = new_capacity;
	return true;
}
bool SeqStackIsFull(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool SeqStackIsEmpty(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}
void SeqStackInit(SeqStack* pst)
{
	assert(pst != NULL);
	pst->capacity = STACK_DEFAULT_SIZE;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	pst->top = 0;
}
void SeqStackPush(SeqStack* pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst) && !_inc(pst, pst->capacity * 2))
	{
		printf("顺序栈已满无法将%d插入\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}
void SeqStackPop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst)) {
		printf("顺序栈已空无法删除\n");
		return;
	}
	pst->top--;
}
void SeqStackTop(SeqStack* pst, ElemType* top_val)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst)) {
		printf("顺序栈已空无法取顶元素\n");
		return;
	}
	*top_val = pst->base[pst->top-1];
}
void SeqStackShow(SeqStack* pst)
{
	assert(pst != NULL);
	int i = pst->top-1;
	for (i; i >= 0; i--) {
		printf("| %d |\n", pst->base[i]);
	}
	printf(" -- \n");
}
void SeqStackDestroy(SeqStack* pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}
int  SeqStackSize(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top;
}
#endif