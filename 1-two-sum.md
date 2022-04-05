# Two Sum

[link](https://leetcode.com/problems/two-sum/)
**Level**: Easy
**Memory Use**: 10.1mb(<94.81%)
**Time**: 56ms(<41.05%)

**Explanation**:
`find`: this method finds an elmeent in the vector and returns iterator to that element, and end pointer if not found,
`distance`: this method finds the index difference between two iterators of vector.

**Space complexity**: O(n^2)
**time complexity**: O(1)

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans = {};
        for (int i = 0; i < nums.size(); i++)
        {
            int alt = target - nums[i];

            auto itr = find(nums.begin() + i + 1, nums.end(), alt);

            if (itr != nums.end())
            {
                ans.push_back(i);
                ans.push_back(distance(nums.begin(), itr));
            }
        }

        return ans;
    }
};



```
