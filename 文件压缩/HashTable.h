#pragma once

#include "Common.h"
class HashTable
{
public:
	HashTable(ush size);
	~HashTable();
	
	void Insert(ush& hashAddr, uch ch, uch pos, ush& matchHead);
	ush GetNext(ush& matchHead);
private:
	void HashFunc(ush& hashAddr, ush ch);
	ush H_SHIFT();
private:
	ush* _prev;
	ush* _head;

	// ��ϣͰ����Ϊ 2^15
	const static ush HASH_BITS = 15;
	// ��ϣ��Ĵ�С
	const static ush HASH_SIZE = (1 << HASH_BITS);
	// ��ϣ���룺��Ҫ�����ǽ��Ҵ��������󴰰���ʱ�����¹�ϣ��������λ��(��ֹԽ��head��)
	const ush HASH_MASK = HASH_SIZE - 1;
};