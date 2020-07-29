#ifndef _DLIST_H_
#define _DLIST_H_

#include "main.h"
typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;
typedef SListNode* SList;



#endif
