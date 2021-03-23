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



// hashAddr����ϣ��ַ
// ch:ƥ���ַ��ĵ�����
// pos��ƥ���ַ����±�
// matchHead���ϴ�ƥ���λ��
void HashTable::Insert(ush& hashAddr, uch ch, uch pos, ush& matchHead)
{
	HashFunc(hashAddr, ch);

	matchHead = _head[hashAddr];				// �����ϴ�ƥ���λ��
	_prev[pos & HASH_MASK] = _head[hashAddr];	// ���ϴ�ƥ���ƶ�����ߣ������ͻ
	_head[hashAddr] = pos;						// ���µ��ַ����׵�ַ�����ұ�(��ַ�洢��)
}


// ��ϣ�������ڼ����ϣ��ַ
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