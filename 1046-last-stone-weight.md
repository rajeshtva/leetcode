### Last Stne weight.

[Daily Challange 2022-04-07](https://leetcode.com/problems/last-stone-weight/)

**time complexity**: O(n^2 . log(n))  
**space complexity**: O(1)

**explanation**: - sort the array - loop till there are at least two elements in array(we are removing elements from array) - then take last two elements, compare - if they are not equal. calcute difference and push back to the array. - sort the array if push elements in the array.

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
