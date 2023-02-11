# Spiral Matrix 2

[link](https://leetcode.com/problems/spiral-matrix-ii)
**Level**: Medium

**Memory Use**:  6.4 MB

**Time**: 0 ms

**Explanation**:

- maintain a record of previous (i,j).
- in each loop, find new value of (i,j). check if it is in-bound and board[i][j] is also set to 0. 
- if above condition fails, then change direciton and find new pair of (i,j).

**Space complexity**: $O(n)$
**time complexity**: $O(n)$, 
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        set<pair<int, int>> bucket;

        vector<vector<int>> board(n, vector<int>(n, 0));

        pair<int, int> previous = { 0, -1 };
        pair<int, int> temp;

        int direction = 0;

        int elements_count = n * n;

        for (int i = 1; i <= elements_count; i++) {
            temp = get_next_pointer(previous, direction);

            // checking bound or iterated before.
            if ((temp.first < 0 || temp.first >= n || temp.second < 0 || temp.second >= n) || board[temp.first][temp.second] != 0) {
                direction = (direction + 1) % 4;

                temp = get_next_pointer(previous, direction);
            }

            board[temp.first][temp.second] = i;
            previous = temp;
        }

        return board;
    }

    pair<int, int> get_next_pointer(pair<int, int>& previous, int direction)
    {
        switch (direction) {
        case 0:
            return { previous.first, previous.second + 1 };
        case 1:
            return { previous.first + 1, previous.second };
        case 2:
            return { previous.first, previous.second - 1 };
        case 3:
            return { previous.first - 1, previous.second };
        }

        return {0,0};
    }
};

```

