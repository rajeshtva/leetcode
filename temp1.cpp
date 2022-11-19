// #include "includes/leetcode.h"
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int answer(vector<int>& p, vector<int>& q)
//     {
//         int n = p.size();
//         int answer = 0;

//         int minCount = *max_element(p.begin(), p.end());
//         int maxFiller = *min_element(q.begin(), q.end());

//         answer = minCount;
//         if (maxFiller != 0)
//             answer += maxFiller;

//         return answer;
//     }
// };

class Solution {
    vector<int> arr;
    int solve(vector<int>& arr, int k)
    {
        int n = arr.size();
        this->arr = move(arr);

        return dfs(n, k);
    }

    int dfs(int n, int k)
    {
        int m = 0;
        return 1 + max(dfs(n - 1, m), dfs(n - 1, k));
    }
};
int main()
{
    int t;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    Solution solution;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    cout << solution.answer(p, q);
}
