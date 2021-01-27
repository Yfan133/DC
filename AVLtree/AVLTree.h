#pragma once
template<class T>
class AVLNode
{
public:
	AVLNode(T data = T())
		:left(nullptr)
		,right(nullptr)
		,parent(nullptr)
		,val(data)
		,bf_(0)
	{}
	AVLNode* left;
	AVLNode* right;
	AVLNode* parent;
	T val;
	int bf_;
};
template<class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	AVLTree()
		:root_(nullptr)
	{}
	bool AVLinsert(T data)
	{
		// 1.找位置进行插入
		if (root_ == nullptr)
		{
			root_ = new Node(data);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur)
		{
			parent = cur;
			if (data > cur->val)
				cur = cur->right;
			else
				cur = cur->left;
		}
		Node* cur = new Node(data);
		if (data > parent->val)
			parent->right = cur;
		else
			parent->left = cur;
		cur->parent = parent;
		// 2.调整树的平衡
		while (parent != nullptr)
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
					if (cur->bf_ > 0)
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
private:
	void RotateRight(Node* parent)
	{
		Node* cur = parent->left;
		Node* subLR = cur->right;
		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;
		cur->right = parent;
		Node* pp = parent->parent;
		cur->parent = pp;
		parent->parent = cur;
		if (nullptr == pp)
		{
			root_ = cur;
		}
		else
		{
			if (parent == pp->left)
				pp->left = cur;
			else
				pp->right = cur;
		}
		parent->bf_ = 0;
		cur->bf_ = 0;
	}
	void RotateLeft(Node* parent)
	{
		Node* cur = parent->right;
		Node* subRL = cur->left;
		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;
		cur->left = parent;
		Node* pp = parent->parent;
		cur->parent = pp;
		parent->parent = cur;
		if (nullptr == pp)
		{
			root_ = cur;
		}
		else
		{
			if (pp->left = parent)
				pp->left = cur;
			else
				pp->right = cur;
		}
		parent->bf_ = 0;
		cur->bf_ = 0;
	}
	void RotateLR(Node* parent)
	{
		RotateLeft(parent->left);
		RotateRight(parent);
	}
	void RotateRL(Node* parent)
	{
		RotateRight(parent->right);
		Rotateleft(parent);
	}
private:
	AVLNode<T>* root_;
};