#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"common.h"
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftchild;
	struct BinTreeNode* rightchild;
}BinTreeNode, * BinTree;
void BinTreeInit(BinTree* t)
{
	assert(t != NULL);
	*t = NULL;
}
void BinTreeCreat(BinTree* t)	//ÏÈÐò´´½¨ABC##DE##F##G#H##
{
	assert(t != NULL);
	ElemType tmp;
	scanf("%c", &tmp);
	(*t) = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert((*t) != NULL);
	if (tmp == '#')
		(*t) = NULL;
	else
	{
		(*t)->data = tmp;
		BinTreeCreat(&((*t)->leftchild));
		BinTreeCreat(&((*t)->rightchild));
	}
}
int Size(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + Size(t->leftchild) + Size(t->rightchild);
}
int Height(BinTree t)
{
	if (t == NULL)
		return 0;
	int left = Height(t->leftchild);
	int right = Height(t->rightchild);
	return (left > right ? left : right) + 1;
}
//void BinTreeLevel(BinTree t)
//{
//	Queue Q;
//	QueueInit(&Q);
//	QueuePush(&Q, t);
//	while (!QueueIsEmpty(&Q))
//	{
//		BinTreeNode* tmp = QueueTop(&Q);
//		QueuePop(&Q);
//		printf("%d ", tmp->data);
//		if (tmp->leftchild)
//			QueuePush(&Q, t->leftchild);
//		if (tmp->rightchild)
//			QueuePush(tmp->rightchild);
//	}
//	QueueDestory(&Q);
//}
#endif // !_BINTREE_H_
