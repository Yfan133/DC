#pragma once
#include <iostream>
#include <vector>
using namespace std;
enum state
{
	EMPTY,
	EXIST,
	DELETE
};
template <class K, class V>
struct HashNode
{
	pair<K, V> _value;
	state _state;

	HashNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		, _state(EMPTY)
	{}
};
template <class K, class V>
class HashTable
{
public:
	HashTable(size_t n = 10)
	{
		// 这里必须使用resize！
		_table.resize(n);
		_size = 0;
	}
	bool Insert(const pair<K, V>& value)
	{
		// 1.先检查容量
		checkCapacity();
		// 2.通过哈希函数计算位置
		int index = value.first % _table.size();
		// 3.找第一个空位置
		while (_table[index]._state == EXIST)
		{
			// 当前key值已存在
			if (_table[index]._value.first == value.first)
				return false;
			index = (index + 1) % _table.size();
		}
		_table[index]._value = value;
		_table[index]._state = EXIST;
		++_size;
		return true;
	}
	void checkCapacity()
	{
		// 1.计算负载因子
		if (_size * 10 / _table.size() >= 7)
		{
			HashTable ht(2 * _table.size());

			// 将旧表中元素插入新表
			for (int i = 0; i < _table.size(); ++i)
			{
				if (_table[i]._state == EXIST)
					ht.Insert(_table[i]._value);
			}
			swap(_table, ht._table);
		}
	}
	HashNode<K, V>* find(const K& key)
	{
		int index = key % _table.size();
		while (_table[index]._state == !EMPTY)
		{
			if (_table[index]._state == EXIST && _table[index]._value.first == key)
				return &_table[index];
			index = (index + 1) % _table.size();
		}
		return nullptr;
	}
	bool erase(const K& key)
	{
		HashNode<K, V>* ptr = find(key);
		if (ptr)
		{
			ptr->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}
private:
	vector<HashNode<K, V>> _table;
	size_t _size;
};

void TestHt()
{
	HashTable<int, int> ht;
	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(11, 1));
	ht.Insert(make_pair(21, 1));
	ht.Insert(make_pair(2, 1));
	ht.Insert(make_pair(9, 1));
	ht.Insert(make_pair(15, 1));
	ht.Insert(make_pair(13, 1));
	ht.Insert(make_pair(28, 1));
	ht.Insert(make_pair(72, 1));
	ht.Insert(make_pair(99, 1));
	ht.Insert(make_pair(56, 1));

	HashNode<int, int>* ptr = ht.find(99);
	cout << ptr->_value.first << "--->" << ptr->_value.second << endl;
	ptr = ht.find(100);
	cout << ptr << endl;

	bool ret = ht.erase(72);
	ret = ht.erase(35);
}