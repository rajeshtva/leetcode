# 

[link]()
**Level**: Easy 

**Memory Use**:  18.4 MB

**Time**: 194 ms

**Explanation**:

- 

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int sum = 0;
        int j = 0;
        int m = mat.size();
        int n = mat[0].size();
        int maxSum = m + n - 2;
        vector<int> answer;
        bool up = false;

        while (sum <= maxSum) {
            if (up) {
                for (int i = 0; i < m; i++) {
                    j = sum - i;

                    if (j >= 0 && j < n) {
                        answer.push_back(mat[i][j]);
                    }
                }
            } else {
                for (int i = m - 1; i >= 0; i--) {
                    j = sum - i;

                    if (j >= 0 && j < n) {
                        answer.push_back(mat[i][j]);
                    }
                }
            }

            up = !up;

            sum++;
        }

        return answer;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution s;
    ull t;

    cin >> t;

    while (t--) {
        ull m = 0, n = 0;
        cin >> m >> n;

        vector<vector<int>> mat(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        vector<int> answer = s.findDiagonalOrder(mat);

        for (int i : answer) {
            cout << i << " ";
        }

        cout << endl;
    }
}


```

