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

```
