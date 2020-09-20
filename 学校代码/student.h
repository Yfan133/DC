#include"main.h"
typedef char* ElemType;
typedef struct StudentIn
{
	ElemType no;
	ElemType name;
	ElemType depno;
	int		 score;
}StudentIn;
typedef struct SListNode
{
	struct StudentIn* student;
	struct SListNode* next;
}SListNode, * SList;

/////////////////////////////////////////////////////////////////////
void SListInit(SList* phead)
{
	assert(phead != NULL);
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->student = NULL;
	s->next = NULL;
	*phead = s;
}
void SListPushBack(SList* phead, ElemType No, ElemType Name, ElemType Depno, int Score)
{
	assert(*phead != NULL);
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->student = (StudentIn*)malloc(sizeof(StudentIn));
	s->student->no = No;
	s->student->name = Name;
	s->student->depno = Depno;
	s->student->score = Score;
	s->next = NULL;
	SListNode* p = *phead;
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}
void SListShowByNo(SList phead)
{
	assert(phead != NULL);
	SListNode* p = phead->next;
	while (p != NULL)
	{
		printf("%s   %s   %s   %d\n", p->student->no,p->student->name,p->student->depno,p->student->score);
		p = p->next;
	}
}
void SListSort(SList* phead)
{
	assert((*phead)->next != NULL);
	SListNode* p = (*phead)->next;
	SListNode* q = p->next;
	SListNode* prev = NULL;
	SListNode* tmp = (*phead)->next;
	if (q == NULL) 
		return;
	p->next = NULL;
	while (q != NULL) 
	{
		p = q;
		q = q->next;
		while (tmp != NULL && p->student->score > tmp->student->score) 
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL) {
			p->next = tmp;
			tmp = *phead = p;
		}
		else {
			p->next = tmp;
			prev->next = p;
		}
		prev = NULL;
		tmp = (*phead)->next;
	}
}
void SListShowByScore(SList* phead)
{
	assert(*phead != NULL);
	SListSort(phead);
}
void SListDeleByNo(SList* phead, ElemType No)
{
	assert(*phead != NULL);
	SListNode* p = *phead;
	while (p->next != NULL && p->next->student->no != No)
		p = p->next;
	if (p->next == NULL)
	{
		printf("未查询到该学生信息...\n");
		return;
	}
	SListNode* s = p->next;
	p->next = s->next;
	free(s);
	s = NULL;
}
void SListShow(SList phead,int way)
{
	assert(phead != NULL);
	switch (way)
	{
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	default:
		printf("输入有误,请重新输入...\n");
		break;
	}
}
