#ifndef _MAIN_C_
#define _MAIN_C_


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
void HashInsert(HashTable pht,ElemType x)
{
	int index = Hash(x);
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	assert(node != NULL);
	node->data = x;
	node->next = pht[index];
	pht[index] = node;
}
#endif // !_MAIN_C_