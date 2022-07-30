# 739. Daily Temperatures

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

-

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> output(n);

        stack<int> bucket;

        for (int i = 0; i < n; i++) {
            if (bucket.size() && temperatures[bucket.top()] < temperatures[i]) {
                while (bucket.size() && (temperatures[bucket.top()] < temperatures[i])) {
                    output[bucket.top()] = i - bucket.top();
                    bucket.pop();
                }
            }
            bucket.push(i);
        }

        return output;
    }
};



```
