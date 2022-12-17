/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int MAX = 1e9;
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, MAX));

        vector<pair<int, int>> neighbours = { { 1, -1 }, { 1, 0 }, { 1, 1 } };

        function<int(int, int)> findAnswer = [&](int i, int j) -> int {
            if (i >= n)
                return 0;

            if (memo[i][j] != MAX)
                return memo[i][j];

            int maxValue = MAX;

            for (auto it : neighbours) {
                int x = i + it.first;
                int y = j + it.second;

                if (0 <= x && x < n && 0 <= y && y < m) {
                    maxValue = min(maxValue, findAnswer(x, y));
                }
            }

            if (maxValue == MAX)
                maxValue = 0;

            return memo[i][j] = maxValue + matrix[i][j];
        };

        int value = INT_MAX;
        for (int j = 0; j < m; j++) {
            value = min(value, findAnswer(0, j));
        }

        return value;
    }
};
// @lc code=end
