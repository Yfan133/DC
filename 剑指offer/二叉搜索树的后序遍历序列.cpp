class Solution {
public:
    bool lrv(vector<int>& vc, int l, int r)     //后序遍历，每个子树的根节点都在这个序列的最后！根据这个特性划分数组
    {
        if (l == r)      //如果检查完毕，则返回true
            return true;
        int p = l;
        while (p < r - 1 && vc[p] < vc[r - 1])   //寻找分界线
            p++;
        int m = p;
        while (p < r - 1 && vc[p] > vc[r - 1])   //判断这棵二叉树的正确性，即右树全部大于根结点！
            p++;
        if (p != r - 1)
            return false;
        return lrv(vc, l, m) && lrv(vc, m, r - 1);
    }
    bool verifyPostorder(vector<int>& postorder)
    {
        return lrv(postorder, 0, postorder.size());
    }
};