class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target)
    {
        // �������,���start����target,ֱ�ӷ���
        if (start == target) {
            return true;
        }

        // ��������ߵĹ�ϵ
        unordered_map<int, vector<int>> myMap;
        vector<int> visit(n, 0); // �ж��Ƿ���ʹ�
        for (auto i = 0; i < graph.size(); ++i) {
            auto thisValue = graph[i];
            myMap[thisValue[0]].push_back(thisValue[1]);
        }

        visit[start] = 1; // ���,�Ѿ���������

        if (myMap.count(start) == 0) { // �����㵽�����κεط�,ֱ�ӷ���false
            return false;
        }

        // �����������
        for (auto i = 0; i < myMap[start].size(); ++i) {
            auto thisValue = myMap[start][i];
            if (visit[thisValue]) { // ���ʹ��Ľڵ㲻Ҫ�ٷ��ʣ�������ѭ��
                continue;
            }

            visit[thisValue] = 1;
            if (dfs(myMap, visit, thisValue, target)) {
                return true;
            }

            visit[thisValue] = 0; // ����
        }

        return false;

    }

private:
    bool dfs(unordered_map<int, vector<int>>& myMap, vector<int>& visit, int value, int target)
    {
        if (value == target) { // �ҵ�Ŀ��ֵ
            return true;
        }

        if (myMap.count(value) == 0) { // �����ڴδ˱�
            return false;
        }

        for (auto i = 0; i < myMap[value].size(); ++i) {
            auto thisValue = myMap[value][i];
            if (visit[thisValue]) {
                continue;
            }

            visit[thisValue] = 1;
            if (dfs(myMap, visit, thisValue, target)) {
                return true;
            }

            visit[thisValue] = 0; // ����
        }

        return false;
    }
};