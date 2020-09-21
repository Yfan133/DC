#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#include<memory.h>

void Swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
#endif // !_COMMON_H_

