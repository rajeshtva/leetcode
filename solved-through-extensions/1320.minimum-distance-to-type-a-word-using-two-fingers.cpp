/*
 * @lc app=leetcode id=1320 lang=cpp
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 */
#include "includes/leetcode.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumDistance(string word)
    {
        int n = word.size();
        vector<pair<int, int>> charPos(26);

        for (int i = 0; i < 26; i++) {
            int x = i / 6;
            int y = i % 6;
            charPos[i] = { x, y };
        }

        int memo[n + 2][n + 2][n + 2];
        memset(memo, -1, sizeof(memo));

        int ans = INT_MAX;

        for (int i = -1; i < n; i++) {
            for (int l = -1; l < n - 1; l++) {
                for (int r = -1; r < n - 1; r++) {
                    if (i <= -1) {
                        memo[i + 1][l + 1][r + 1] = 0;
                        continue;
                    }

                    int left = memo[i + 1][i + 1][r + 1];
                    int right = memo[i + 1][l + 1][i + 1];

                    int leftCost = 0, rightCost = 0;

                    auto iPos = charPos[word[i] - 'A'];

                    if (l >= 0) {
                        auto prevPosL = charPos[word[l] - 'A'];
                        leftCost = abs(iPos.first - prevPosL.first) + abs(iPos.second - prevPosL.second);
                    }

                    if (r >= 0) {
                        auto prevPosR = charPos[word[r] - 'A'];
                        rightCost = abs(iPos.first - prevPosR.first) + abs(iPos.second - prevPosR.second);
                    }

                    int value = min(left + leftCost, right + rightCost);

                    memo[i + 1][l + 1][r + 1] = value;

                    if (i == n - 1) {
                        ans = min(ans, value);
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end
