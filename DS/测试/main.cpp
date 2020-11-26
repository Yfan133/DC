#include<iostream>
#include<string>
#include<vector>
#include<queue>
//#include<stack>
using namespace std;
#pragma warning(disable:4996)
//int Quick(vector<int>& arr, int left, int right)
//{
//	
//}
//void QuickSort(vector<int>& arr,int left,int right)
//{
//	
//}
//int main()
//{
//	vector<int> arr = { 49,38,56,75,12,99,68,75,49 };
//	QuickSort(arr, 0, arr.size());
//	return 0;
//}
#include<assert.h>
typedef char BinTreeElemType;
typedef struct BinTreeNode
{
	BinTreeElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef BinTreeNode* BinTree;

//二叉树的创建
void BinTreeInit(BinTree* t);
BinTree BinTreeCreate_1();
void BinTreeInit(BinTree* t)  //BinTreeNode**t;
{
	*t = NULL;
}

BinTree BinTreeCreate_1()
{
	BinTreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreate_1();
		t->rightChild = BinTreeCreate_1();
		return t;
	}
}
void main()
{
	const char* str = "ABC##DE##F##G#H##";
	BinTree bt;
	BinTreeInit(&bt);
	bt = BinTreeCreate_1();
	return;
}