#include"student.h"
int main()
{
	SListNode* head;
	SListInit(&head);
	int Select = 1;
	int item = 0;
	int No = 0;
	char Name[20] = "\0";
	int Depon = 0;
	float Score = 0;
	while (Select) 
	{
		printf("**********************************************\n");
		printf("*  [0]Quit_System           [1]Push_Back     *\n");
		printf("*  [2]Show_All_Score        [3]Show_By_No    *\n");
		printf("*  [4]Show_By_Depon         [5]Show_By_Score *\n");
		printf("*  [6]Dele_By_No            [7]Write_toFile  *\n");
		printf("**********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &Select);
		if (Select == 0)
			break;
		switch (Select)
		{
		case 1:
			while (item != -1) 
			{
				printf("ѧ��< ");
				scanf("%d", &No);
				printf("����< ");
				scanf("%s", Name);
				printf("ϵ����< ");
				scanf("%d", &Depon);
				printf("�ɼ�< ");
				scanf("%f", &Score);
				SListPushBack(&head, No, Name, Depon, Score);
				printf("β���������ݳɹ�...\n");
				printf("�Ƿ����,��������-1,��������1...\n������<");
				scanf("%d", &item);
			}
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:");
			//while (scanf("%d", &item), item != -1) {
				//DCListPushFront(&list, item);
			//}
			break;
		case 3:
			SListShowByNo(head);
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			break;
		case 7:
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
