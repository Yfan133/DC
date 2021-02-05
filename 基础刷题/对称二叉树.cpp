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
    bool isSame(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL || left->val != right->val)
            return false;
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
            return true;
        return isSame(root->left, root->right);
    }
};
