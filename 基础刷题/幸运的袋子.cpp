#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LuckPacket(vector<int>& vec, int pos, int sum, int mul)
{
    int count = 0;
    // ÿһ��λ���ϵ���϶�Ҫ��һ��
    for (int i = pos; i < vec.size(); i++)
    {
        sum += vec[i];
        mul *= vec[i];
        if (sum > mul)
            count += 1 + LuckPacket(vec, i + 1, sum, mul);
        else if (vec[i] == 1)
            count = LuckPacket(vec, i + 1, sum, mul);
        else
            break;
        // ��֦����ֹ�ظ������
        while (i < vec.size() - 1 && vec[i] == vec[i + 1])
            i++;
        // ������һ�����ʱ����ȥ��ǰ��ֵ
        // ����ÿһ��ѭ���൱�ڰ�һ��ֵ��ÿ����϶���һ�Σ�Ȼ��ȥ����ǰ�ڵ㣬ȥ����һ���ڵ��ֵ�ĸ������
        // ���磬1123���Ȱ�1�����������һ�飺1123,12,13��֮������2�ڵ�
        sum -= vec[i];
        mul /= vec[i];
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& i : vec)
        cin >> i;
    sort(vec.begin(), vec.end());
    cout << LuckPacket(vec, 0, 0, 1) << endl;
    return 0;
}