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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        set<pair<int, int>> bucket;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> answer;

        pair<int, int> previous = { 0, -1 };
        pair<int, int> temp;

        int direction = 0;

        int elements_count = m * n;

        for (int i = 1; i <= elements_count; i++) {
            temp = get_next_pointer(previous, direction);

            // checking bound or iterated before.
            if ((temp.first < 0 || temp.first >= m || temp.second < 0 || temp.second >= n) || matrix[temp.first][temp.second] == INT_MIN) {
                direction = (direction + 1) % 4;

                temp = get_next_pointer(previous, direction);
            }

            answer.push_back(matrix[temp.first][temp.second]);
            matrix[temp.first][temp.second] = INT_MIN;
            previous = temp;
        }

        return answer;
    }

    pair<int, int>
    get_next_pointer(pair<int, int>& previous, int direction)
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

        return { 0, 0 };
    }
};


```

