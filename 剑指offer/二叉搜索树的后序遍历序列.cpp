class Solution {
public:
    bool lrv(vector<int>& vc, int l, int r)     //���������ÿ�������ĸ��ڵ㶼��������е���󣡸���������Ի�������
    {
        if (l == r)      //��������ϣ��򷵻�true
            return true;
        int p = l;
        while (p < r - 1 && vc[p] < vc[r - 1])   //Ѱ�ҷֽ���
            p++;
        int m = p;
        while (p < r - 1 && vc[p] > vc[r - 1])   //�ж���ö���������ȷ�ԣ�������ȫ�����ڸ���㣡
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