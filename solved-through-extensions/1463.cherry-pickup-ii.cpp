/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));

        function<int(int, int, int)> f = [&](int r, int c1, int c2) -> int {
            if (r >= n)
                return 0;

            if (memo[r][c1][c2] != -1)
                return memo[r][c1][c2];

            vector<int> cols = { -1, 0, 1 };
            int maxCherry = 0;
            int posGain = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
            int temp = 0;

            for (int j1 = 0; j1 < 3; j1++) {
                for (int j2 = 0; j2 < 3; j2++) {
                    int col1 = c1 + cols[j1];
                    int col2 = c2 + cols[j2];

                    if (0 <= col1 && col1 < m && 0 <= col2 && col2 < m) {
                        temp = f(r + 1, col1, col2);
                        maxCherry = max(maxCherry, temp);
                    }
                }
            }

            return memo[r][c1][c2] = maxCherry + posGain;
        };

        return f(0, 0, m - 1);
    }
};


// @lc code=end

