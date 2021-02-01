/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int index = 0;
    TreeNode* Bintree(vector<int>& pre, vector<int>& vin, int l, int r)
    {
        if (index == pre.size() || l >= r)
            return nullptr;
        TreeNode* res = nullptr;
        for (int i = l; i < r; i++)
        {
            if (pre[index] == vin[i])
            {
                res = new TreeNode(pre[index]);
                ++index;
                res->left = Bintree(pre, vin, l, i);
                res->right = Bintree(pre, vin, i + 1, r);
                break;
            }
        }
        return res;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return Bintree(pre, vin, 0, pre.size());
    }
};
