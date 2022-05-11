# Perfect Squares.

[link](https://leetcode.com/problems/perfect-squares)
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

- dynamic programming. before each number calculate the no of steps it takes to reach there.

**Space complexity**: $O(1)$
**time complexity**: $O(n.n^(1/2))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    int numSquares(int n)
    {
        vector<int> cache(n + 1, INT_MAX);
        cache[0] = 0;
        cache[1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int sq = j * j;

                if (i - sq < 0)
                    break;

                cache[i] = min(cache[i], 1 + cache[i - sq]);
            }
        }

        return cache[n];
    }
};
```

### Breadth first search.

```cpp
class Solution {
public:
    int numSquares(int n)
    {
        vector<int> visited(n + 1);
        vector<int> level(n + 1);

        queue<int> row;

        row.push(n);

        while (!row.empty()) {
            int front = row.front();
            row.pop();
            int sq = floor(sqrt(front));
            for (int i = 1; i <= sq; i++) {
                int nextStep = front - (int)pow(i, 2);

                if (visited[nextStep] != 1) {
                    visited[nextStep] = 1;
                    row.push(nextStep);
                    level[nextStep] = level[front] + 1;
                }
            }
        }

        return level[0];
    }
};


```
