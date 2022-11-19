#include "includes/leetcode.h"

using namespace std;

typedef long long ll;

class Solution {
public:
    string s;
    string t;
    string robotWithString(string s)
    {
        this->s = move(s);
        return dfs();
    }

    string dfs()
    {
        string maxString = string(1e6, 'z');
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
        auto input1 = sanitize<string>(a);
        // auto input2 = sanitize<int>(b);
        // auto input3 = sanitize<int>(c);
        // auto input4 = sanitize<int>(d);
        // auto input5 = sanitize<int>(e);
        // auto input3 = deserialise<int>(c);
        // auto input4 = deserialise<int>(d);

        auto output = solution.minimumDistance(input1);

        print(output);
    }
}
