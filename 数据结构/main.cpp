#include"bintree.h"

int main()
{
	//const char* str = "ABC##DE##F##G#H##";
	BinTree bt;
	BinTreeInit(&bt);
	BinTreeCreate(&bt);
	//bt = BinTreeCreate_1();
	//int index = 0;
	//bt = BinTreeCreate_2(str, &index);
	//BinTree bt1 = BinTreeClone(bt);

	//�������
	printf("VLR: ");
	BinTreeVLR(bt);
	printf("\n");
	//�������
	printf("LVR: ");
	BinTreeLVR(bt);
	printf("\n");
	//�������
	printf("LRV: ");
	BinTreeLRV(bt);
	printf("\n");
	//��α���
	//printf("Level: ");
	//BinTreeLevel(bt);
	//printf("\n");
	printf("size = %d\n", Size(bt));
	printf("height = %d\n", Height(bt));

	getchar();	//������ող��������֮���'\n'

	BinTree bt2;
	BinTreeInit(&bt2);
	BinTreeCreate(&bt2);
	if (Equal(bt, bt2))
		printf("yes!\n");
	return 0;
}