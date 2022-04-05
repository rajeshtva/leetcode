## naive approach: greedy solution.

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        long long mArea = 0;

        for(int i = 0; i < height.size(); i++)
        {
            for(int j = i + 1; j< height.size(); j++) {
                int tArea = min(height[i] , height[j]) * abs(i - j);

                if(tArea > mArea) {
                    mArea = tArea;
                }
            }
        }

        return mArea;
    }
};
```

## 2nd Approach:

time compleixty: O(n)
space complexity: O(1)

RunTime: 172ms(14.22%)
Memory Usage: 59mb(>81.47%)

Approach:
we can't store more water than minimum of both sides.
reduce whichever side is smaller.

explanation: [container with most water](https://www.youtube.com/watch?v=ZHQg07n_tbg)

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        long long mArea = 0;
        long long tempArea = 0;

        long long leftSide = 0;
        long long rightSide = height.size()-1;

        while(leftSide < rightSide) {
            tempArea = min(height[leftSide], height[rightSide]) * (rightSide - leftSide);

            if(tempArea > mArea) {
                mArea = tempArea;
            }

            if(height[leftSide] < height[rightSide]) {
                leftSide ++;
            } else if(height[leftSide] > height[rightSide]) {
                rightSide -- ;
            } else {
                leftSide ++ ;
                rightSide -- ;
            }
        }

        return mArea;
    }
};
```
