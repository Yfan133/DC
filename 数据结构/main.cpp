#if 0
#include"bintree.h"

int main()
{
	const char* str1 = "ABCDEFGH";
	const char* str2 = "CBEDFAGH";
	BinTree bt;
	BinTreeInit(&bt);
	bt = BinTreeCreateLRV_LVR(str1, str2, strlen(str1));
	//BinTreeCreate(&bt);
	//bt = BinTreeCreate_1();
	//int index = 0;
	//bt = BinTreeCreate_2(str, &index);
	//BinTree bt1 = BinTreeClone(bt);

	//先序遍历
	printf("VLR: ");
	BinTreeVLR(bt);
	printf("\n");
	printf("VLR: ");
	BinTreeVLR_Nor(bt);
	printf("非递归\n");
	//中序遍历
	printf("LVR: ");
	BinTreeLVR(bt);
	printf("\n");
	printf("LVR: ");
	BinTreeLVR_Nor(bt);
	printf("非递归\n");
	//后序遍历
	printf("LRV: ");
	BinTreeLRV(bt);
	printf("\n");
	printf("LRV: ");
	BinTreeLRV_Nor(bt);
	printf("非递归\n");
	//层次遍历
	//printf("Level: ");
	//BinTreeLevel(bt);
	//printf("\n");
	printf("size = %d\n", Size(bt));
	printf("height = %d\n", Height(bt));

	getchar();	//这个接收刚才输入完成之后的'\n'

	BinTree bt2;
	BinTreeInit(&bt2);
	BinTreeCreate(&bt2);
	if (Equal(bt, bt2))
		printf("yes!\n");
	return 0;
}
#endif
//#include "heap.h"
#if 0
int main()
{
	Minheap hp;
	HeapInit(&hp, 25);
	int ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; i++)
		HeapInsert(&hp, ar[i]);
	HeapShow(&hp);
	return 0;
}
#endif

#if 0
void main()
{
	int v = (0 - 1) / 2;
	int ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	Minheap mhp;
	HeapInit(&mhp, 25);
	for (int i = 0; i < n; ++i)
		HeapInsert(&mhp, ar[i]);
	HeapShow(&mhp);
	HeapInsert(&mhp, 17);
	HeapShow(&mhp);
	HeapErase(&mhp);
	HeapShow(&mhp);
}
#endif
#if 0
void main()
{
	//int ar[] = {27,15,19,18,28,34,65,49,25,37};
	int ar[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
	int n = sizeof(ar) / sizeof(ar[0]);
	Minheap mhp;
	HeapSort(&mhp, ar, n);
	HeapShow(&mhp);
}
#endif
#include "bst.h"
void main()
{
	int ar[] = { 27,15,19,18,1,28,34,65,100,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	BSTree bst;
	BstInit(&bst);
	for (int i = 0; i < n; ++i)
		BstInsert(&bst, ar[i]);
	printf("min = %d\n", BstMin(bst));
	printf("max = %d\n", BstMax(bst));
	BstSortPrint(bst);
	printf("\n");

	BSTNode* p = BstFind(bst, 27);
	BstErase(&bst, p);
}
