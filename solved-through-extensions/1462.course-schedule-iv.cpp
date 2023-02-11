/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */
#include "includes/leetcode.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries)
    {
        vector<vector<int>> adjList(n);

        for (auto it : prereq) {
            adjList[it[0]].push_back(it[1]);
        }

        stack<int> topoStack;
        vector<int> topoSorted;
        vector<bool> visited(n, false);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for (auto it : adjList[node]) {
                if (!visited[it]) {
                    dfs(it);
                }
            }

            topoStack.push(node);
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i);
        }

        while (!topoStack.empty()) {
            topoSorted.push_back(topoStack.top());
            topoStack.pop();
        }
    }
};
// @lc code=end
