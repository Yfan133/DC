#include"common.h"
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
    int res, k_;
    int kthLargest(TreeNode* root, int k)
    {
        if (root == nullptr)
            return -1;
        k_ = k;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->right);
        if (k_ == 0)
            return;
        if (--k_ == 0)
            res = root->val;
        dfs(root->left);
    }
};