#include"test.h"
void main()
{
    unsigned char tmp = 1;
    tmp <<= 4;
    unsigned char data = 123;
    printf("%d", data & (~tmp));
}
