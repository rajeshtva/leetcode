/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int n = cardPoints.size();

        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int s=0;
        int count = n - k;
        int ans = INT_MAX;

        if(count == 0) return sum;

        for(int i = 0; i<n;i++) {
            s += cardPoints[i];

            if(i >= count-1) {
                ans = min(s, ans);
                s = s-cardPoints[i-(count-1)];
            }
        }

        ans = ans == INT_MAX ? 0: ans;

        return sum-ans;
    }
};
// @lc code=end
