#include "includes/leetcode.h"
/**
 * solution implementation.
 */
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> temp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    temp[i][j] = matrix[i][j] - '0';
                } else {
                    if (matrix[i][j] != '0') {
                        temp[i][j] = temp[i - 1][j] + matrix[i][j] - '0';
                    }
                }
            }
        }

        int area = 0;

        for (int i = 0; i < m; i++) {
            area = max(area, getMaxArea(temp[i]));
        }

        return area;
    }

    int getMaxArea(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> lnse(nums.size(), -1);
        vector<int> rnse(nums.size(), -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            rnse[i] = st.empty() ? n - 1 : st.top() - 1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            lnse[i] = st.empty() ? 0 : st.top() + 1;

            st.push(i);
        }

        int area = 0;

        for (int i = 0; i < n; i++) {
            area = max(area, (rnse[i] - lnse[i] + 1) * nums[i]);
        }

        return area;
    }
};
/**
 * Main class definition.`
 */
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution solution;
    int t;

    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        auto a = deserialise2dMatrix<char>(s);

        cout << solution.maximalRectangle(a);

        cout << endl;
    }
}
