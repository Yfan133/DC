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
    int index = 0; //记录先序序列走到哪一步了
    TreeNode* build(vector<int>& vlr, vector<int>& lvr, int left, int right)
    {
        if (index == vlr.size() || left == right)
            return nullptr;
        TreeNode* res = nullptr;
        for (int k = left; k < right; k++)
        {
            if (vlr[index] == lvr[k]) //如果在 left 和 right 的区间找到了值
            {
                res = new TreeNode(vlr[index]);
                index++;            //应该计算的位置 ++
                res->left = build(vlr, lvr, left, k);
                res->right = build(vlr, lvr, k + 1, right);
                break;
            }
        }
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder, inorder, 0, preorder.size());
    }
};