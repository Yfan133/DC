#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"common.h"
typedef struct BinTreeNode
{
	BTElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
typedef BinTreeNode* BinTree;
///////////////////////////////////////////////////////////////////////////////

//二叉树的创建
void BinTreeInit(BinTree* t);
void BinTreeCreate(BinTree* t);
BinTree BinTreeCreate_1();
BinTree BinTreeCreate_2(const char* s, int* i);
//BinTree BinTreeCreate_3(const char* vlr, const char* lvr, int n);
//BinTree BinTreeCreate_4(const char* lvr, const char* lrv, int n);

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
////二叉树的算法
//int Size(BinTree t);
//int Height(BinTree t);
//BinTreeNode* Left(BinTreeNode* p);
//BinTreeNode* Right(BinTreeNode* p);
//BinTreeNode* BinTreeFind(BinTree t, BTElemType key);
//BinTreeNode* BinTreeParent(BinTree t, BinTreeNode* p);
//BinTreeNode* BinTreeClone(BinTree t);
//bool         Equal(BinTree t1, BinTree t2);
//////////////////////////////////////////////////////////////////////////////////
void BinTreeInit(BinTree* t)
{
	assert(t != NULL);
	*t = NULL;
}
void BinTreeCreate(BinTree* t)
{
	assert(t != NULL);
	BTElemType item;
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
	BTElemType item;
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
//BinTree BinTreeCreate_3(const char* vlr, const char* lvr, int n);
//BinTree BinTreeCreate_4(const char* lvr, const char* lrv, int n);
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
void BinTreeLevel(BinTree t);
//int Height(BinTree t)
//{
//	if (t == NULL)
//		return 0;
//	else
//	{
//		int left_h = Height(t->leftChild);
//		int right_h = Height(t->rightChild);
//		return (left_h > right_h ? left_h : right_h) + 1;
//	}
//}
#endif

