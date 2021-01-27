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
		// 1.��λ�ý��в���
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
		// 2.��������ƽ��
		while (parent != nullptr)
		{
			// 1.�������븸�ڵ��ƽ������
			if (cur == parent->left)
				parent->bf_--;
			else
				parent->bf_++;
			// 2.�жϸ��ڵ��ƽ������ִ�в�ͬ��Ϊ
			if (parent->bf_ == 0)
				break;
			else if (parent->bf_ == -1 || parent->bf_ == 1)
			{
				cur = parent;
				parent = parent->parent;
			}
			else //parent->bf_ == 2 huo -2��Ҫͨ����ת����
			{
				if (parent->bf_ == -2)
				{
					// �ҵ���
					if (-1 == cur->bf_)
					{
						RotateRight(parent);
					}
					// ����˫��
					else
					{
						RotateLR(parent);
					}
				}
				else // parent->bf_ = 2
				{
					// ����
					if (cur->bf_ > 0)
					{
						RotateLeft(parent);
					}
					// ����˫��
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