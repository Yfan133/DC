/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) //������ǰ���ǣ�ÿ����ֵ������ͬ������һ�����й�������
    {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        //����������ڽ���ҹ�������
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)   //���leftΪ���򷵻���
            return right;
        if (right == nullptr)  //���rightΪ���򷵻���
            return left;
        return root;        //������Ҷ������򷵻ص�ǰ��root���Ѿ��ҵ��������ȣ�������
    }
};