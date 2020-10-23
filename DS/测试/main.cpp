#include<iostream>
using namespace std;
char* replaceSpace(char* s)
{
    int space = 0;
    int i = 0;
    while (s[i] != '\0')
        if (s[i++] == ' ')
            ++space;
    int j = i + 2 * space+1;
    /*char* arr = (char*)malloc(j);
    memcpy(arr, s, i + 1);
    free(s);
    s = arr;*/
    s=(char*)realloc(s,j);
    j--;
    while (i >= 0)
    {
        if (s[i] == ' ')
        {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
        else
            s[j--] = s[i];
        --i;
    }
    return s;
}
int main()
{
    char* s = (char*)malloc(sizeof(char) * 5);
    s[0] = 'a';
    s[1] = ' ';
    s[2] = 'b';
    s[3] = ' ';
    s[4] = '\0';
    s = replaceSpace(s);
    printf("%s", s);
    /*for (int i = 0; i < 9; i++)
        printf("%c", s[i]);*/
	return 0;
}