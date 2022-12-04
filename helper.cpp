#include "includes/leetcode.h"
// #define RAJESH 1;
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        return 0;
    }

    int somethin(void)
    {
        string d = "334,3232,22,4343,22,";
        stringstream ss(d);
        string word;
        int i = 0;

        while (!ss.eof()) {
            getline(ss, word, ',');
            cout << word << "---" << i++ << endl;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    Solution ts;

    cout << to_string('d') << string(1, 'x');

    ts.somethin();

    t = 0;
    while (t--) {
        Solution s;

        string a, b, c;
        cin >> a >> b >> c;

        auto i1 = deserialize<int>(a);
        auto i2 = deserialize<int>(b);
        auto i3 = deserialize<int>(c);

        auto output = s.jobScheduling(i1, i2, i3);

        print(output);
    }
}
