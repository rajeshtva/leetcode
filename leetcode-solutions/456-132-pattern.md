# 456. 132 Pattern

[link](https://leetcode.com/problems/132-pattern/)

**Level**: Medium 


## 1. Brute Approach

**Memory Use**:  19.8 MB

**Time**: 36 ms

**Explanation**:
-    try all possible values of i,j & k


**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if((nums[i] < nums[k]) && (nums[k] < nums[j])) return true;
                }
            }
        } 
        return false;
    }
};

```

## 2. Better Brute Force Approach.
```cpp

class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {

        int n = nums.size();

        for (int j = 1; j < n - 1; j++) {
            int minI = INT_MAX;

            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j])
                    minI = min(minI, nums[i]);
            }

            for (int k = j + 1; k < n; k++) {
                if ((minI < nums[k]) && (nums[k] < nums[j])) {
                    return true;
                }
            }
        }

        return false;
    }
};u
```

