### 1. Naive Approach.

**time complexity**: O(n^3)  
**Verdict:** TLE

```cpp
class Solution {
    int M = 1e9 + 7;

public:
    int threeSumMulti(vector<int>& arr, int target)
    {
        long long count = 0;
        unordered_map<int, int>hash_table;

        for(auto i: arr) {
            hash_table[i]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                count = (count + hash_table[target - arr[i] - arr[j]]) % M;
            }
        }

        return count;
    }
};
```

### 2. Better Approach:

**approach:** check if `k(target - i -j )` exists in the array. if yes. then
