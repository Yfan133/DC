/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //  三种情况：
 //  1.root比p，q都小，则在root右树中找
 //  2.root比p，q都大，则在root左树中找
 //  3.p和q不在同一分支内，则返回root
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root->val < p->val && root->val < q->val)               //实测递归效率最高
            return lowestCommonAncestor(root->right, p, q);         //超级返回，如果找到了一直返回到头！！
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // if (p->val > q->val)                                     //迭代法
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
        // if (root == nullptr || root == p || root == q)           //常规二叉树，找法
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