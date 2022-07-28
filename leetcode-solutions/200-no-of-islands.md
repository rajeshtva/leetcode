#

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

-   breadth first search.
-   the idea is to recursively mark all 1's which are adjecent(not diagonal) to the one node.
-   then mark all their nodes.  

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {

                    count++;

                    queue<pair<int, int>> bucket;
                    grid[i][j] = '2'; // marked as visited.
                    bucket.push({ i, j });

                    vector<int> rows = { -1, 0, 0, 1 };
                    vector<int> cols = { 0, -1, 1, 0 };

                    while (!bucket.empty()) {
                        // loop to mark all lands around it.

                        int p = bucket.front().first;
                        int q = bucket.front().second;

                        bucket.pop();

                        for (int k = 0; k < 4; k++) {
                            int r = p + rows[k];
                            int c = q + cols[k];

                            if (0 <= r && r < m && 0 <= c && c < n && grid[r][c] == '1') {
                                grid[r][c] = '2';
                                bucket.push({ r, c });
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
```
