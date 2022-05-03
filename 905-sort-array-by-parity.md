# Sort Array By Parity

[link](https://leetcode.com/problems/sort-array-by-parity/)
**Level**: Easy 

**Memory Use**:  16.1 MB

**Time**: 19 ms

**Explanation**:

- new comparator function

**Space complexity**: $O(n)$
**time complexity**: $O(n.log(n))$, for storing the element, $O(1)$ for getting top element.

```cpp
bool compare(int a, int b)
{
    // both even
    if (!(a & 1) && !(b & 1))
        return a < b;

    // both odd
    if ((a & 1) && (b & 1))
        return a < b;

    // a is even and b is odd
    if (!(a & 1) && (b & 1))
        return true;

    // a is odd and b is even
    if ((a & 1) && !(b & 1)) {
        return false;
    }

    return true;
}
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), compare);

        return nums;
    }
};
```
