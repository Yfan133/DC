#include"test.h"
void main()
{
    char* s="1";
    if (s == NULL)
        printf("null");
    ++s;
    ++s;
    if (*s == '\0')
        printf("123");

   /* while (*s != '\0')
    {
        printf("%c", *s);
        s++;
    }*/
}
