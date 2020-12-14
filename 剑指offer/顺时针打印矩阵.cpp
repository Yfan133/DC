class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int left = 0, right = matrix[0].size() - 1, top = 0, btm = matrix.size() - 1;
        vector<int> res;
        while (left <= right && top <= btm)
        {
            for (int i = left; i <= right; i++)  //插入最上面一行
                res.push_back(matrix[top][i]);
            for (int i = top + 1; i <= btm; i++)        //插入右边一列
                res.push_back(matrix[i][right]);
            if (left != right && top != btm)     //如果最后是一层，则不打印了
            {
                for (int i = right - 1; i >= left; i--)
                    res.push_back(matrix[btm][i]);
                for (int i = btm - 1; i > top; i--)
                    res.push_back(matrix[i][left]);
            }
            ++left;
            --right;
            ++top;
            --btm;
        }
        return res;
    }
};