//#include"stack.h"
#include"queue.h"
void main()
{
	/*SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);
	SeqStackPush(&st, 9);
	SeqStackShow(&st);
	int top_val;
	while (!SeqStackIsEmpty(&st))
	{
		SeqStackTop(&st, &top_val);
		SeqStackPop(&st);
		printf("%d ³öÕ».\n", top_val);
	}
	SeqStackDestroy(&st);*/
	/*SeqQueue sq;
	SeqQueueInit(&sq);
	SeqQueueEn(&sq, 1);
	SeqQueueEn(&sq, 2);
	SeqQueueEn(&sq, 3);
	SeqQueueEn(&sq, 4);
	SeqQueueEn(&sq, 5);
	SeqQueueEn(&sq, 6);
	SeqQueueEn(&sq, 7);
	SeqQueueEn(&sq, 8);
	SeqQueueEn(&sq, 9);
	SeqQueueShow(&sq);
	SeqQueueDe(&sq);
	SeqQueueShow(&sq);
	printf("front = %d\n", SeqQueueFront(&sq));
	SeqQueueEn(&sq, 9);*/
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueueShow(&Q);

	/*int front_val;
	while (!QueueEmpty(&Q))
	{
		front_val = QueueFront(&Q);
		QueuePop(&Q);
		printf("%d ³ö¶Ó.\n", front_val);
	}*/
	QueueDestroy(&Q);
	QueuePush(&Q, 4);
	QueueShow(&Q);
}