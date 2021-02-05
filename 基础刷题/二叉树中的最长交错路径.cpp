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
    int res = 0;
    void longest(TreeNode* root, int flag, int len)
    {
        res = max(res, len);
        if (flag)    //���flagΪ1 ��������мӳɣ�
        {
            if (root->left)
                longest(root->left, 0, len + 1);    //����������ұ�
            if (root->right)
                longest(root->right, 1, 1);         //���ұ�����1    
        }
        else
        {
            if (root->right)
                longest(root->right, 1, len + 1);    //����������ұ�
            if (root->left)
                longest(root->left, 0, 1);         //���ұ�����1    
        }
    }
    int longestZigZag(TreeNode* root)
    {
        if (root == NULL)
            return res;
        longest(root, 1, 0);
        longest(root, 0, 0);
        return res;
    }
};
