#include"test.h"
void delete_space(char *arr1,char *arr2)
{
    while (*arr1)
    {
        if (*arr1 == ' ')
        {
            strcpy(arr2, "%20");
            arr1++;
            arr2 += 3;
        }
        else
            *arr2++ = *arr1++;
    }
    *arr2 = '\0';
}
int Find_Data(int arr[4][4],int bow,int line,int target)
{
    if (bow == 0 || line == 0)
        return 0;
    int i = 0, j = line - 1;
    while (i < bow && j >= 0)
    {
        if (target == arr[i][j])
            return 1;
        if (target < arr[i][j])
            --j;
        if (target > arr[i][j])
            ++i;
    }
    return 0;
}
int count_theone(unsigned int target)
{
    int count = 0;
    while (target > 0)
    {
        if (target % 2)
            count++;
        target /= 2;
    }
    return count;
}
int count_fab_value(int target)
{
    if (target < 3)
        return 1;
    int p1 = 1, p2 = 1, p3 = 0;
    while (target > 2)
    {
        p3 = p1 + p2;
        p1 = p2;
        p2 = p3;
        --target;
    }
    return p3;
}
typedef struct ab
{ 
    char a; 
    char o;
    char p;
    int b; 
    //double c;
    //short d;
}ab;
//#pragma pack(4)
int fun(int x, int y)
{
    static int m = 0;
    static int i = 2;
    i += m + 1;
    m = i + x + y;
    return m;
}
typedef struct SListNode
{
    int data;
    struct SlistNode* next;
}SListNode;
typedef SListNode* SList;
void SListInit(SList* phead)
{
    assert(phead != NULL);
    *phead = NULL;
}
void SListPushBack(SList *phead,int data)
{
    assert(phead != NULL);
    SListNode* s = (SListNode*)malloc(sizeof(SListNode));
    s->data = data;
    s->next = NULL;
    SListNode* p = *phead;
    if (p == NULL)
        *phead = s;
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = s;
    }
}
void SListReverse(SList* phead)
{
    assert(phead != NULL);
    if (*phead == NULL)
        return;
    SListNode* p = *phead;
    SListNode* next = p->next;
    p->next = NULL;
    while (next != NULL)
    {
        p = next;
        next = p->next;
        p->next = *phead;
        *phead = p;
    }
}
void SListShow(SList phead)
{
    assert(phead != NULL);
    SListNode* p = phead;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
typedef struct student
{
    int No;
    char name[20];
    int depno;
    float score;
}student;
int main()
{
    int* ar = "acdef";
    int* br
    //student* peter = (student*)malloc(sizeof(student));
    //memset(peter->name, 0, sizeof(peter->name));
    //FILE* pfile;
    //pfile = fopen("D:\\myfile.txt", "r+");
    //fscanf(pfile, "%d,%s,%d,%f", peter->No, peter->name,peter->depno,peter->score);
    ////fscanf(pfile, "%d,%s,%d,%f\n", peter->No, peter->name, peter->depno, peter->score);
    //fclose(pfile);
    //return 0;
    /*SListNode* phead;
    SListInit(&phead);
    SListPushBack(&phead, 1);
    SListPushBack(&phead, 2);
    SListPushBack(&phead, 3);
    SListReverse(&phead);
    SListShow(phead);*/
    //func();
    //printf("%d", x);
    /*char arr1[] = "abc defgx yz";
    char arr2[20];
    delete_space(arr1, arr2);*/
    //ab s;
    //int a = 10;
    //int arr[4][4] = { 1,2,8,9, 2,4,9,12, 4,7,10,13, 6,8,11,15 };
    //printf("%d\n", Find_Data(arr,4,4,15));
    //printf("%d", 5 - 10);
    //unsigned int data = 123;
    //printf("%d", count_theone(data));
    //printf("%d", count_fab_value(5));
    /*struct tagTest1
    {
        short a;
        char d;
        long b;
        long c;
    };
    struct tagTest2
    {
        long b;
        short c;
        char d;
        long a;
    };
    struct tagTest3
    {
        short c;
        long b;
        char d;
        long a;
    };
    struct tagTest1 stT1;
    struct tagTest2 stT2;
    struct tagTest3 stT3;
    printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));*/
    /*enum ENUM_A
    {
        X1,
        Y1,
        Z1 = 5,
        A1,
        B1
    };
    enum ENUM_A enumA = Y1;
    enum ENUM_A enumB = B1;*/
    /*int j = 4;
    int m = 1;
    int k;
    k = fun(j, m);
    printf("%d,", k);
    k = fun(j, m);
    printf("%d/n", k)*/
 }
//#pragma pack()