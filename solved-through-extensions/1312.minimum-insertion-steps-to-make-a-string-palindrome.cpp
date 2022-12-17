/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */
#include "includes/leetcode.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minInsertions(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.length();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                memo[i][j] = s[i - 1] == t[j - 1]
                    ? memo[i - 1][j - 1] + 1
                    : max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return s.length() - memo[n][n];
    }
};
// @lc code=end
