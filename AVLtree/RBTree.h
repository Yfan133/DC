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
// 红黑树的迭代器
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
		return *this;	// this相当于一个内部的类对象指针，对this解引用就是类对象
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
	// 1.约定end是head的位置，begin是树中最小的位置
	void Increment()
	{
		// 1.找右子树的最小值
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
				pNode = pNode->left;
		}
		// 2.在父中找到大于节点的第一个节点
		else
		{
			Node* parent = pNode->parent;
			while (pNode == parent->right)
			{
				pNode = parent;
				parent = pNode->parent;
			}
			// 特殊情况：根结点没有右子树
			if (pNode->right != parent)
				pNode = parent;
		}
	}
	// 2.约定对end--，之后到树中值最大的节点处
	void Decrement()
	{
		// 1.已经在end的位置，对end--到最大节点处
		if (pNode->parent->parent == pNode && RED == pNode->color_)
			pNode = pNode->right;
		// 2.在左树中找最大的
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
	// 增加迭代器的方法
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
		// 1.根为空的情况
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
		_size++;
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
			// 违背性质3：连续为红
			if (root->parent->color_ == RED)
			{
				cout << root->parent->val_ << "和" << root->val_ << "连续为红" << endl;
				return false;
			}
		}
		// 违背性质4：其中路径黑节点个数不同
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
// 总结：插入时最多只需要旋转两次，因为