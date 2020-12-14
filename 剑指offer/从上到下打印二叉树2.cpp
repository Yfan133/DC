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
                    node = bfs.front(); //ż����:ǰ�����, ������(��Ϊ��һ����Ҫ���ҵ����������)
                    bfs.pop_front();
                    if (node->left) bfs.push_back(node->left);
                    if (node->right) bfs.push_back(node->right);
                }
                else {  //������:���ǰ��, ���ҵ��� (��Ϊ��һ����Ҫ�����Ҽ�������)
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