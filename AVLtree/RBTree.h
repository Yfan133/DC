#pragma once
#include <iostream>

enum Color
{
	RED,
	BLACK
};
template <class T>
struct BRTreeNode
{
	BRTreeNode(const T& x = T(), Color c = RED)
		:left(nullptr)
		,right(nullptr)
		,parent(nullptr)
		,val_(x)
		, color_(c)
	{}
	BRTreeNode* left;
	BRTreeNode* right;
	BRTreeNode* parent;
	T val_;
	Color color_;
};
template <class T>
class BRTree
{
	typedef BRTreeNode<T> Node;
	BRTree()
	{
		head = new Node;
		head->left = head;
		head->right = head;
		head->parent = nullptr;
	}
	bool Insert(const T& data)
	{
		Node* root = GetRoot;
		// 1.找到插入位置
		if (root == nullptr)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->parent = root;
		}
		while (root)
		{
			if (root->val_ > data)
				root = root->left;
			else if (root->val_ < data)
				root = root->right;
			else
				return false;
		}
		// 2.插入数据
		Node* parent = root->parent;
		root = new Node(data);
		if (parent->val_ > data)
			parent->left = root;
		else
			parent->right = root;
		// 3.调整树的结构

	}
private:
	Node*& GetRoot()
	{
		return head->parent;
	}
private:
	Node* head;
};