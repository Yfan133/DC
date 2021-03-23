#include "HashTable.h"

HashTable::HashTable(ush size)
	: _prev(new ush[2 * size])
	, _head(_prev + size)
{}

HashTable::~HashTable()
{
	delete[] _prev;
	_head = _prev = nullptr;
}



// hashAddr：哈希地址
// ch:匹配字符的第三个
// pos：匹配字符首下标
// matchHead：上次匹配的位置
void HashTable::Insert(ush& hashAddr, uch ch, uch pos, ush& matchHead)
{
	HashFunc(hashAddr, ch);

	matchHead = _head[hashAddr];				// 保存上次匹配的位置
	_prev[pos & HASH_MASK] = _head[hashAddr];	// 将上次匹配移动到左边，解决冲突
	_head[hashAddr] = pos;						// 把新的字符串首地址放入右边(地址存储区)
}


// 哈希函数用于计算哈希地址
void HashTable::HashFunc(ush& hashAddr, ush ch)
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}
ush HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

ush HashTable::GetNext(ush& matchHead)
{
	return _prev[matchHead & HASH_MASK];
}