//#include"main.h"
//
//typedef char ElemType;
//typedef struct SListNode
//{
//	ElemType data;
//	struct SListNode* next;
//}SListNode, * SList;
//
/////////////////////////////////////////////////////////////////////////////////////////
//void SListInit(SList* phead)
//{
//	assert(phead != NULL);
//	*phead = NULL;
//}
//void SListPushBack(SList* phead, ElemType target)
//{
//	assert(phead != NULL);
//	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
//	s->data = target;
//	s->next = NULL;
//	SListNode* p = *phead;
//	if (p == NULL)
//		*phead = s;
//	else
//	{
//		while (p->next != NULL)
//			p = p->next;
//		p->next = s;
//	}
//}
//void SListShow(SList phead)
//{
//	assert(phead != NULL);
//	SListNode* p = phead;
//	while (p != NULL)
//	{
//		printf("%c ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int SListLength(SList phead)
//{
//	assert(phead != NULL);
//	SListNode* p = phead;
//	int length = 0;
//	while (p != NULL)
//	{
//		p = p->next;
//		++length;
//	}
//	return length;
//}
//bool IsEmpty(SList phead)
//{
//	if (phead == NULL)
//		return true;
//	return false;
//}
//char SListThirdNum(SList phead)
//{
//	assert(phead != NULL);
//	SListNode* p = phead;
//	int times = 2;
//	while (times--)
//		p = p->next;
//	return p->data;
//}
//int SListFindPos(SList phead, ElemType target)
//{
//	assert(phead != NULL);
//	SListNode* p = phead;
//	int pos = 1;
//	while (p != NULL)
//	{
//		if (p->data == target)
//			return pos;
//		++pos;
//		p = p->next;
//	}
//	return 0;
//}
//void SListInsertPos(SList* phead, ElemType target, int pos)
//{
//	assert(*phead != NULL);
//	SListNode* p = *phead;
//	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
//	s->data = target;
//	s->next = NULL;
//	if (pos == 1)
//	{
//		s->next = *phead;
//		*phead = s;
//		return;
//	}
//	while (p->next != NULL && pos > 2)
//	{
//		p = p->next;
//		--pos;
//	}
//	if (pos > 2)
//	{
//		printf("所给位置超过链表总长!\n");
//		return;
//	}
//	s->next = p->next;
//	p->next = s;
//}
//void SListDelePos(SList* phead, int pos)
//{
//	assert(*phead != NULL);
//	SListNode* p = *phead;
//	if (pos == 1)
//	{
//		*phead = (*phead)->next;
//		return;
//	}
//	while (p != NULL && pos > 2)
//	{
//		p = p->next;
//		--pos;
//	}
//	if (pos > 2)
//	{
//		printf("所给位置超过链表总长!\n");
//		return;
//	}
//	SListNode* s = p->next;
//	p->next = s->next;
//	free(s);
//	s = NULL;
//}
//void SListDestroy(SList* phead)
//{
//	assert(*phead != NULL);
//	while ((*phead) != NULL)
//	{
//		SListNode* p = *phead;
//		(*phead) = (*phead)->next;
//		free(p);
//		p = NULL;
//	}
//}
//int main()
//{
//	SListNode* head;
//	SListInit(&head);
//	SListPushBack(&head, 'a');
//	SListPushBack(&head, 'b');
//	SListPushBack(&head, 'c');
//	SListPushBack(&head, 'd');
//	SListShow(head);
//	printf("length=%d\n", SListLength(head));
//	if (IsEmpty(head))
//		printf("链表为空\n");
//	printf("the third data = %c\n", SListThirdNum(head));
//	printf("元素:%c在第%d个位置\n", 'a', SListFindPos(head, 'a'));
//	SListInsertPos(&head, 'e', 4);
//	SListShow(head);
//	SListDelePos(&head, 3);
//	SListShow(head);
//	SListDestroy(&head);
//	return 0;
//}