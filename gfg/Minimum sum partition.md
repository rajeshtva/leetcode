# Minimum sum partition

Find the minimum difference between sum of elements of two subsets of array `arr` such that each element is either in s1 or s2.

```cpp
typedef long long ll;

class Solution {

public:
    int minDifference(int arr[], int n)
    {
        int range = accumulate(arr, arr + n, 0);
        vector<vector<int>> memo(n + 1, vector<int>(range + 1, -1));
        int half = range / 2;

        for (int j = 0; j <= range; j++)
            memo[0][j] = false;

        for (int i = 0; i <= n; i++)
            memo[i][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= range; j++) {
                memo[i][j] = j < arr[i - 1]
                    ? memo[i - 1][j]
                    : memo[i - 1][j] || memo[i - 1][j - arr[i - 1]];
            }
        }

        // this is for testing purpose only.
        vector<int> possibleSums;

        for (int j = 0; j <= half; j++) {
            if (memo[n][j] == true)
                possibleSums.push_back(j);
        }

        int ans = INT_MAX;

        for (int i = 0; i < possibleSums.size(); i++) {
            ans = min(ans, range - (2 * possibleSums[i]));
        }

        return ans;
    }
};
```
