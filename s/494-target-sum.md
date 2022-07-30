#

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

- use recursion to check for all possibilities.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
    int currentSum = 0;
    int output;
    vector<int> nums;
    int target;
    vector<char> operations;

public:
    void findAnswer(int i)
    {
        if (i == nums.size()) {
            if (currentSum == target) {
                output++;
            }
            return;
        }

        if (i > nums.size())
            return;

        for (char ch : operations) {
            if (ch == '+') {
                currentSum += nums[i];
                findAnswer(i + 1);
                currentSum -= nums[i];
            } else {
                currentSum -= nums[i];
                findAnswer(i + 1);
                currentSum += nums[i];
            }
        }
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        this->nums = nums;
        this->target = target;
        this->operations = { '+', '-' };

        this->output = 0;

        findAnswer(0);

        return output;
    }
};

```

## Dynamic programming approach.

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;

        for (int a : nums) {
            sum += a;
        }

        map<pair<int, int>, int> dp;

        int a = t(nums, 0, target, dp);
        return a;
    }

    int t(vector<int>& nums, int i, int target, map<pair<int, int>, int>& dp)
    {
        int minus = 0, plus = 0;

        if (target == 0 && (i == nums.size())) {
            return 1;
        }

        if (i >= nums.size())
            return 0;

        auto itr = dp.find({ i, target });

        if (itr != dp.end())
            return itr->second;

        minus = t(nums, i + 1, target + nums[i], dp);
        plus = t(nums, i + 1, target - nums[i], dp);

        dp[{ i, target }] = minus + plus;

        return minus + plus;
    }
};
```
