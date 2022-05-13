#

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

- first traverse all the matrix and mark all 0's and push them into queue.
- iterate over queue and check for neighbours. if they are unmarked, then push them into queue if they're unvisited.

**Space complexity**: $O(n^2)$
**time complexity**: $O(O(n^2))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        vector<vector<int>> output(mat.size(), vector<int>(mat[0].size(), -1));

        queue<pair<int, int>> bucket;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    bucket.push({ i, j });
                    output[i][j] = 0;
                }
            }
        }

        int m = mat.size();
        int n = mat[0].size();

        while (bucket.size()) {
            pair<int, int> point = bucket.front();

            vector<int> nr = { -1, 0, 0, 1 };
            vector<int> nc = { 0, -1, 1, 0 };

            for (int i = 0; i < 4; i++) {
                int r = point.first + nr[i];
                int c = point.second + nc[i];

                if (0 <= r && r < m && 0 <= c && c < n) {
                    if (output[r][c] == -1) {
                        output[r][c] = output[point.first][point.second] + 1;
                        bucket.push({ r, c });
                    }
                }
            }

            bucket.pop();
        }

        return output;
    }
};

```
