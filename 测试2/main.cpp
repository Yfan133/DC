#include<iostream>
#include<assert.h>
using namespace std;
#pragma warning (disable:4996)
//为什么这里要传二级指针，而队列传的一级指针
typedef struct StackNode
{
    int data;
    struct StackNode* next;
}StackNode, * Stack;
void StackInit(Stack* st)
{
    assert(st != NULL);
    *st = NULL;
}
void StackPush(Stack* st, int data)
{
    assert(st != NULL);
    StackNode* s = (StackNode*)malloc(sizeof(StackNode));
    s->data = data;
    s->next = *st;
    *st = s;
}
int StackTop(Stack* st)
{
    assert(st != NULL);
    return (*st)->data;
}
void StackPop(Stack* st)
{
    assert(st != NULL);
    StackNode* s = *st;
    (*st) = (*st)->next;
    free(s);
    s = NULL;
}
bool IsEmpty(Stack* st)
{
    assert(st != NULL);
    return (*st) == NULL;
}
typedef struct SQNode
{
    StackNode* s1;
    StackNode* s2;
}SQNode;
void SQInit(SQNode* pq)
{
    assert(pq != NULL);
    StackInit(&(pq->s1));
    StackInit(&(pq->s2));
}
void SQPush(SQNode* pq,int val)
{
    assert(pq != NULL);
    StackPush(&(pq->s1), val);
}
int SQPop(SQNode* pq)
{
    assert(pq != NULL);
    int val = -1;
    if (pq->s2 != NULL) {
        val = StackTop(&(pq->s2));
        StackPop(&(pq->s2));
        return val;
    }
    while (pq->s1 != NULL) {
        val = StackTop(&(pq->s1));
        StackPop(&(pq->s1));
        StackPush(&(pq->s2), val);
    }
    if (pq->s2 != NULL) 
        StackPop(&(pq->s2));
    return val;
}
SQNode* SQcreat()
{
    SQNode* p = (SQNode*)malloc(sizeof(SQNode));
    SQInit(p);
    return p;
}


class A
{
public:
    A()
    {
        _count++;
        _sum += _count;
    }
    static void Reset()
    {
        _count = 0;
        _sum = 0;
    }
    static int GetSum()
    {
        return _sum;
    }
    static int _count;
    static int _sum;
};
int A::_count = 0;
int A::_sum = 0;
int Sum_Solution1(int n)
{
    int sum = n;
    n && (sum += Sum_Solution1(n - 1));
    return sum;
}
int Sum_Solution(int n)
{
    A a;
    n > 1 && Sum_Solution(n - 1);
    return a._sum;
}
void Move(int* A, int* B, int* ASize, int* BSize)
{
    B[*BSize] = A[*ASize - 1];
    (*ASize)--;
    (*BSize)++;
}
void Han(int n, int* A, int* B, int* C, int* ASize, int* BSize, int* CSize)
{
    if (n == 1)
        Move(A, C, ASize, CSize);
    else 
    {
        Han(n - 1, A, C, B, ASize, CSize, BSize);
        Move(A, C, ASize, CSize);
        Han(n - 1, B, A, C, BSize, ASize, CSize);
    }
}
void hanota(int* A, int ASize, int* B, int BSize, int* C, int CSize)
{
    Han(ASize, A, B, C, &ASize, &BSize, &CSize);
}
int main()
{
    int* A = new int[3]{ 2,1,0 };
    int* B = new int[3];
    int* C = new int[3];
    int Asize = 3;
    int Bsize = 0;
    int Csize = 0;
    hanota(A, Asize, B, Bsize, C, Csize);
    return 0;
}
//int main()
//{
//    SQNode* p = SQcreat();
//    SQPush(p, 1);
//    SQPush(p, 2);
//    SQPop(p);
//    SQPop(p);
//    SQPop(p);
//    return 0;
//}

//#define CapacityInit 2
//typedef struct Stack
//{
//    int* base;
//    int capacity;
//    int top;
//}StackNode;
//void StackInit(StackNode* pst)
//{
//    assert(pst != NULL);
//    pst->capacity = CapacityInit;
//    pst->base = (int*)malloc(sizeof(int) * pst->capacity);
//    pst->top = 0;
//}
//void StackExpand(StackNode* pst)
//{
//    assert(pst != NULL);
//    pst->capacity *= 2;
//    pst->base = (int*)realloc(pst->base, sizeof(int) * pst->capacity);
//    if(pst->base==NULL)
//        return;
//}
//bool IsFull(StackNode* pst)
//{
//    assert(pst != NULL);
//    return pst->capacity == pst->top;
//}
//void StackPush(StackNode* pst,int data)
//{
//    assert(pst != NULL);
//    if (IsFull(pst))
//        StackExpand(pst);
//    pst->base[pst->top++] = data;
//
//}
//int StackTop(StackNode* pst)
//{
//    assert(pst != NULL);
//    return pst->base[pst->top - 1];
//}
//void StackShow(StackNode* pst)
//{
//    assert(pst != NULL);
//    int i = pst->top-1;
//    while (i >= 0)
//    {
//        printf("%d->", pst->base[i--]);
//    }
//    printf("OVER!\n");
//}
//int main()
//{
//    StackNode st;
//    StackInit(&st);
//    StackPush(&st, 1);
//    StackPush(&st, 2);
//    StackPush(&st, 3);
//    StackPush(&st, 4);
//    StackPush(&st, 4);
//    StackShow(&st);
//    printf("%d", StackTop(&st));
//    return 0;
//}
