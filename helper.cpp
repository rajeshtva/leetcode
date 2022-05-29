#include "libraries/leetcode.h"
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        string s;
        vector<vector<char>> input;

        cin >> s;

        input = deserialise2dMatrix(s);

        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                cout << input[i][j] << ' ';
            }
            cout << endl;
        }
    }
}
