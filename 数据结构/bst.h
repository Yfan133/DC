#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int BstElemType;
typedef struct BSTNode
{
	BstElemType val;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode, * BSTree;

void BstInit(BSTree* bst);
bool BstInsert(BSTree* t, BstElemType x);
BstElemType BstMin(BSTree t);
BstElemType BstMax(BSTree t);
void BstSortPrint(BSTree t);
BSTNode* BstFind(BSTree t, BstElemType key);
bool BstErase(BSTree* t, BSTNode* p);
/////////////////////////////////////////////////////////////////
void BstInit(BSTree* bst)
{
	assert(bst != nullptr);
	*bst = nullptr;
}
bool BstInsert(BSTree* t, BstElemType x)
{
	if (*t == nullptr)
	{
		(*t) = (BSTNode*)malloc(sizeof(BSTNode));
		assert(*t != nullptr);
		(*t)->val = x;
		(*t)->left = nullptr;
		(*t)->right = nullptr;
		return true;
	}
	if ((*t)->val > x)
		BstInsert(&(*t)->left, x);
	else if ((*t)->val < x)
		BstInsert(&(*t)->right, x);
	else
		return false;
}
BstElemType BstMin(BSTree bst)
{
	assert(bst != nullptr);
	/*if (bst->left == nullptr)
		return bst->val;
	return BstMin(bst->left);*/
	while (bst->left != nullptr)
		bst = bst->left;
	return bst->val;
}
BstElemType BstMax(BSTree bst)
{
	assert(bst != nullptr);
	if (bst->right == nullptr)
		return bst->val;
	return BstMax(bst->right);
}
void BstSortPrint(BSTree bst)
{
	if (bst != nullptr)
	{
		BstSortPrint(bst->left);
		printf("%d ", bst->val);
		BstSortPrint(bst->right);
	}
}
BSTNode* BstFind(BSTree bst, BstElemType key)
{
	if (bst == nullptr)
		return nullptr;
	if (bst->val == key)
		return bst;
	if (bst->val > key)
		return BstFind(bst->left, key);
	else
		return BstFind(bst->right, key);
}
//删除的核心就是找到合适的值，把他赋给p，然后free掉原位置的值
//要理解这里为什么传二级指针，是因为如果给一级指针赋空，函数外的值不会改变！！
bool BstErase(BSTree* t, BSTNode* p)
{
	if (*t != nullptr)
	{
		if ((*t)->val > p->val)
			BstErase(&(*t)->left, p);
		else if ((*t)->val < p->val)
			BstErase(&(*t)->right, p);
		else
		{
			//找到了p节点
			if (p->left && p->right)
			{
				//若左右都不为空
				BSTNode* tmp = p->left;
				//找到左支的最大值
				while (tmp->right)
					tmp = tmp->right;
				p->val = tmp->val;
				//把问题转换成在 p->left 为根节点中删除tmp节点
				BstErase(&p->left, tmp);
			}
			else
			{
				//左树右树有空
				BSTNode* tmp = p;
				//这里就是为什么要传二级指针的原因！！
				if (p->left == nullptr)
					*t = p->right;
				else
					*t = p->left;
				free(tmp);
				tmp = nullptr;
			}
			return true;
		}
	}
	return false;
}
