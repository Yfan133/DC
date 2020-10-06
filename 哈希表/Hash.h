#ifndef _HASH_H_
#define _HASH_H_

#include"common.h"
#define ElemType int
typedef struct HashNode
{
	ElemType data;
	struct HashNode* next;
}HashNode;
#define P 7
typedef HashNode* HashTable[P];

void HashInit(HashTable pht)
{
	for (int i = 0; i < P; ++i)
		pht[i] = NULL;
}
ElemType Hash(ElemType x)
{
	return x % P;
}
void HashInsert(HashTable pht, ElemType x)
{
	int index = Hash(x);
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	assert(node != NULL);
	node->data = x;
	node->next = pht[index];
	pht[index] = node;
}
void HashShow(HashTable pht)
{
	for (int i = 0; i < P; ++i)
	{
		printf("%d :", i);
		HashNode* p = pht[i];
		while (p != NULL)
		{
			printf("%d->", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

#endif // !_HASH_H_
