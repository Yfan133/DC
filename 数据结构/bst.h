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
//ɾ���ĺ��ľ����ҵ����ʵ�ֵ����������p��Ȼ��free��ԭλ�õ�ֵ
//Ҫ�������Ϊʲô������ָ�룬����Ϊ�����һ��ָ�븳�գ��������ֵ����ı䣡��
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
			//�ҵ���p�ڵ�
			if (p->left && p->right)
			{
				//�����Ҷ���Ϊ��
				BSTNode* tmp = p->left;
				//�ҵ���֧�����ֵ
				while (tmp->right)
					tmp = tmp->right;
				p->val = tmp->val;
				//������ת������ p->left Ϊ���ڵ���ɾ��tmp�ڵ�
				BstErase(&p->left, tmp);
			}
			else
			{
				//���������п�
				BSTNode* tmp = p;
				//�������ΪʲôҪ������ָ���ԭ�򣡣�
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
