class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)     //����������ѭ�����飬����λ�õ�ǰ���Ƿ��л���Ȼ��Ƚ����մ� 
    {
        int count = 0;
        int sz = flowerbed.size();
        for (int i = 0; i < sz; i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == sz - 1 || flowerbed[i + 1] == 0))    //�����λ�õ�ǰ���ǿյģ����ʾ��λ�ÿ����ֻ�
            {
                flowerbed[i] = 1;   //�ǵ��ֻ�֮��Ҫ�Ѹ�λ������Ϊ1
                count++;
            }
        }
        return count >= n;
    }
};
