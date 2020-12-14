/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool ismir(TreeNode* L, TreeNode* R)
    {
        if (L == nullptr && R == nullptr)
            return true;
        if (L == nullptr || R == nullptr || L->val != R->val)
            return false;
        bool flag = ismir(L->left, R->right);
        if (!flag)
            return false;
        return ismir(L->right, R->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        return ismir(root->left, root->right);
    }
};