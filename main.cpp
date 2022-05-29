#include "libraries/leetcode.h"
/**
 * solution implementation.
 */
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n)
    {
        string num = to_string(n);
        map<char, int> chart;
        int i;

        for (i = num.size() - 1; i >= 0; i--) {
            if (i + 1 < n && num[i] < num[i + 1])
                break;

            if (chart[num[i]] == 0)
                chart[num[i]] = i;
        }

        if (i < 0) // first base case. the number is already greatest.
            return -1;

        pair<char, int> d;
        for (auto& s : chart) {
            if (s.first > num[i]) {
                d = s;
                break;
            }
        }

        swap(num[d.second], num[i]);

        reverse(num.begin() + i + 1, num.end());
        int ans;
        try {
            ans = stoi(num);
        } catch (const std::out_of_range& e) {
            ans = -1;
        }

        return ans;
    }
};
/**
 * Main class definition.
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
        int n;

        cin >> n;

        auto o = solution.nextGreaterElement(n);

        cout << o;

        cout << endl;
    }
}
