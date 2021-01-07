#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LuckPacket(vector<int>& vec, int pos, int sum, int mul)
{
    int count = 0;
    // 每一个位置上的组合都要求一次
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
        // 剪枝，防止重复的组合
        while (i < vec.size() - 1 && vec[i] == vec[i + 1])
            i++;
        // 进行下一个组合时，减去当前的值
        // 这里每一次循环相当于把一个值的每种组合都试一次，然后去掉当前节点，去试下一个节点的值的各种组合
        // 例如，1123。先把1的所有组合试一遍：1123,12,13，之后再试2节点
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