/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 */
#include "includes/leetcode.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int palindromePartition(string s, int k)
    {
        int ans = INT_MAX;
        function<int(string, int, int, int)> dfs = [&](string str, int i, int j, int total) -> int {
            for (int k = i; k <= j - 1; k++) {
                string a = str.substr(i, k-i+1);
                string b = str.substr(k+1);

                for(int l = 1; l <= total; l++){

                }
            }
        };
    }
};
// @lc code=end
