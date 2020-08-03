//#include"bst.h"
#include"bintree.h"
//void main()
//{
//	BSTNode* bst;
//	BstInit(&bst);
//	int ar[] = { 27,15,19,18,1,28,34,65,100,49,25,37 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	for (int i = 0; i < n; ++i)
//	{
//		BstInsert(&bst, ar[i]);
//	}
//	printf("min = %d\n", BstMin(bst));
//	printf("max = %d\n", BstMax(bst));
//	BstSortPrint(bst);
//	printf("\n");
//	BSTNode* p = BstFind(bst, 65);
//	BstErase(&bst, p);
//}
void main()
{
	BinTreeNode* Q;
	BinTreeInit(&Q);
	int index = 0;
	const BinTreeElemType* vlr = "ABCDEFGH";
	const BinTreeElemType* lrv = "CEFDBHGA";
	const BinTreeElemType* lvr = "CBEDFAGH";
	Q = BinTreeCreate_3(vlr, lvr, strlen(vlr));
}
//void main()
//{
//	BinTreeNode* Q;
//	BinTreeInit(&Q);
//	int index = 0;
//	const BinTreeElemType* str = "ABC##DE##F##G#H##";
//	Q = BinTreeCreate_2(str, &index);
//	printf("%d", BinTreeLeafSize(Q));
//	BinTreeFind(Q, 'F');
//	/*BinTreeVLR(Q);
//	printf("\n");
//	BinTreeLVR(Q);
//	printf("\n");
//	BinTreeLRV(Q);
//	printf("\n");
//	BinTreeLevel(Q);
//	printf("\n");*/
//	BinTreeDestory(&Z);
//}