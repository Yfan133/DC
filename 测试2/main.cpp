#include<iostream>
#include<assert.h>
using namespace std;
#pragma warning (disable:4996)
#define CapacityInit 2
typedef struct Stack
{
    int* base;
    int capacity;
    int top;
}StackNode;
void StackInit(StackNode* pst)
{
    assert(pst != NULL);
    pst->capacity = CapacityInit;
    pst->base = (int*)malloc(sizeof(int) * pst->capacity);
    pst->top = 0;
}
void StackExpand(StackNode* pst)
{
    assert(pst != NULL);
    pst->capacity *= 2;
    pst->base = (int*)realloc(pst->base, sizeof(int) * pst->capacity);
    if(pst->base==NULL)
        return;
}
bool IsFull(StackNode* pst)
{
    assert(pst != NULL);
    return pst->capacity == pst->top;
}
void StackPush(StackNode* pst,int data)
{
    assert(pst != NULL);
    if (IsFull(pst))
        StackExpand(pst);
    pst->base[pst->top++] = data;

}
int StackTop(StackNode* pst)
{
    assert(pst != NULL);
    return pst->base[pst->top - 1];
}
void StackShow(StackNode* pst)
{
    assert(pst != NULL);
    int i = pst->top-1;
    while (i >= 0)
    {
        printf("%d->", pst->base[i--]);
    }
    printf("OVER!\n");
}
int main()
{
    StackNode st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPush(&st, 4);
    StackShow(&st);
    printf("%d", StackTop(&st));
    return 0;
}
