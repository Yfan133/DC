#ifndef __COMMON_H_
#define __COMMON_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<memory.h>
#pragma warning(disable:4996)
void Swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
typedef char BinTreeElemType;

#endif
