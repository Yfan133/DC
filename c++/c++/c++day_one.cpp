//�����ռ䶨���ʽ
#include<stdio.h>
namespace N
{
	int a = 10;
}
int a = 20;
int main()
{
	int a = 30;
	//::  �����������
	//::  ȫ�ֱ���
	//�����ռ�+ :: �����ռ��еĳ�Աʹ��
	printf("%d", ::a);
	return 0;
}