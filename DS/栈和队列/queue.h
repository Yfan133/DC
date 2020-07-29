#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"main.h"

#define QUEUE_DEFAULT_SIZE 8
#define QDataType int

typedef struct QListNode
{
	QDataType _data;
	struct QListNode* _next;
}QNode;

typedef struct Queue 
{ 
	QNode* _front; 
	QNode* _rear; 
}Queue;

void QueueShow(Queue* q);
void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);

//////////////////////////////////////////////////////////////////////
void QueueInit(Queue* q)
{
	assert(q != NULL);
	q->_front = q->_rear = NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q != NULL);
	QNode* p = (QNode*)malloc(sizeof(QNode));
	assert(p != NULL);
	p->_data = data;
	p->_next = NULL;
	if (q->_front == NULL)
		q->_front = q->_rear = p;
	else
	{
		q->_rear->_next = p;
		q->_rear = p;
	}
}
void QueueShow(Queue* q)
{
	assert(q != NULL);
	QNode* p = q->_front;
	while (p != NULL)
	{
		printf("%d  ", p->_data);
		p = p->_next;
	}
	printf("\n");
}
void QueuePop(Queue* q)
{
	assert(q != NULL);
	if (QueueEmpty(q))
	{
		printf("链式队列为空无法删除...\n");
		return;
	}
	QNode* p = q->_front;
	if (q->_front == q->_rear)
		q->_front = q->_rear = NULL;
	else
		q->_front = p->_next;
	free(p);
}
QDataType QueueFront(Queue* q)
{
	assert(q != NULL);
	assert(q->_front != NULL);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q != NULL);
	assert(q->_front != NULL);
	return q->_rear->_data;
}
int QueueSize(Queue* q)
{
	assert(q != NULL);
	assert(q->_front != NULL);
	QDataType size = 0;
	QNode* p = q->_front;
	while (p != NULL)
	{
		size++;
		p = p->_next;
	}
	return size;
}
int QueueEmpty(Queue* q)
{
	assert(q != NULL);
	return q->_front == NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q != NULL);
	QNode* p = q->_front;
	while (p != NULL)
	{
		q->_front = p->_next;
		free(p);
		p = q->_front;
	}
	q = NULL;
}








//typedef struct SeqQueue
//{
//	ElemType* base;
//	ElemType capacity;
//	ElemType front;
//	ElemType rear;
//}SeqQueue;
//
//void SeqQueueInit(SeqQueue* psq);
//void SeqQueueEn(SeqQueue* psq, ElemType x);
//void SeqQueueDe(SeqQueue* psq);
//ElemType SeqQueueFront(SeqQueue* psq);
//int SeqQueueSize(SeqQueue* psq);
//bool SeqQueueEmpty(SeqQueue* psq);
//void SeqQueueShow(SeqQueue* psq);
//void SeqQueueDestroy(SeqQueue* psq);
//
//void SeqQueueInit(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	psq->capacity = QUEUE_DEFAULT_SIZE;
//	psq->base = (ElemType*)malloc(sizeof(ElemType) * psq->capacity);
//	psq->front = psq->rear = 0;
//}
//void SeqQueueEn(SeqQueue* psq, ElemType x)
//{
//	assert(psq != NULL);
//	if (psq->rear == psq->capacity) {
//		printf("顺序队列已满无法将%d插入\n", x);
//		return;
//	}
//	psq->base[psq->rear++] = x;
//}
//void SeqQueueDe(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	if (SeqQueueEmpty(psq)) {
//		printf("顺序队列为空无法删除\n");
//		return;
//	}
//	psq->front++;
//}
//ElemType SeqQueueFront(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	assert(psq->front!=psq->rear);
//	return psq->base[psq->front];
//}
//int SeqQueueSize(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	assert(psq->front != psq->rear);
//	return psq->rear - psq->front;
//}
//bool SeqQueueEmpty(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	return psq->front == psq->rear;
//}
//void SeqQueueShow(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	int i = psq->front;
//	for (i; i < psq->rear; i++) {
//		printf("%d  ", psq->base[i]);
//	}
//	printf("\n");
//}
//void SeqQueueDestroy(SeqQueue* psq)
//{
//	assert(psq != NULL);
//	free(psq->base);
//	psq->capacity = psq->front = psq->rear = 0;
//}
#endif

