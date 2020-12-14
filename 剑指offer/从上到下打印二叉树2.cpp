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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> bfs;
        bool flag = true;
        if (root == nullptr) return ans;
        bfs.push_back(root);

        while (!bfs.empty()) {
            vector<int> temp;
            int size = bfs.size();
            TreeNode* node;
            for (int i = 0; i < size; i++) {
                if (flag) {
                    node = bfs.front(); //偶数层:前出后加, 从左到右(因为下一层是要从右到左加入数组)
                    bfs.pop_front();
                    if (node->left) bfs.push_back(node->left);
                    if (node->right) bfs.push_back(node->right);
                }
                else {  //奇数层:后出前加, 从右到左 (因为下一层是要从左到右加入数组)
                    node = bfs.back();
                    bfs.pop_back();
                    if (node->right) bfs.push_front(node->right);
                    if (node->left) bfs.push_front(node->left);
                }
                temp.push_back(node->val);
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};