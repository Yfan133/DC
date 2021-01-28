#pragma once
#include <iostream>
using namespace std;

template<class T>
class AVLNode
{
public:
	AVLNode(const T& data = T())
		:left(nullptr)
		,right(nullptr)
		,parent(nullptr)
		,val(data)
		,bf_(0)
	{}
	AVLNode<T>* left;
	AVLNode<T>* right;
	AVLNode<T>* parent;
	T val;
	int bf_;
};
template<class T>
class AVLTree
{
	typedef AVLNode<T> Node;
public:
	AVLTree()
		:root_(nullptr)
	{}
	~AVLTree()
	{
		Destory(root_);
	}
	bool AVLinsert(const T& data)
	{
		// 1.找位置进行插入
		if (root_ == nullptr)
		{
			root_ = new Node(data);
			return true;
		}
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->val)
				cur = cur->left;
			else if (data > cur->val)
				cur = cur->right;
			else
				return false;
		}
		cur = new Node(data);
		if (data > parent->val)
			parent->right = cur;
		else
			parent->left = cur;

		cur->parent = parent;
		// 2.调整树的平衡
		while (parent)
		{
			// 1.调整插入父节点的平衡因子
			if (cur == parent->left)
				parent->bf_--;
			else
				parent->bf_++;
			// 2.判断父节点的平衡因子执行不同行为
			if (parent->bf_ == 0)
				break;
			else if (parent->bf_ == -1 || parent->bf_ == 1)
			{
				cur = parent;
				parent = parent->parent;
			}
			else //parent->bf_ == 2 huo -2，要通过旋转调整
			{
				if (parent->bf_ == -2)
				{
					// 右单旋
					if (-1 == cur->bf_)
					{
						RotateRight(parent);
					}
					// 左右双旋
					else
					{
						RotateLR(parent);
					}
				}
				else // parent->bf_ = 2
				{
					// 左单旋
					if (cur->bf_ == 1)
					{
						RotateLeft(parent);
					}
					// 右左双旋
					else
					{
						RotateRL(parent);
					}
				}
				break;
			}
		}
		return true;
	}
	void Inorder()
	{
		Inorder(root_);
		cout << endl;
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(root_);
	}
private:
	void Inorder(Node* root)
	{
		if (root)
		{
			Inorder(root->left);
			cout << root->val << " ";
			Inorder(root->right);
		}
	}
	void Destory(Node*& root)
	{
		if (root)
		{
			Destory(root->left);
			Destory(root->right);
			delete root;
			root == nullptr;
		}
	}
	void RotateRight(Node* parent)
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
		if (pp == nullptr)
		{
			root_ = subL;
		}
		else 
		{
			if (pp->left == parent)
				pp->left = subL;
			else
				pp->right = subL;
		}
		subL->bf_ = parent->bf_ = 0;
	}
	void RotateLeft(Node* parent)
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

		if (pp == nullptr)
		{
			root_ = subR;
		}
		else 
		{
			if (pp->left == parent)
				pp->left = subR;
			else
				pp->right = subR;
		}
		subR->bf_ = parent->bf_ = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->val;
		RotateLeft(parent->left);
		RotateRight(parent);
		if (bf == -1)
			parent->bf_ = 1;
		else
			subL->bf_ = -1;
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;
		int bf = subRL->bf_;
		RotateRight(parent->right);
		RotateLeft(parent);
		if (bf == -1)
			subR->bf_ = 1;
		else
			parent->bf_ = -1;
	}
	int High(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = High(root->left);
		int right = High(root->right);
		return left > right ? left + 1 : right + 1;
	}
	bool _IsBalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;
		int left = High(root->left);
		int right = High(root->right);
		int bf = right - left;
		if (abs(bf) > 1 || bf != root->bf_)
		{
			cout << "节点" << root->val << "的平衡因子出问题" << endl;
			return false;
		}
		return _IsBalanceTree(root->left) && _IsBalanceTree(root->right);
	}
private:
	AVLNode<T>* root_;
};
void TestAVLTree()
{
	AVLTree<int> an;
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto i : arr)
		an.AVLinsert(i);
	an.Inorder();
	an.IsBalanceTree();
}