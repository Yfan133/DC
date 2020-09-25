#include"main.h"
typedef struct StudentIn
{
	int      no;
	char	 name[20];
	int      depno;
	float	 score;
}StudentIn;
typedef struct SListNode
{
	struct StudentIn* student;
	struct SListNode* next;
}SListNode, * SList;
//////////////////////////////////////////////////////////////////////////////
void SListInit(SList* phead)
{
	assert(phead != NULL);
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->student = NULL;
	s->next = NULL;
	*phead = s;
}
void SListPushBack(SList* phead, int No, char* Name, int Depno, float Score)
{
	assert(*phead != NULL);
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->student = (StudentIn*)malloc(sizeof(StudentIn));
	s->student->no = No;
	memset(s->student->name, 0, sizeof(s->student->name));
	memcpy(s->student->name, Name,strlen(Name));
	s->student->depno = Depno;
	s->student->score = Score;
	s->next = NULL;
	SListNode* p = *phead;
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}
void SListShow(SList phead)
{
	assert(phead != NULL);
	SListNode* p = phead->next;
	while (p != NULL)
	{
		printf("%d   %s   %d   %.1f\n", p->student->no,p->student->name,p->student->depno,p->student->score);
		p = p->next;
	}
}
void SListSortByNo(SList* phead)
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
		while (tmp != NULL && p->student->no > tmp->student->no)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL) {
			p->next = tmp;
			tmp = p;
			(*phead)->next = p;
		}
		else {
			p->next = tmp;
			prev->next = p;
		}
		prev = NULL;
		tmp = (*phead)->next;
	}
}
void SListSortByDepon(SList* phead)
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
		while (tmp != NULL && p->student->depno > tmp->student->depno)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL) {
			p->next = tmp;
			tmp = p;
			(*phead)->next = p;
		}
		else {
			p->next = tmp;
			prev->next = p;
		}
		prev = NULL;
		tmp = (*phead)->next;
	}
}
void SListSortByScore(SList* phead)
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
			tmp =  p;
			(*phead)->next = p;
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
	
}
void SListDeleByNo(SList* phead, int No)
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
void SListShowWay(SList* phead,int way)
{
	assert(*phead != NULL);
	switch (way)
	{
	case 1:
		SListSortByNo(phead);
		SListShow(*phead);
		break;
	case 2:
		SListSortByDepon(phead);
		SListShow(*phead);
		break;
	case 3:
		SListSortByScore(phead);
		SListShow(*phead);
		break;
	}
}
