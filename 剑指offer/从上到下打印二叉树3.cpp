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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        int flag = 1;
        while (!que.empty())
        {
            int size = que.size();
            TreeNode* tmp;
            vector<int> vc;
            for (int i = 0; i < size; i++)
            {
                tmp = que.front();
                que.pop();
                if (tmp->left != nullptr)
                    que.push(tmp->left);
                if (tmp->right != nullptr)
                    que.push(tmp->right);
                vc.push_back(tmp->val);
            }
            if (flag % 2 == 0)
                reverse(vc.begin(), vc.end());
            res.push_back(vc);
            flag++;
        }
        return res;
    }
};