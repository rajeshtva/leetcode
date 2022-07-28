# Kth largest element in stream

[link](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
**Level**: Easy

**Memory Use**: 19.8 MB
**Time**: 36 ms
**Explanation**:

- maintain a min heap which keeps the smallest element so far at the top.
- if the size of min heap exceeds k, then just remove top element.
- at the end the top element will be answer.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int k;

public:
    KthLargest(int o, vector<int>& nums)
    {
        k = o;
        for (int a : nums) {
            minHeap.push(a);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};
```
