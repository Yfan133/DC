#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
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
//#include<assert.h>
//typedef char BinTreeElemType;
//typedef struct BinTreeNode
//{
//	BinTreeElemType data;
//	struct BinTreeNode* leftChild;
//	struct BinTreeNode* rightChild;
//}BinTreeNode;
//
//typedef BinTreeNode* BinTree;
//
////二叉树的创建
//void BinTreeInit(BinTree* t);
//BinTree BinTreeCreate_1();
//void BinTreeInit(BinTree* t)  //BinTreeNode**t;
//{
//	*t = NULL;
//}
//
//BinTree BinTreeCreate_1()
//{
//	BinTreeElemType item;
//	scanf("%c", &item);
//	if (item == '#')
//		return NULL;
//	else
//	{
//		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t != NULL);
//		t->data = item;
//		t->leftChild = BinTreeCreate_1();
//		t->rightChild = BinTreeCreate_1();
//		return t;
//	}
//}

void main()
{
	//int ar[] = { 1,2,3 };
	//int* p = ar;
	//*p += 2;
	//*p++;	//这里++优先级更高
	//int* q;
	//q = new int(2);	//这里赋初值和p记住
	return;
}
/*
二维数组：
a[i][j]=*(*(a+i)+j)=*(a+i)[j];
&a[i][j]=a[i]+j=*(a+i)+j

char* x = (char*)"abc";		//指针x和y指向字符常量区，不能修改其内容。并且x和y的地址相同
char* y = (char*)"abc";

1. 引用必须用指向一个实例
2. 将函数用inline修饰只是向编译器建议这个函数可以作为内联函数来使用，是否展开由编译器决定
3. inline必须放在函数定义的前面，放在声明前面是不起作用的
4. 如果在多个源文件中定义同名的inline函数，则函数实现体必须一致

*/

