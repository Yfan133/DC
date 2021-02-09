#pragma once

#include <iostream>
#include <vector>
using namespace std;

// 哈希桶就是一串串链表
template <class T>
struct HashNode
{
	HashNode(const T& data = T())
		:next(nullptr), val_(data)
	{}
	HashNode<T>* next;
	T val_;
};

template <class T>
class HashBucket
{
	typedef HashNode<T> Node;
public:
	HashBucket(const size_t capacity = 10)
		:table_(capacity, nullptr), size_(0)
	{}
	bool InsertUnique(const T& data)
	{
		// 1.找到对应桶号
		// 2.检查是否重复
		// 3.选择头插
		size_t HashNo = HashFunc(data);
		Node* cur = table_[HashNo];
		while (cur)
		{
			if (cur->val_ == data)
				return false;
			cur = cur->next;
		}
		cur = new Node(data);
		cur->next = table_[HashNo];
		table_[HashNo] = cur;
		return true;
	}
	bool InsertEqual(const T& data)
	{
		// 1.找到对应桶号
		size_t HashNo = HashFunc(data);
		// 2.直接头插
		Node* cur = new Node(data);
		cur->next = table_[HashNo];
		table_[HashNo] = cur;
		return true;
	}
	Node* Find(const T& data)const
	{
		// 1.找到对应桶号
		size_t HashNo = HashFunc(data);
		// 2.查找值相同的节点
		Node* cur = table_[HashNo];
		while (cur)
		{
			if (cur->val_ == data)
			{
				return cur;
			}
			else
			{
				cur = cur->next;
			}
		}
		return nullptr;
	}
	void Show()const 
	{
		// 1.依次打印每个桶号的链表
		for (size_t i = 0; i < table_.size(); i++)
		{
			printf("[%d]：", i);
			Node* cur = table_[i];
			while (cur)
			{
				cout << cur->val_ << "->";
				cur = cur->next;
			}
			cout << "nullptr" << endl;
		}
		cout << endl;
	}
	size_t EraseUnique(const T& data)
	{
		// 1.找到对应桶号
		size_t HashNo = HashFunc(data);
		// 2.通过桶号找到节点
		Node* cur = table_[HashNo];
		Node* prev = nullptr;
		while (cur)
		{
			if (cur->val_ == data)
			{
				if (prev == nullptr)
					table_[HashNo] = cur->next;
				else
					prev->next = cur->next;
				delete cur;
				cur = nullptr;
				return 1;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		return 0;
	}
	size_t EraseEqual(const T& data)
	{
		// 1.找到对应桶号
		size_t HashNo = HashFunc(data);
		size_t Countdel = 0;
		// 2.找到值相同的节点
		Node* cur = table_[HashNo];
		Node* prev = nullptr;
		// 3.删除节点
		while (cur)
		{
			if (cur->val_ == data)
			{
				if (prev == nullptr)
				{
					table_[HashNo] = cur->next;
					delete cur;
					cur = table_[HashNo];
				}
				else
				{
					prev->next = cur->next;
					delete cur;
					cur = prev->next;
				}
				Countdel++;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		// 4.循环上面操作直到cur为空
		return Countdel;
	}
private:
	// 哈希函数：除留余数法
	size_t HashFunc(const T& data)const
	{
		return data % table_.size();
	}
private:
	vector<Node*> table_;
	size_t size_;
};
void TestHashBucket()
{
	HashBucket<int> hb(7);
	int arr[] = { 19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79, 19 };
	for (auto i : arr)
		hb.InsertEqual(i);
	hb.Show();
	size_t era = hb.EraseEqual(19);
	cout << era << endl;
	hb.Show();
}