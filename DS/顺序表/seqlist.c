#include"seqlist.h"
int main()
{
	SeqList list;
	SeqListInit(&list);

	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while (select)
	{
		printf("*********************************************\n");
		printf("*  [0] quit_system         [1] push_back    *\n");
		printf("*  [2] push_front          [3] print_list   *\n");
		printf("*  [4] pop_back            [5] pop_front    *\n");
		printf("*  [6] insert_pos          [7] insert_val   *\n");
		printf("*  [8] erase_pos           [9] erase_val    *\n");
		printf("*  [10] find               [11] length      *\n");
		printf("*  [12] capacity           [13] sort        *\n");
		printf("*  [14] reverse            [15] clear       *\n");
		printf("*  [16] front              [17] back        *\n");
		printf("*  [18] binary_find        [19] erase_all   *\n");
		printf("*********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&list, item);
			}
			printf("尾部插入数据成功......\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			printf("头部插入数据成功......\n");
			break;
		case 3:
			SeqListPrint(&list);
			break;
		case 4:
			SeqListPopBack(&list);
			break;
		case 5:
			SeqListPopFront(&list);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			flag = SeqListInsertByPos(&list, pos, item);
			if (flag)
				printf("插入数据成功.......\n");
			else
				printf("插入数据失败.......\n");
			break;
		case 7:
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			SeqListSort(&list);
			SeqListInsertByVal(&list, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListEraseByPos(&list, pos);
			printf("删除数据成功\n");
			break;
		case 9:
			printf("请输入要删除的元素");
			scanf("%d", &item);
			SeqListEraseByVal(&list, item);
			printf("删除数据成功\n");
			break;
		case 10:
			printf("请输入要查找的关键值:>");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos == -1)
				printf("数据查找失败.\n");
			else
				printf("数据查找成功.\n");
				printf("%d\n",pos);
			break;
		case 11:
			printf("SeqList Length = %d\n", SeqListLength(&list));
			break;
		case 12:
			printf("SeqList Capacity = %d\n", SeqListCapacity(&list));
			break;
		case 13:
			SeqListSort(&list);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			SeqListReverse(&list);
			printf("顺序表反转成功......\n");
			break;
		case 15:
			SeqListClear(&list);
			break;
		default:
			printf("命令出错,请重新输入......\n");
			break;
		}
		system("pause");
		system("cls");
	}

	SeqListDestory(&list);
	return 0;
}
//反转时错误