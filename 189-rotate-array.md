# 189 - Rotate Array

[link](https://leetcode.com/problems/rotate-array/)

**Level**: Medium

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

- circular array implementation.
- circularly all indices are traversed. and no one is missed.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();

        k = k % n;

        if (k == 0)
            return;

        int start = 0;
        int to = 0;
        int temp = nums[0];
        int count = 0;
        int from = 0;

        while (count < n) {

            from = (to - k + n) % n;

            if (from == start) {
                nums[to] = temp;
                start = from + 1;
                to = start;
                temp = nums[to];
            } else {
                nums[to] = nums[from];
                to = from;
            }

            count++;
        }
    }
};
```
