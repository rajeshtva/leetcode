# Shortest Unsorted Continuous Subarray

[link](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)
**Level**: Medium

**Memory Use**: 27.5 MB

**Time**: 38 ms

**Explanation**:

- first sort the entire array then traverse and see which index has been changed.

**Space complexity**: $O(n)$
**time complexity**: $O(n.log(n))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> temp(nums.size());

        vector<int>temp = nums;

        sort(nums.begin(), nums.end());

        int begin = -1;
        int end = -1;

        int size = nums.size();

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != temp[i]) {
                begin = i;
                break;
            }
            i++;
        }

        if (begin == -1) {
            return 0;
        }

        i = nums.size() - 1;
        while (i >= 0) {
            if (nums[i] != temp[i]) {
                end = i;
                break;
            }
            i--;
        }

        cout << end << " " << begin << endl;

        return abs(end - begin) + 1;
    }
};



```
