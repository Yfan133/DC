#ifndef _BST_H_
#define _BST_H_

#include"common.h"
typedef int BstElemType;
typedef struct BSTNode
{
	BstElemType data;
	struct BSTNode* left_Child;
	struct BSTNode* right_Child;
}BSTNode;
typedef BSTNode* BSTree;
///////////////////////////////////////////////////////////////////
void BstInit(BSTree* t);
bool BstInsert(BSTree* t, BstElemType x);
BstElemType BstMin(BSTree t);
BstElemType BstMax(BSTree t);
void BstSortPrint(BSTree t);
BSTNode* BstFind(BSTree t, BstElemType key);
bool BstErase(BSTree* t, BSTNode* p);
///////////////////////////////////////////////////////////////////
void BstInit(BSTree* t)
{
	*t = NULL;
}
bool BstInsert(BSTree* t, BstElemType x)
{
	if (*t == NULL)
	{
		(*t) = (BSTNode*)malloc(sizeof(BSTNode));
		assert(*t != NULL);
		(*t)->data = x;
		(*t)->left_Child = (*t)->right_Child = NULL;
		return true;
	}
	else
	{
		if (x < (*t)->data)
			return BstInsert(&(*t)->left_Child, x);
		else if (x > (*t)->data)
			return BstInsert(&(*t)->right_Child, x);
		else
			return false;
		
	}
}
BstElemType BstMin(BSTree t)
{
	assert(t != NULL);
	while (t->left_Child != NULL)
		t = t->left_Child;
	return t->data;
}
BstElemType BstMax(BSTree t)
{
	assert(t != NULL);
	while (t->right_Child != NULL)
		t = t->right_Child;
	return t->data;
}
void BstSortPrint(BSTree t)
{
	if (t != NULL)
	{
		BstSortPrint(t->left_Child);
		printf("%d ", t->data);
		BstSortPrint(t->right_Child);
	}
}
BSTNode* BstFind(BSTree t, BstElemType key)
{
	if (t == NULL || t->data == key)
		return t;
	else
	{
		BSTNode* p = t->left_Child;
		if (key > t->data)
			p = t->right_Child;
		return BstFind(p, key);
	}
}
bool BstErase(BSTree* t, BSTNode* p)
{
	if (*t != NULL)
	{
		if (p->data < (*t)->data)
			BstErase(&(*t)->left_Child, p);
		else if (p->data > (*t)->data)
			BstErase(&(*t)->right_Child, p);
		else
		{
			if (p->left_Child != NULL && p->right_Child != NULL)
			{
				BSTNode* s = p->left_Child;
				while (s->right_Child != NULL)
					s = s->right_Child;
				p->data = s->data;
				BstErase(&p->left_Child, s);
			}
			else
			{
				if (p->left_Child != NULL)
					*t = p->left_Child;
				else
					*t = p->right_Child;
				free(p);
			}
			return true;
		}
	}
	return false;
}
#endif // !_BST_H_