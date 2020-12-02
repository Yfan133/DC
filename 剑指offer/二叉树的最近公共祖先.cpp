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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) //这个题的前提是，每个数值都不相同，并且一定会有公共祖先
    {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        //后序遍历用于解决找公共祖先
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)   //如果left为空则返回右
            return right;
        if (right == nullptr)  //如果right为空则返回左
            return left;
        return root;        //如果左右都不空则返回当前的root，已经找到公共祖先！！！！
    }
};