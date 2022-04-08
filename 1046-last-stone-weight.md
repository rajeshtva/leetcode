### Last Stne weight.

[Daily Challange 2022-04-07](https://leetcode.com/problems/last-stone-weight/)

**time complexity**: O(n^2 . log(n))  
**space complexity**: O(n)

**explanation**:

- sort the array
- loop till there are at least two elements in array(we are removing elements from array)
  - then take last two elements, compare
  - if they are not equal. calcute difference and push back to the array.
    - sort the array if push elements in the array.

**Code**

```cpp

class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        sort(stones.begin(), stones.end());

        while (stones.size() > 1) {
            int first = stones.back();
            stones.pop_back();
            int second = stones.back();
            stones.pop_back();

            if (first != second) {
                stones.push_back(abs(first - second));
                sort(stones.begin(), stones.end());
            }
        }

        if(stones.size() == 1) {
            return stones[0];
        }

        return 0;
    }
};
```

### 2. using heap.

changes are only in the way we are storing data. we are including each element in the heap(max heap).implemented using priority queue. At every step, inside heap, each element is placed at appropriate position like in vector sorting.

```cpp
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for(int v : stones){
            maxHeap.offer(v);
        }
        int x;
        int y;
        while(maxHeap.size() > 1){
            y = maxHeap.poll();
            x = maxHeap.poll();
            if(y > x){
                maxHeap.offer(y - x);
            }
        }
        if(maxHeap.size() == 0) return 0;
        return maxHeap.poll();
    }
}
```

or

```cpp
public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b)->b-a);
        for(int item:stones) {
            maxHeap.add(item);
        }
        while(maxHeap.size()>1) {
            int a = maxHeap.poll();
            int b = maxHeap.poll();
            maxHeap.add(a-b);
        }
        return maxHeap.isEmpty() ? 0 : maxHeap.poll();
    }
```

**Conclusion**: Heap is required to learn.
