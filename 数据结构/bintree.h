#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"common.h"
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftchild;
	struct BinTreeNode* rightchild;
}BinTreeNode, * BinTree;
////////////////////////////////////////////////////////
void BinTreeInit(BinTree* bt);

//二叉树的创建
void BinTreeCreate(BinTree* bt);

//二叉树的遍历
void BinTreeVLR(BinTree bt);
void BinTreeLVR(BinTree bt);
void BinTreeLRV(BinTree bt);
void BinTreeLevel(BinTree bt);

//二叉树算法
int Size(BinTree bt);
int Height(BinTree bt);
BinTreeNode* Left(BinTreeNode* p);
BinTreeNode* Right(BinTreeNode* p);
BinTreeNode* BinTreeFind(BinTree bt, ElemType key);
BinTreeNode* BinTreeParent(BinTree bt, BinTreeNode* p);
BinTreeNode* BinTreeCopy(BinTree bt);
bool Equal(BinTree bt1, BinTree bt2);
////////////////////////////////////////////////////////
void BinTreeInit(BinTree* bt)
{
	assert(bt != NULL);	//二级指针不能为空
	*bt = NULL;			//给一级指针赋空
}

//二叉树的创建
void BinTreeCreate(BinTree* bt)					//先序创建ABC##DE##F##G#H##
{
	assert(bt != NULL);
	ElemType tmp;
	scanf("%c", &tmp);
	(*bt) = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert((*bt) != NULL);
	if (tmp == '#')
		(*bt) = NULL;
	else
	{
		(*bt)->data = tmp;
		BinTreeCreate(&((*bt)->leftchild));
		BinTreeCreate(&((*bt)->rightchild));
	}
}

//二叉树的遍历
void BinTreeVLR(BinTree bt)
{
	if (bt == NULL)
		return;
	printf("%c  ", bt->data);
	BinTreeVLR(bt->leftchild);
	BinTreeVLR(bt->rightchild);
}
void BinTreeLVR(BinTree bt)
{
	if (bt == NULL)
		return;
	BinTreeVLR(bt->leftchild);
	printf("%c  ", bt->data);
	BinTreeVLR(bt->rightchild);
}
void BinTreeLRV(BinTree bt)
{
	if (bt == NULL)
		return;
	BinTreeVLR(bt->leftchild);
	BinTreeVLR(bt->rightchild);
	printf("%c  ", bt->data);
}
//void BinTreeLevel(BinTree bt)
//{
//	if (bt == NULL)
//		return;
//	LinkQueue Q;
//	LinkQueueInit(&Q);
//	LinkQueueEn(&Q,bt);
//	while (!Q.empty())
//	{
//		BinTreeNode* tmp = LinkQueueFront(&Q);
//		LinkQueuePop(&Q);
//		printf("%c ", tmp->data);
//		if()
//	}
//}

//二叉树的算法
int Size(BinTree bt)
{
	if (bt == NULL)
		return 0;
	else
		return 1 + Size(bt->leftchild) + Size(bt->rightchild);
}
int Height(BinTree bt)
{
	if (bt == NULL)
		return 0;
	int left = Height(bt->leftchild);
	int right = Height(bt->rightchild);
	return (left > right ? left : right) + 1;
}
BinTreeNode* Left(BinTreeNode* p)
{
	if (p == NULL)
		return NULL;
	return p->leftchild;
}
BinTreeNode* Right(BinTreeNode* p)
{
	if (p == NULL)
		return NULL;
	return p->rightchild;
}
BinTreeNode* BinTreeFind(BinTree bt, ElemType key)
{
	if (bt == NULL || bt->data == key)		//这句话合并了两句
		return bt;
	BinTreeNode* tmp = BinTreeFind(bt->leftchild, key);
	if (tmp != NULL)
		return tmp;
	return BinTreeFind(bt->rightchild, key);	//这里不管返回的是什么，直接给整体返回就行
}												//相当于返回了两次
BinTreeNode* BinTreeParent(BinTree bt, BinTreeNode* p)
{
	if (bt == NULL || p == NULL || bt == p)		//这里的判断条件一定记住，p可能就是bt那么直接返回null
		return NULL;
	if (bt->leftchild == p || bt->rightchild == p)
		return bt;
	BinTreeNode* tmp = BinTreeParent(bt->leftchild, p);
	if (tmp != NULL)
		return tmp;
	return BinTreeParent(bt->rightchild, p);
}
BinTreeNode* BinTreeCopy(BinTree bt)
{
	if (bt == NULL)
		return NULL;

	BinTreeNode* res = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(res != NULL);
	res->data = bt->data;
	res->leftchild = BinTreeCopy(bt->leftchild);
	res->rightchild = BinTreeCopy(bt->rightchild);
	return res;
}
bool Equal(BinTree bt1, BinTree bt2)
{
	if (bt1 == NULL && bt2 == NULL)
		return true;
	if (bt1 == NULL || bt2 == NULL)
		return false;
	return (bt1->data == bt2->data) && Equal(bt1->leftchild, bt2->leftchild) && Equal(bt1->rightchild, bt2->rightchild);
}

#endif // !_BINTREE_H_
/*
总结：
	1.在后序遍历完成返回值的时候，可以简化代码，只接收left判断出的值，如果不成立。
		要进行right的判断，直接把right判断结果返回给上一层，从代码角度返回了两次
	2.每次写递归程序之前，先想清楚所有的结束条件

*/