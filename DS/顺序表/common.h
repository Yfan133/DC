#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
#pragma warning(disable:4996)
#define ElemType int
void Swap(ElemType* a, ElemType* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

#endif "_COMMON_H_"

