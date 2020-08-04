#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"common.h"

typedef struct BinTreeNode
{
	BinTreeElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
typedef BinTreeNode* BinTree;
typedef BinTreeNode* LinkQueueElemType;

//////////////////////////////////////////////////////////
typedef struct LinkQueueNode
{
	LinkQueueElemType data;
	struct LinkQueueNode* link;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode* head; // 队头指针
	LinkQueueNode* tail; // 队尾指针
}LinkQueue;
void LinkQueueInit(LinkQueue* pq);
void LinkQueueEn(LinkQueue* pq, LinkQueueElemType x);
void LinkQueueDe(LinkQueue* pq);
LinkQueueElemType LinkQueueFront(LinkQueue* pq);
int LinkQueueSize(LinkQueue* pq);
bool LinkQueueEmpty(LinkQueue* pq);
void LinkQueueDestroy(LinkQueue* pq);
////////////////////////////////////////////////////////////////////
void LinkQueueInit(LinkQueue* pq)
{
	assert(pq != NULL);
	pq->head = pq->tail = NULL;
}
void LinkQueueEn(LinkQueue* pq, LinkQueueElemType x)
{
	assert(pq != NULL);
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;
	if (pq->head == NULL)
		pq->head = pq->tail = node;
	else
	{
		pq->tail->link = node;
		pq->tail = node;
	}
}
void LinkQueueDe(LinkQueue* pq)
{
	assert(pq != NULL);
	if (pq->head != NULL)
	{
		LinkQueueNode* p = pq->head;
		if (pq->head == pq->tail)
			pq->head = pq->tail = NULL;
		else
			pq->head = p->link;
		free(p);
	}
}
LinkQueueElemType LinkQueueFront(LinkQueue* pq)
{
	assert(pq != NULL);
	assert(pq->head != NULL);
	return pq->head->data;  //return pq->tail->data
}
int LinkQueueSize(LinkQueue* pq)
{
	assert(pq != NULL);
	int size = 0;
	LinkQueueNode* p = pq->head;
	while (p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}
bool LinkQueueEmpty(LinkQueue* pq)
{
	assert(pq != NULL);
	return pq->head == NULL;
}
void LinkQueueDestroy(LinkQueue* pq)
{
	assert(pq != NULL);
	LinkQueueNode* p = pq->head;
	while (p != NULL)
	{
		pq->head = p->link;
		free(p);
		p = pq->head;
	}
}
///////////////////////////////////////////////////////////////////////////////
//typedef struct BinTreeNode
//{
//	BinTreeElemType data;
//	struct BinTreeNode* leftChild;
//	struct BinTreeNode* rightChild;
//}BinTreeNode;
//
//typedef BinTreeNode* BinTree;

//二叉树的创建
void BinTreeInit(BinTree* t);
void BinTreeCreate(BinTree* t);
BinTree BinTreeCreate_1();
BinTree BinTreeCreate_2(const char* s, int* i);
BinTree BinTreeCreate_3(const char* vlr, const char* lvr, int n);
BinTree BinTreeCreate_4(const char* lvr, const char* lrv, int n);

//二叉树的遍历
void BinTreeVLR(BinTree t);
void BinTreeLVR(BinTree t);
void BinTreeLRV(BinTree t);
void BinTreeLevel(BinTree t);

////二叉树的非递归遍历
//void BinTreeVLR_Nor(BinTree t);
//void BinTreeLVR_Nor(BinTree t);
//void BinTreeLRV_Nor(BinTree t);
//
//二叉树的算法
int Size(BinTree t);
int Height(BinTree t);
BinTreeNode* Left(BinTreeNode* p);
BinTreeNode* Right(BinTreeNode* p);
BinTreeNode* BinTreeFind(BinTree t, BinTreeElemType key);
BinTreeNode* BinTreeParent(BinTree t, BinTreeNode* p);
BinTreeNode* BinTreeClone(BinTree t);
bool         Equal(BinTree t1, BinTree t2);
void BinTreeDestory(BinTree* t);
int BinTreeLeafSize(BinTree t);
int BinTreeLevelKSize(BinTree t, int k);
//////////////////////////////////////////////////////////////////////////////////
void BinTreeInit(BinTree* t)
{
	assert(t != NULL);
	*t = NULL;
}
void BinTreeCreate(BinTree* t)
{
	assert(t != NULL);
	BinTreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate(&(*t)->leftChild);
		BinTreeCreate(&(*t)->rightChild);
	}
}
BinTree BinTreeCreate_1()
{
	BinTreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(p != NULL);
		p->data = item;
		p->leftChild=BinTreeCreate_1();
		p->rightChild = BinTreeCreate_1();
		return p;
	}
}
BinTree BinTreeCreate_2(const char* s, int* i)
{
	assert(s != NULL);
	if (s[*i] == '\0' || s[*i] == '#')
		return NULL;
	else
	{
		BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(p != NULL);
		p->data = s[*i];
		(*i)++;
		p->leftChild = BinTreeCreate_2(s, i);
		(*i)++;
		p->rightChild = BinTreeCreate_2(s, i);
		return p;
	}
}
BinTree BinTreeCreate_3(const char* vlr, const char* lvr, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (vlr[0] != lvr[k])
		++k;
	BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	p->data = lvr[k];
	p->leftChild = BinTreeCreate_3(vlr + 1, lvr, k);
	p->rightChild = BinTreeCreate_3(vlr + k + 1, lvr + k + 1, n - k - 1);
	return p;
}
BinTree BinTreeCreate_4(const char* lrv, const char* lvr, int n)
{
	
}
void BinTreeVLR(BinTree t)
{
	if (t != NULL)
	{
		printf("%c", t->data);
		BinTreeVLR(t->leftChild);
		BinTreeVLR(t->rightChild);
	}
}
void BinTreeLVR(BinTree t)
{
	if (t != NULL)
	{
		BinTreeLVR(t->leftChild);
		printf("%c", t->data);
		BinTreeLVR(t->rightChild);
	}
}
void BinTreeLRV(BinTree t)
{
	if (t != NULL)
	{
		BinTreeLRV(t->leftChild);
		BinTreeLRV(t->rightChild);
		printf("%c", t->data);
	}
}
void BinTreeLevel(BinTree t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t);
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
		}
		LinkQueueDestroy(&Q);
	}
}
void BinTreeDestory(BinTree* t)
{
	/*BinTreeNode* tmp = *t;
	if (tmp != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueueEn(&Q, tmp);
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
			free(p);
		}
		LinkQueueDestroy(&Q);
	}*/
	if (*t != NULL)
	{
		BinTreeDestory(&(*t)->leftChild);
		BinTreeDestory(&(*t)->rightChild);
		free(*t);
		*t = NULL;
	}
}
int Size(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1;
}
int Height(BinTree t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = Height(t->leftChild);
		int right_h = Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
int BinTreeLeafSize(BinTree t)
{
	static int count = 0;
	if (t != NULL)
	{
		if ((t->leftChild == NULL) && (t->rightChild == NULL))
			count++;
		BinTreeLeafSize(t->leftChild);
		BinTreeLeafSize(t->rightChild);
	}
	return count;
}
int BinTreeLevelKSize(BinTree t, int k)
{

}
BinTreeNode* BinTreeFind(BinTree t, BinTreeElemType key)
{
	if (t == NULL || t->data == key)
		return t;
	BinTreeNode* p = BinTreeFind(t->leftChild, key);
	if (p != NULL)
		return p;
	return BinTreeFind(t->rightChild, key);
}
BinTreeNode* BinTreeParent(BinTree t, BinTreeNode* p)
{
	if (t == NULL || p == NULL || t == p)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	BinTreeNode* q = BinTreeParent(t->leftChild, p);
	if (q != NULL)
		return q;
	return BinTreeParent(t->rightChild, p);
}
BinTreeNode* BinTreeClone(BinTree t);
#endif

