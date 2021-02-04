#pragma once
#include <iostream>
using namespace std;
enum Color
{
	RED,
	BLACK
};
template <class T>
struct BRTreeNode
{
	BRTreeNode(const T& x = T(), Color c = RED)
		:val_(x)
		,color_(c)
		,left(nullptr)
		,right(nullptr)
		,parent(nullptr)
	{}
	T val_;
	Color color_;
	BRTreeNode<T>* left;
	BRTreeNode<T>* right;
	BRTreeNode<T>* parent;
};
// ������ĵ�����
template <class T>
struct RBTreeIterator
{
	typedef BRTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
	RBTreeIterator(Node* node = nullptr)
		:pNode(node)
	{}
	// RBTreeIterator(const Self& S){pNode = s->pNode;}
	T& operator*()
	{
		return pNode->val_;
	}
	T* operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		Increment();
		return *this;	// this�൱��һ���ڲ��������ָ�룬��this�����þ��������
	}
	Self operator++(int)
	{
		Self tmp(*this);
		Increment();
		return tmp;
	}
	Self& operator--()
	{
		Decrement();
		return *this;
	}
	Self& operator--(int)
	{
		Self tmp(*this);
		Decrement();
		return tmp;
	}
	bool operator!=(const Self& s)const
	{
		return pNode != s.pNode;
	}
	bool operator==(const Self& s)const
	{
		return pNode == s.pNode;
	}
private:
	// 1.Լ��end��head��λ�ã�begin��������С��λ��
	void Increment()
	{
		// 1.������������Сֵ
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
				pNode = pNode->left;
		}
		// 2.�ڸ����ҵ����ڽڵ�ĵ�һ���ڵ�
		else
		{
			Node* parent = pNode->parent;
			while (pNode == parent->right)
			{
				pNode = parent;
				parent = pNode->parent;
			}
			// ��������������û��������
			if (pNode->right != parent)
				pNode = parent;
		}
	}
	// 2.Լ����end--��֮������ֵ���Ľڵ㴦
	void Decrement()
	{
		// 1.�Ѿ���end��λ�ã���end--�����ڵ㴦
		if (pNode->parent->parent == pNode && RED == pNode->color_)
			pNode = pNode->right;
		// 2.��������������
		else if (pNode->left)
		{
			pNode = pNode->left;
			while (pNode->right)
				pNode = pNode->right;
		}
		else
		{
			Node* parent = pNode->parent;
			while (pNode == parent->left)
			{
				pNode = parent;
				parent = pNode->parent;
			}
			pNode = parent;
		}
	}
private:
	Node* pNode;
};

template <class T>
class BRTree
{
private:
	typedef BRTreeNode<T> Node;
	Node* head;
	size_t _size;
public:
	typedef RBTreeIterator<T> iterator;
	BRTree()
	{
		head = new Node;
		head->left = head;
		head->right = head;
		head->parent = nullptr;
		_size = 0;
	}
	~BRTree()
	{
		Destroy(GetRoot());
		delete head;
		head = nullptr;
	}
	///////////////////////////////////////////////////////////
	// ���ӵ������ķ���
	iterator begin()
	{
		return iterator(head->left);
	}
	iterator end()
	{
		return iterator(head);
	}
	bool empty()
	{
		return head->parent == nullptr;
	}
	size_t size()
	{
		return _size;
	}
	///////////////////////////////////////////////////////////
	bool Insert(const T& data)
	{
		Node*& root = GetRoot();
		// 1.��Ϊ�յ����
		if (root == nullptr)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->parent = root;
			head->left = root;
			head->right = root;
			_size = 1;
			return true;
		}
		// 2.�ҵ�����λ��
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->val_)
				cur = cur->left;
			else if (data > cur->val_)
				cur = cur->right;
			else
				return false;
		}
		// 2.��������
		cur = new Node(data);
		if (data < parent->val_)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;
		// 3.�������Ľṹ
		while (parent != head && parent->color_ == RED)
		{
			Node* pp = parent->parent;
			if (parent == pp->left)
			{
				// �������
				Node* uncle = pp->right;
				if (uncle && uncle->color_ == RED)
				{
					// ���һ������ڵ���ڣ���Ϊ��
					// ����������͸��ڵ��ڣ�gg��죬���ϵ���
					parent->color_ = BLACK;
					uncle->color_ = BLACK;
					pp->color_ = RED;
					cur = pp;
					parent = cur->parent;
				}
				else
				{
					if (cur == parent->right)
					{
						// �������cur��parent��������(�ڲ�)
						// ������ת���������
						// ���壺������������ par �� cur
						RotateLeft(parent);
						swap(parent, cur);
					}
					// �����������ڵ�Ϊ�ջ�������ڵ�Ϊ��ɫ
					// ���������� par �� pp ����ɫ����pp��������
					parent->color_ = BLACK;
					pp->color_ = RED;
					RotateRight(pp);
				}
			}
			else
			{
				// �������
				Node* uncle = pp->left;
				if (uncle && uncle->color_ == RED)
				{
					// ���һ������ڵ���ڣ���Ϊ��
					// ����������͸��ڵ��ڣ�gg��죬���ϵ���
					parent->color_ = BLACK;
					uncle->color_ = BLACK;
					pp->color_ = RED;
					cur = pp;
					parent = cur->parent;
				}
				else
				{
					if (cur == parent->left)
					{
						// �������cur��parent��������(�ڲ�)
						// ������ת���������
						// ���壺������������ par �� cur
						RotateRight(parent);
						swap(parent, cur);
					}
					// �����������ڵ�Ϊ�ջ�������ڵ�Ϊ��ɫ
					// ���������� par �� pp ����ɫ����pp��������
					parent->color_ = BLACK;
					pp->color_ = RED;
					RotateLeft(pp);
				}
			}
		}
		root->color_ = BLACK;
		head->left = LeftMin();
		head->right = RightMax();
		_size++;
		return true;
	}
	bool IsVaildRBTree()
	{
		// 1.����Ҳ�Ǻ����
		// 2.����һ�����ڵ�Ϊ��ɫ
		// 3.���ʶ��������������ĺ�ɫ
		// 4.����������ɫ�ڵ�����һ��
		// ��������ͳ��һ��·���ϵĺڽڵ㣬���ж�ÿ��·���ĺڽڵ��Ƿ����
		Node* root = GetRoot();
		if (root == nullptr)
			return true;
		if (root->color_ != BLACK)
		{
			cout << "���ڵ㲻Ϊ��" << endl;
			return false;
		}
		size_t countblack = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->color_ == BLACK)
				countblack++;
			cur = cur->left;
		}
		return _IsVaildRBTree(root, countblack, 0);
	}
	void Inorder()
	{
		InOrder(GetRoot());
		cout << endl;
	}
private:
	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->val_ << " ";
			InOrder(root->right);
		}
	}
	bool _IsVaildRBTree(Node* root, const size_t& countBlack, size_t pathBlack)
	{
		if (root == nullptr)
			return true;
		if (root->color_ == BLACK)
			pathBlack++;
		else
		{
			// Υ������3������Ϊ��
			if (root->parent->color_ == RED)
			{
				cout << root->parent->val_ << "��" << root->val_ << "����Ϊ��" << endl;
				return false;
			}
		}
		// Υ������4������·���ڽڵ������ͬ
		if (root->left == nullptr && root->right == nullptr)
		{
			if (pathBlack != countBlack)
			{
				cout << root->val_ << "·����ɫ�ڵ������ͬ" << endl;
				return false;
			}
			return true;
		}
		return _IsVaildRBTree(root->left, countBlack, pathBlack) && 
			_IsVaildRBTree(root->right, countBlack, pathBlack);
	}
	Node* LeftMin()
	{
		Node* root = GetRoot();
		if (root == nullptr)
			return nullptr;
		while (root->left)
		{
			root = root->left;
		}
		return root;
	}
	Node* RightMax()
	{
		Node* root = GetRoot();
		if (root == nullptr)
			return nullptr;
		while (root->right)
		{
			root = root->right;
		}
		return root;
	}
	Node*& GetRoot()
	{
		return head->parent;
	}
	void Destroy(Node*& root)
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}
	bool RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;
		subR->left = parent;

		Node* pp = parent->parent;
		parent->parent = subR;
		subR->parent = pp;
		if (pp == head)
		{
			head->parent = subR;
		}
		else
		{
			if (pp->left == parent)
				pp->left = subR;
			else
				pp->right = subR;
		}
		return true;
	}
	bool RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;
		subL->right = parent;

		Node* pp = parent->parent;
		parent->parent = subL;
		subL->parent = pp;
		if (pp == head)
		{
			head->parent = subL;
		}
		else
		{
			if (pp->left == parent)
				pp->left = subL;
			else
				pp->right = subL;
		}
		return true;
	}
};
void TestRBTree()
{
	BRTree<int> brt;
	//int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int arr[] = { 16 };
	for (auto i : arr)
		brt.Insert(i);
	brt.IsVaildRBTree();
	brt.Inorder();
	RBTreeIterator<int> it = brt.begin();
	while (it != brt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl << brt.size();
}
// �ܽ᣺����ʱ���ֻ��Ҫ��ת���Σ���Ϊ