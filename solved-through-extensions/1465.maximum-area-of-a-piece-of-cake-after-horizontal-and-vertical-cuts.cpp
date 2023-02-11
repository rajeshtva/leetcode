/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */
#include "includes/leetcode.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int horDiff = horizontalCuts[0];
        int verDiff = verticalCuts[0];
        int M = 1e9 + 7;

        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        int n = horizontalCuts.size();
        int m = verticalCuts.size();

        for (int i = 1; i < n; i++)
            horDiff = max(horDiff, horizontalCuts[i] - horizontalCuts[i - 1]);

        for (int i = 1; i < m; i++)
            verDiff = max(verDiff, verticalCuts[i] - verticalCuts[i - 1]);

        return (verDiff * horDiff * 1ll) % M;
    }
};
// @lc code=end
