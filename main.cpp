#include "libraries/leetcode.h"
/**
 * solution implementation.
 */
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();

//         int start, end, maxLength = INT_MIN;

//         vector<vector<int>> cache(n, vector<int>(n, -1));

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = n - 1; j >= i; j--) {
//                 if (i == j) {
//                     cache[i][j] = 1;
//                 } else if (s[i] == s[j]) {
//                     if (cache[i + 1][j - 1] == -1)
//                         cache[i][j] = 2;
//                     else if (cache[i + 1][j - 1] != 0)
//                         cache[i][j] = cache[i + 1][j - 1] + 2;
//                     else
//                         cache[i][j] = 0;
//                 } else {
//                     cache[i][j] = 0;
//                 }

//                 if (maxLength != max(maxLength, cache[i][j])) {
//                     start = i;
//                     end = j;
//                     maxLength = cache[i][j];
//                 }
//             }
//         }

//         return s.substr(start, end - start + 1);
//     }
// };

class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size(), count = 0, left, right, maxLength = INT_MIN, start, end;

        for (int i = 0; i < n; i++) {
            left = right = i;

            while (0 <= left && right < n && s[left] == s[right]) {
                if (maxLength < right - left + 1) {
                    start = left;
                    end = right;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
                count++;
            }

            left = i;
            right = i + 1;

            while (0 <= left && right < n && s[left] == s[right]) {
                if (maxLength < right - left + 1) {
                    start = left;
                    end = right;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
                count++;
            }
        }

        return s.substr(start, end - start + 1);
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
    ull t;

    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << solution.longestPalindrome(s);

        cout << endl;
    }
}
