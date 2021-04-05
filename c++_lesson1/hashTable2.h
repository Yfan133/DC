#pragma once
#include <iostream>
#include <vector>
using namespace std;

// 仿函数：从键值对中获取key
template <class K>
struct KofV
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

// 哈希节点（单链表）
template <class T>
struct HashNode
{
	T _value;
	HashNode<T>* _next;

	HashNode(const T& value = T())
		:_value(value)
		, _next(nullptr)
	{}
};

// 哈希表
template <class K, class V, class KofV>
class HashTable
{
	typedef HashNode<V> Node;
public:
	HashTable(size_t size = 5)
		:_table(size)
		, _size(0)
	{}
	bool Insert(const V& value)
	{
		// 检查容量
		checkCapacity();
		// 计算位置
		KofV kov;
		int index = kov(value) % _table.size();

		// 查重
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_value) == value)
				return false;
			cur = cur->_next;
		}

		// 进行头插
		cur = new Node(value);
		
		cur->_next = _table[index];
		_table[index] = cur;

		++_size;
		return true;
	}

	void checkCapacity()
	{
		// 负载因子 = 有效元素个数 / 数组容量 = 1时需要扩容
		if (_size == _table.size())
		{
			size_t newSize = 2 * _size;
			vector<Node*> newHt(newSize);
			
			KofV kov;
			// 遍历原数组，将所有节点插入新数组
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// 保存旧表下一个元素
					Node* next = cur->_next;

					// 重新计算新表位置，并将其插入新表
					int index = kov(cur->_value) % newHt.size();
					cur->_next = newHt[index];
					newHt[index] = cur;

					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newHt);
		}
	}

	Node* find(const K& key)
	{
		if (_table.size() == 0)
			return nullptr;
		
		int index = key % _table.size();
		Node* cur = _table[index];
		KofV kov;
		while (cur)
		{
			if (kov(cur->_value) == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		int index = key % _table.size();

		Node* cur = _table[index];
		Node* prev = nullptr;
		KofV kov;
		while (cur)
		{
			if (kov(cur->_value) == key)
			{
				if (prev == nullptr)
					_table[index] = cur->_next;
				else
				{
					prev->_next = cur->_next;
				}
				delete cur;
				--_size;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}
private:
	vector<Node*> _table;
	size_t _size;
};