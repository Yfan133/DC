/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre = nullptr, * head = nullptr;      //pre保存上次执行过的节点，head保存头结点
    void cycle(Node* root)      //对于搜索二叉树中序遍历就是递增的
    {
        if (root == nullptr)
            return;
        cycle(root->left);
        if (head == nullptr)
        {
            head = root;
            //head->left = root;
            //pre = root;
        }
        else
        {
            pre->right = root;
            root->left = pre;
            //head->left = root;        //这里代码冗余
            //pre = root;
        }
        pre = root;
        cycle(root->right);
    }
    Node* treeToDoublyList(Node* root)
    {
        if (root == nullptr)
            return nullptr;
        cycle(root);
        //head->left->right = head;
        head->left = pre;       //循环结束之后一定要把头尾相连
        pre->right = head;
        return head;
    }
};