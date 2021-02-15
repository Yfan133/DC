class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fRow[1000] = { 0 };
        int fCol[1000] = { 0 };
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    fRow[i]++;
                    fCol[j]++;
                }
            }
        }
        for (int k = 0; k < matrix.size(); k++)
        {
            if (fRow[k] != 0)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    matrix[k][j] = 0;
                }
            }
        }
        for (int l = 0; l < matrix[0].size(); l++)
        {
            if (fCol[l] != 0)
            {
                for (int m = 0; m < matrix.size(); m++)
                {
                    matrix[m][l] = 0;
                }
            }
        }
    }
};