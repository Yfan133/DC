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