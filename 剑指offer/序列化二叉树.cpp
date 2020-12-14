/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return ""; // �п�
        }
        ostringstream out;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            // ������
            TreeNode* temp = bfs.front();
            bfs.pop();
            if (temp) {
                out << temp->val << " ";
                bfs.push(temp->left);
                bfs.push(temp->right);
            }
            else {
                out << "null "; // ע�� null �����пո�
            }
        }
        return out.str(); // out ��������ת���ַ�����Ԫ��֮���ÿո�ָ�
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr; // �п�
        }
        istringstream in(data);
        string info;
        vector<TreeNode*> res; // res �������ַ�����ÿ��Ԫ��ת�� TreeNode* ��ʽ��Ԫ��
        while (in >> info) {
            if (info == "null") { // ע�� null ����û�ո���Ϊ�ո��������ָ��ַ����ģ��������ַ�����
                res.push_back(nullptr);
            }
            else {
                res.push_back(new TreeNode(stoi(info)));
            }
        }
        int pos = 1;
        for (int i = 0; pos < res.size(); ++i) {
            // ��ѭ���� res �е�����Ԫ�������������һ�ö�����
            if (!res[i]) {
                continue;
            }
            res[i]->left = res[pos++]; // pos ��ʱָ����������++��ָ��������
            if (pos < res.size()) {
                res[i]->right = res[pos++]; // pos ��ʱָ����������++��ָ����һ���ڵ��������
            }
        }
        return res[0];
    }
};