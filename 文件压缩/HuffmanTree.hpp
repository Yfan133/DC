#pragma once
#include <queue>

template <class T>
struct HuffmanNode		// 哈夫曼树节点类型
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
class HuffmanTree		// 哈夫曼树
{
	typedef HuffmanNode<T> Node;
	// 自定义比较方法
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
	// 创建哈夫曼树
	Node* CreateTree(std::vector<T>& vec)
	{
		// 1.遍历数组元素构建 N 颗根节点，将 N 颗树保存到小堆中
		std::priority_queue<Node*, std::vector<Node*>, Compare> Q;
		for (auto val : vec)
		{
			// 只构造元素出现频率不为 0 的元素
			// 动态构造一个匿名对象，并插入小堆中
			if (!val)
				Q.push(new Node(val));
		}
		// 2.每次从小堆中取两个最小的元素构建一颗新树，根节点为两个值的和
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
		// 3.当堆中只剩下一颗树时，哈夫曼树就构造完成了
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