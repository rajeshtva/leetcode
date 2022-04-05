# Trapng rain water
[link](https://leetcode.com/problems/trapping-rain-water/submissions/)
**Level**: Hard
**Memory Use**: 18.9mb(>5.11%)
**Time**: 12ms(>83.42%)

**Explanation**:
we have to know at every step what is maximum height of wall from both side. which is made available through `leftMax` and `rightMax` variables.

**Space complexity**: O(n)
**time complexity**: O(n)

```cpp

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<long long> leftMax(height.size());
        vector<long long> rightMax(height.size());

        // maximum from left side
        int max = height[0];
        leftMax[0] = height[0];

        // for left side
        for (int i = 1; i < height.size(); i++)
        {
            if (max <= height[i])
            {
                max = height[i];
            }

            leftMax[i] = max;
        }

        // for right side:
        max = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (max <= height[i])
            {
                max = height[i];
            }
            rightMax[i] = max;
        }

        // calculating rain water stoage.
        long long rainWaterStorage = 0;
        for (int i = 0; i < height.size(); i++)
        {
            rainWaterStorage += min(rightMax[i], leftMax[i]) - height[i];
        }

        return rainWaterStorage;
    }
};
```
