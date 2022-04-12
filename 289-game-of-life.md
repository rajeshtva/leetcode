# 289. Game of Life

[link](https://leetcode.com/problems/game-of-life/)

**Level**: Medium

**Memory Use**: 6.8 mb

**Time**: 3ms

**Explanation**:

- know how to iterate on all neighboruign elements of a cell to count 1's.

```cpp
    int getLiveNeighborsCnt(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;

        return cnt;
    }

```

**Space complexity**: $O(n^2)$ 

**time complexity**: $O(n^2)$ for temporary storing the board.



```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> next(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;

                // counting the alive neighbours
                // top row
                if (i - 1 >= 0) {
                    if (j - 1 >= 0 && board[i - 1][j - 1] == 1)
                        count++;
                    if (board[i - 1][j] == 1)
                        count++;
                    if (j + 1 <= n - 1 && board[i - 1][j + 1] == 1)
                        count++;
                }

                if (j - 1 >= 0 && board[i][j - 1] == 1)
                    count++;
                if (j + 1 <= n - 1 && board[i][j + 1] == 1)
                    count++;

                if (i + 1 <= m - 1) {
                    if (j - 1 >= 0 && board[i + 1][j - 1] == 1)
                        count++;
                    if (board[i + 1][j] == 1)
                        count++;
                    if (j + 1 <= n - 1 && board[i + 1][j + 1] == 1)
                        count++;
                }

                if (count < 2)
                    next[i][j] = 0;
                else if (count == 3) {
                    next[i][j] = 1;
                } else if (count > 3) {
                    next[i][j] = 0;
                } else {
                    next[i][j] = board[i][j];
                }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = next[i][j];
    }
};

```

#### Overall optimized solution(copied): 

```cpp
class Solution {
public:
    int R, C;
    bool isLive(int status) {
        return status == 1;
    }
    int getLiveNeighborsCnt(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        R = board.size(), C = board[0].size();
		int liveNeighborsCnt;
		// store current board state
        vector<vector<int>> tempBoard = board;        
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
				// compute number of live neighbors
                liveNeighborsCnt = getLiveNeighborsCnt(r, c, tempBoard);
				// Apply conditions and update state of board
                if(isLive(board[r][c])) {
                    if(liveNeighborsCnt < 2 || liveNeighborsCnt > 3) board[r][c] = 0;
                } else {
                    board[r][c] = liveNeighborsCnt == 3 ? 1 : 0;
                }
            }
        }
    }
};
```
