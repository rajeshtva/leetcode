# 1260. Shift 2D grid

[link](https://leetcode.com/problems/shift-2d-grid/)
**Level**: Easy 


**Memory Use**:  14mb 
**Time**: 47 ms 
**Explanation**:
- take modulas of k with m * n because at every m * n shifts things will repeat itself.

**Space complexity**: $O(n^3)$
**time complexity**: $O(n^2)$,
```cpp

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m * n);

        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pair<int, int> currentPosition = { i, j };
                pair<int, int> newPosition = getNextPlace(currentPosition, m, n, k);

                matrix[newPosition.first][newPosition.second] = grid[i][j];
            }
        }

        return matrix;
    }

    pair<int, int> getNextPlace(pair<int, int>& position, int m, int n, int k)
    {
        int x = position.first;
        int y = position.second;

        while (k--) {
            if (x == m - 1 && y == n - 1) {
                x = 0;
                y = 0;
            } else if (y == n - 1) {
                x = x + 1;
                y = 0;
            } else {
                y++;
            }
        }

        return { x, y };
    }
};

```


