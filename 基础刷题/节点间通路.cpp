class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target)
    {
        // 特殊情况,如果start就是target,直接返回
        if (start == target) {
            return true;
        }

        // 建立边与边的关系
        unordered_map<int, vector<int>> myMap;
        vector<int> visit(n, 0); // 判断是否访问过
        for (auto i = 0; i < graph.size(); ++i) {
            auto thisValue = graph[i];
            myMap[thisValue[0]].push_back(thisValue[1]);
        }

        visit[start] = 1; // 起点,已经被访问了

        if (myMap.count(start) == 0) { // 如果起点到不了任何地方,直接返回false
            return false;
        }

        // 深度优先搜索
        for (auto i = 0; i < myMap[start].size(); ++i) {
            auto thisValue = myMap[start][i];
            if (visit[thisValue]) { // 访问过的节点不要再访问，否则死循环
                continue;
            }

            visit[thisValue] = 1;
            if (dfs(myMap, visit, thisValue, target)) {
                return true;
            }

            visit[thisValue] = 0; // 回溯
        }

        return false;

    }

private:
    bool dfs(unordered_map<int, vector<int>>& myMap, vector<int>& visit, int value, int target)
    {
        if (value == target) { // 找到目标值
            return true;
        }

        if (myMap.count(value) == 0) { // 不存在次此边
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

            visit[thisValue] = 0; // 回溯
        }

        return false;
    }
};