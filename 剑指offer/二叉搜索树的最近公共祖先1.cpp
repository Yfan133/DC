/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //  ���������
 //  1.root��p��q��С������root��������
 //  2.root��p��q��������root��������
 //  3.p��q����ͬһ��֧�ڣ��򷵻�root
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root->val < p->val && root->val < q->val)               //ʵ��ݹ�Ч�����
            return lowestCommonAncestor(root->right, p, q);         //�������أ�����ҵ���һֱ���ص�ͷ����
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // if (p->val > q->val)                                     //������
        //     swap (p, q);
        // while (root != nullptr)
        // {
        //     if (root->val < p->val)
        //         root = root->right;
        //     else if (root->val > q->val)
        //         root = root->left;
        //     else
        //         break;
        // }
        // if (root == nullptr || root == p || root == q)           //������������ҷ�
        //     return root;
        // TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // TreeNode* right = lowestCommonAncestor(root->right, p ,q);
        // if (left == nullptr)
        //     return right;
        // if (right == nullptr)
        //     return left;
        // return root;
        return root;
    }
};