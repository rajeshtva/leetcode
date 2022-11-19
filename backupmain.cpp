#include "includes/leetcode.h"

using namespace std;

typedef long long ll;
typedef pair<string, int> psi;

class Compare {
public:
    bool operator()(psi& a, psi& b)
    {
        if (a.second < b.second)
            return false;
        else if (a.second == b.second)
            return a.first < b.first;

        return true;
    }
};

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        int lowest = *min_element(nums.begin(), nums.end());
    
        int n = nums.size();
        ll INF = 1E12;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= lowest;
        }

        int highest = *max_element(nums.begin(), nums.end());
        vector<vector<ll>> memo(n + 1, vector<ll>(highest + 1, -1));

        for (int j = 0; j <= highest; j++) {
            memo[0][j] = INF;
        }

        for (int j = 0; j <= highest; j++) {
            ll diff = j - nums[0] * 1ll;
            memo[1][j] = abs(diff) * 1ll * cost[0];
        }

        ll ans = LONG_LONG_MAX;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= highest; j++) {
                ll diff = j - nums[i - 1] * 1ll;
                memo[i][j] = abs(diff) * cost[i - 1] * 1ll + memo[i - 1][j];
            }
        }

        for (int j = 0; j <= highest; j++)
            ans = min(ans, memo[n][j]);

        return ans;
    }
};

int main()
{
    int t;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> t;
    while (t--) {
        Solution solution;

        string a, b, c, d, e;
        cin >> a;
        cin >> b;
        // cin >> c;
        // cin >> d;
        // cin >> e;
        // cin >> c;
        // cin >> d;
        auto input1 = deserialise<int>(a);
        auto input2 = deserialise<int>(b);
        // auto input3 = sanitize<int>(c);
        // auto input4 = sanitize<int>(d);
        // auto input5 = sanitize<int>(e);
        // auto input3 = deserialise<int>(c);
        // auto input4 = deserialise<int>(d);

        auto output = solution.minCost(input1, input2);

        print(output);
    }
}

// # helper main file
// #include <bits/stdc++.h>
#include "includes/leetcode.h"

using namespace std;

class Compare {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        if (a.first < b.first)
            return false;
        else if (a.first == b.first)
            return a.second < b.second;

        return true;
    }
};
// class Solution {
// public:
//     int destroyTargets(vector<int>& nums, int space)
//     {
//         vector<pair<int, int>> distance(space + 1);
//         for (int i = 0; i <= space; i++) {
//             distance[i].first = 0;
//             distance[i].second = INT_MAX;
//         }

//         for (auto& i : nums) {
//             int r = i % space;
//             distance[r].first++;
//             distance[r].second = min(distance[r].second, i);
//         }

//         sort(distance.begin(), distance.end(), d);

//         return distance[0].second;
//     }

//     bool static d(pair<int, int>& a, pair<int, int>& b)
//     {
//         if (a.first < b.first)
//             return false;
//         else if (a.first == b.first)
//             return a.second < b.second;

//         return true;
//     }
// };

// class Solution {
// public:
//     int destroyTargets(vector<int>& nums, int space)
//     {
//         int n = nums.size();
//         vector<int> remCount(space);
//         map<int, int> mp;
//         map<int, int> inverseMap;
//         int c;

//         for (int i = 0; i < n; i++) {
//             c = nums[i] % space;
//             mp[c]++;
//         }

//         for (auto& it : mp) {
//             auto i = inverseMap.find(it.second);

//             if (i == inverseMap.end()) {
//                 inverseMap[it.second] = it.first;
//             } else {
//                 inverseMap[it.second] = min(inverseMap[it.second], it.first);
//             }
//         }

//         return (inverseMap.rbegin())->second;
//     }

//     bool static d(pair<int, int>& a, pair<int, int>& b)
//     {
//         if (a.first < b.first)
//             return false;
//         else if (a.first == b.first)
//             return a.second < b.second;

//         return true;
//     }
// };

class Solution {
public:
    string oddString(vector<string>& words)
    {
        auto c = words;
        unordered_map<string, pair<int, int>> mp;

        for (int j = 0; j < c.size(); j++) {
            string& s = c[j];
            int n = s.length();

            for (int i = 0; i < n; i++) {
                s[i] -= 'a';
            }

            mp[s].first++;
            mp[s].second = j;
        }

        for (auto it : mp) {
            if (it.second.first == 1)
                return words[it.second.second];
        }

        return "";
    }
};
int main()
{
    int t;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> t;
    while (t--) {
        Solution solution;

        string a, b, c, d, e;
        cin >> a;
        // cin >> b;
        // cin >> c;
        // cin >> d;
        // cin >> e;
        // cin >> c;
        // cin >> d;
        auto input1 = deserialise<string>(a);
        // auto input2 = deserialise<string>(b);
        // auto input3 = sanitize<int>(c);
        // auto input4 = sanitize<int>(d);
        // auto input5 = sanitize<int>(e);
        // auto input3 = deserialise<int>(c);
        // auto input4 = deserialise<int>(d);

        auto output = solution.oddString(input1);

        print(output);
    }
}

