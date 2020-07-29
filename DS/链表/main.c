#include "dclist.h"
int main()
{
	//SList list;
	//SListInit(&list);

	DCList list;
	DCListInit(&list);
	
	ElemType Select = 1;
	ElemType item = 0;
	printf("--------------------------------------------\n");
	printf("-  [0]quit_system           [1]push_back   -\n");
	printf("-  [2]push_front            [3]print_list  -\n");
	printf("-  [4]pop_back              [5]pop_front   -\n");
	printf("-  [6]insert_pos            [7]insert_val  -\n");
	printf("-  [8]erase_pos             [9]erase_val   -\n");
	printf("-  [10]find                 [11]length     -\n");
	printf("-  [12]sort                 [13]reverse     -\n");
	printf("-  [14]clear                [15]length     -\n");
	printf("-  [16]destroy              [17]length     -\n");
	printf("--------------------------------------------\n");
	while (Select) {
		printf("请选择:>");
		scanf("%d", &Select);
		if (Select == 0)
			break;
		switch (Select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1) {
				DCListPushBack(&list, item);
			}
			printf("尾部插入数据成功...\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1) {
				DCListPushFront(&list, item);
			}
			break;
		case 3:
			DCListShow(list);
			break;
		case 4:
			DCListPopBack(&list);
			break;
		case 5:
			DCListPopFront(&list);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			DCListSort(list);
			printf("链表排序成功......\n");
			break;
		case 13:
			DCListRverse(list);
			break;
		case 14:
			DCListClear(&list);
			break;
		case 16:
			DCListDestroy(&list);
			break;
		}
	}
	return 0;
}