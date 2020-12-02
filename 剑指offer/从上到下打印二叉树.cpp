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
        queue<TreeNode*> st;
        TreeNode* tmp = root;
        st.push(tmp);
        while (!st.empty())
        {
            vector<int> v;
            int size = st.size();
            for (int i = 0; i < size; i++)
            {
                tmp = st.front();
                st.pop();
                v.push_back(tmp->val);
                if (tmp->left != nullptr)
                    st.push(tmp->left);
                if (tmp->right != nullptr)
                    st.push(tmp->right);
            }
            res.push_back(v);
        }
        return res;
    }
};