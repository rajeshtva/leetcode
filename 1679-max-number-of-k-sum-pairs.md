# Max Number of K sum pairs

[link](https://leetcode.com/problems/max-number-of-k-sum-pairs/submissions/)
**Level**: Medium 

**Memory Use**:  67.6 MB

**Time**: 255 ms

**Explanation**:
-   based on hash map, solution

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> bucket;

        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i]]++;
        }

        int count = 0;

        for (auto itr = bucket.begin(); itr != bucket.end(); itr++) {
            int first = (*itr).first;
            int second = (*itr).second;

            if (first * 2 == k) {
                count += floor(second / 2);
            } else {
                if (bucket.find(k - first) != bucket.end())
                    count += min(bucket[first], bucket[k - first]);
                bucket[first] = 0;
            }
        }

        return count;
    }
};

```

