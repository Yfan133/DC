class Solution {
public:
    void reOrderArray(vector<int>& array)
    {
        int l = 0, r = array.size() - 1;
        while (l < r)
        {
            while (l < r && array[l] % 2 == 1)    //����Ϊ��
                l++;
            if (array[l + 1] % 2 == 0)    //�����һ��ҲΪż����������
            {
                while (l < r && array[r] % 2 == 0)
                    r--;
                if ()
            }
            else    //��һ��Ϊ�������򽻻�����λ��
            {
                swap(array[l], array[l + 1]);
                l++;
            }
        }
    }
};
