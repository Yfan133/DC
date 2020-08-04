#ifndef _HEAP_H_
#define _HEAP_H_

#include"common.h"
typedef int HeapElemType;
typedef struct HeapNode
{
	HeapElemType data;
	struct HeapNode* left_Child;
	struct HeapNode* right_Child;
}HeapNode;
typedef HeapNode* Heap;
////////////////////////////////////////////////////////////////
void HeapInit(Heap* t);
///////////////////////////////////////////////////////////////
void HeapInit(Heap* t)
{
	assert(t != NULL);
	*t = NULL;
}

#endif // !_HEAP_H_

