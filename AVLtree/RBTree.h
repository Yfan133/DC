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
template <class T>
class BRTree
{
	typedef BRTreeNode<T> Node;
private:
	Node* head;
public:
	BRTree()
	{
		head = new Node;
		head->left = head;
		head->right = head;
		head->parent = nullptr;
	}
	~BRTree()
	{
		Destroy(GetRoot());
		delete head;
		head = nullptr;
	}
	bool Insert(const T& data)
	{
		Node*& root = GetRoot();
		// 1.根为空的情况
		if (root == nullptr)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->parent = root;
		}
		// 2.找到插入位置
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
		// 2.插入数据
		cur = new Node(data);
		if (data < parent->val_)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;
		// 3.调整树的结构
		while (parent != head && parent->color_ == RED)
		{
			Node* pp = parent->parent;
			if (parent == pp->left)
			{
				// 正向情况
				Node* uncle = pp->right;
				if (uncle && uncle->color_ == RED)
				{
					// 情况一：叔叔节点存在，且为红
					// 方法：叔叔和父节点变黑，gg变红，向上调整
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
						// 情况三：cur是parent的右子树(内侧)
						// 方法：转换成情况二
						// 具体：左旋，并交换 par 和 cur
						RotateLeft(parent);
						swap(parent, cur);
					}
					// 情况二：叔叔节点为空或者叔叔节点为黑色
					// 方法：交换 par 和 pp 的颜色，对pp进行右旋
					parent->color_ = BLACK;
					pp->color_ = RED;
					RotateRight(pp);
				}
			}
			else
			{
				// 反向情况
				Node* uncle = pp->left;
				if (uncle && uncle->color_ == RED)
				{
					// 情况一：叔叔节点存在，且为红
					// 方法：叔叔和父节点变黑，gg变红，向上调整
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
						// 情况三：cur是parent的左子树(内侧)
						// 方法：转换成情况二
						// 具体：右旋，并交换 par 和 cur
						RotateRight(parent);
						swap(parent, cur);
					}
					// 情况二：叔叔节点为空或者叔叔节点为黑色
					// 方法：交换 par 和 pp 的颜色，对pp进行左旋
					parent->color_ = BLACK;
					pp->color_ = RED;
					RotateLeft(pp);
				}
			}
		}
		root->color_ = BLACK;
		head->left = LeftMin();
		head->right = RightMax();
		return true;
	}
	bool IsVaildRBTree()
	{
		// 1.空树也是红黑树
		// 2.性质一：根节点为黑色
		// 3.性质二：不能有连续的红色
		// 4.性质三：黑色节点数量一样
		// 方法：先统计一条路径上的黑节点，再判断每条路径的黑节点是否相等
		Node* root = GetRoot();
		if (root == nullptr)
			return true;
		if (root->color_ != BLACK)
		{
			cout << "根节点不为黑" << endl;
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
			// 性质3
			if (root->parent->color_ == RED)
			{
				cout << root->parent->val_ << "和" << root->val_ << "连续为红" << endl;
				return false;
			}
		}
		// 性质4
		if (root->left == nullptr && root->right == nullptr)
		{
			if (pathBlack != countBlack)
			{
				cout << root->val_ << "路径黑色节点个数不同" << endl;
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
	BRTree<int> br;
	//int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto i : arr)
		br.Insert(i);
	br.Inorder();
	br.IsVaildRBTree();
}