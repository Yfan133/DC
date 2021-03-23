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

	// 哈希桶个数为 2^15
	const static ush HASH_BITS = 15;
	// 哈希表的大小
	const static ush HASH_SIZE = (1 << HASH_BITS);
	// 哈希掩码：主要作用是将右窗数据往左窗搬移时，更新哈希表中数据位置(防止越到head处)
	const ush HASH_MASK = HASH_SIZE - 1;
};