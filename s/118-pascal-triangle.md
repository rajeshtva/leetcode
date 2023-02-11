# 

[link]()
**Level**: Easy 

**Memory Use**:  19.8 MB

**Time**: 36 ms

**Explanation**:

- 

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> board(numRows);

        for (int i = 0; i < numRows; i++) {
            int numColumn = i + 1;

            board[i] = vector<int>(numColumn);

            board[i][0] = board[i][i] = 1;

            for (int j = 1; j < i; j++) {
                board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
            }
        }

        return board;
    }
};



```

