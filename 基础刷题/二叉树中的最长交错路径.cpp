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
        if (flag)    //如果flag为1 则走左边有加成！
        {
            if (root->left)
                longest(root->left, 0, len + 1);    //走完左边走右边
            if (root->right)
                longest(root->right, 1, 1);         //走右边则置1    
        }
        else
        {
            if (root->right)
                longest(root->right, 1, len + 1);    //走完左边走右边
            if (root->left)
                longest(root->left, 0, 1);         //走右边则置1    
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
