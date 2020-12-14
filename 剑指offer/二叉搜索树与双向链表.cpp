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
    Node* pre = nullptr, * head = nullptr;      //pre�����ϴ�ִ�й��Ľڵ㣬head����ͷ���
    void cycle(Node* root)      //������������������������ǵ�����
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
            //head->left = root;        //�����������
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
        head->left = pre;       //ѭ������֮��һ��Ҫ��ͷβ����
        pre->right = head;
        return head;
    }
};