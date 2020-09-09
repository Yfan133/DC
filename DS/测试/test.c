#include"test.h"
char* delete_space(char s[],int lenth)
{
    int count = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (s[i] == ' ')
            count++;
    }
    count = count * 2 + lenth - 1;
    char arr[100];
    for (int i = lenth - 1; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            arr[count--] = '0';
            arr[count--] = '2';
            arr[count--] = '%';
        }
        else
            arr[count--] = s[i];
    }
    return arr;
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
    unsigned int tmp = 1;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((tmp & target) == 1)
            ++count;
        target = target >> 1;
    }
    return count;
}
int count_fab_value(int target)
{
    int p1 = 1, p2 = 1, p3 = 0;
    for (int i = 0; i < target - 2; ++i)
    {
        p3 = p1 + p2;
        p1 = p2;
        p2 = p3;
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
void main()
{
    //ab s;
    //int a = 10;
    //int arr[4][4] = { 1,2,8,9, 2,4,9,12, 4,7,10,13, 6,8,11,15 };
    //printf("%d\n", Find_Data(arr,4,4,15));
    //printf("%d", 5 - 10);
    //unsigned int data = -123;
    //printf("%d", count_theone(data));
    //printf("%d", count_fab_value(10));
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
    int j = 4;
    int m = 1;
    int k;
    k = fun(j, m);
    printf("%d,", k);
    k = fun(j, m);
    printf("%d/n", k);
}
//#pragma pack()