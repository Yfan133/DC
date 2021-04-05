#pragma once
#include <iostream>
#include <vector>
using namespace std;

// �º������Ӽ�ֵ���л�ȡkey
template <class K>
struct KofV
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

// ��ϣ�ڵ㣨������
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

// ��ϣ��
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
		// �������
		checkCapacity();
		// ����λ��
		KofV kov;
		int index = kov(value) % _table.size();

		// ����
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_value) == value)
				return false;
			cur = cur->_next;
		}

		// ����ͷ��
		cur = new Node(value);
		
		cur->_next = _table[index];
		_table[index] = cur;

		++_size;
		return true;
	}

	void checkCapacity()
	{
		// �������� = ��ЧԪ�ظ��� / �������� = 1ʱ��Ҫ����
		if (_size == _table.size())
		{
			size_t newSize = 2 * _size;
			vector<Node*> newHt(newSize);
			
			KofV kov;
			// ����ԭ���飬�����нڵ����������
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// ����ɱ���һ��Ԫ��
					Node* next = cur->_next;

					// ���¼����±�λ�ã�����������±�
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