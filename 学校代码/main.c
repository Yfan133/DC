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
		printf("*  [1]Push_Back          [2]Show_By_No       *\n");
		printf("*  [3]Show_By_Depon      [4]Show_By_Score    *\n");
		printf("*  [5]Dele_By_No         [6]Write_to_File    *\n");
		printf("*  [0]Quit_System                            *\n");
		printf("**********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &Select);
		if (Select == 0)
			break;
		switch (Select)
		{
		case 1:
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
			break;
		case 2:
			SListShowWay(&head, 1);
			break;
		case 3:
			SListShowWay(&head, 2);
			break;
		case 4:
			SListShowWay(&head, 3);
			break;
		case 5:
			printf("No:");
			scanf("%d", &No);
			SListDeleByNo(&head, No);
			break;
		case 6:
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
