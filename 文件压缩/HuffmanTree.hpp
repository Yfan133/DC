#pragma once
#include <queue>

template <class T>
struct HuffmanNode		// ���������ڵ�����
{
	HuffmanNode(const T& val = T())
		: _val(val)
		, left(nullptr)
		, right(nullptr)
	{}
	T _val;
	HuffmanNode* left;
	HuffmanNode* right;
};

template <class T>
class HuffmanTree		// ��������
{
	typedef HuffmanNode<T> Node;
	// �Զ���ȽϷ���
	struct Compare
	{
		bool operator()(const Node* left, const Node* right)
		{
			return left->_val > right->_val;
		}
	};
public:
	HuffmanTree()
		: _root(nullptr)
	{}
	~HuffmanTree()
	{
		if (_root)
		{
			_Destory(_root);
		}
	}
	// ������������
	Node* CreateTree(std::vector<T>& vec)
	{
		// 1.��������Ԫ�ع��� N �Ÿ��ڵ㣬�� N �������浽С����
		std::priority_queue<Node*, std::vector<Node*>, Compare> Q;
		for (auto val : vec)
		{
			// ֻ����Ԫ�س���Ƶ�ʲ�Ϊ 0 ��Ԫ��
			// ��̬����һ���������󣬲�����С����
			if (!val)
				Q.push(new Node(val));
		}
		// 2.ÿ�δ�С����ȡ������С��Ԫ�ع���һ�����������ڵ�Ϊ����ֵ�ĺ�
		while (Q.size() > 1)
		{
			Node* left = Q.top();
			Q.pop();
			Node* right = Q.top();
			Q.pop();

			Node* root = new Node(left->_val + right->_val);
			root->left = left;
			root->right = right;
			Q.push(root);
		}
		// 3.������ֻʣ��һ����ʱ�����������͹��������
		_root = Q.top();
		return _root;
	}
private:
	void _Destory(Node* root)
	{
		if (root == nullptr)
			return;
		_Destory(root->left);
		_Destory(root->right);
		delete root;
		root = nullptr;
	}
private:
	Node* _root;
};