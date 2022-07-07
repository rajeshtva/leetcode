# 474. Ones and Zeroes 

[link](https://leetcode.com/problems/ones-and-zeroes/)
**Level**: Medium 


```cpp
class Solution {
public:
    int answer = 0;

    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<vector<int>>> mp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return g(strs, 0, m, n, 0, mp);
    }

    int g(vector<string>& strs, int i, int m, int n, int currentSize, vector<vector<vector<int>>>& dp)
    {
        int pick = 0, notPick = 0, zeroCount = 0, oneCount = 0;

        if ((m < 0 || n < 0))
            return 0;

        if (m == 0 && n == 0)
            return 0;

        if (i >= strs.size())
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        zeroCount = count(strs[i].begin(), strs[i].end(), '0');
        oneCount = strs[i].size() - zeroCount;

        notPick = g(strs, i + 1, m, n, currentSize, dp);

        if (m >= zeroCount && n >= oneCount)
            pick = 1 + g(strs, i + 1, m - zeroCount, n - oneCount, currentSize + 1, dp);

        dp[i][m][n] = max(notPick, pick);
        
        return max(pick, notPick);
    }
};
```

