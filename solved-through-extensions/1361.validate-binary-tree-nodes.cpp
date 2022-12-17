/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */
#include "includes/leetcode.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        vector<vector<int>> adjList(n);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1)
                adjList[i].push_back(leftChild[i]);

            if (rightChild[i] != -1)
                adjList[i].push_back(rightChild[i]);
        }

        vector<bool> visited(n, false);

        function<bool(int)> dfs = [&](int currentNode) -> bool {
            visited[currentNode] = true;

            for (auto it : adjList[currentNode]) {

                if (visited[it])
                    return true;

                if (dfs(it))
                    return true;
            }

            return false;
        };

        for (int i = 0; i < n; i++) {
            if (dfs(i))
                return false;
        }

        // node count check.
        for (int i = 0; i < n; i++) {
            if (adjList[i].size() >= 3)
                return false;
        }

        return true;
    }
};
// @lc code=end
