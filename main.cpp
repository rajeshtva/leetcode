#include "libraries/leetcode.h"
/**
 * solution implementation.
 */
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<vector<int>> result;
        vector<vector<int>> points;

        trasformBuilding(buildings, points);

        sort(points.begin(), points.end(), [](const vector<int>& a, vector<int>& b) {
            return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
        });

        map<int, int> mp;
        mp[0] = 1;

        int previousHeight = 0;

        for (auto& p : points) {
            // put in queue
            if (p[1] < 0) {
                mp[-p[1]]++;
            } else {
                // if height is +ve, the pop that element.
                mp[p[1]]--;
                if (mp[p[1]] == 0) {
                    mp.erase(p[1]);
                }
            }

            if (previousHeight != mp.rbegin()->first) {
                result.push_back({ p[0], mp.rbegin()->first });
                previousHeight = mp.rbegin()->first;
            }
            // put in answer, the current x,y ,
        }

        return result;
    }

    void trasformBuilding(vector<vector<int>>& buildings, vector<vector<int>>& points)
    { // negate the point of beginingn
        for (auto& i : buildings) {
            points.push_back({ i[0], -i[2] }); // starting index.
            points.push_back({ i[1], i[2] }); // ending index.
        }
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
        string s;
        cin >> s;
        int target;
        cin >> target;

        auto input = deserialise2dMatrix<int>(s, 3);

        auto output = solution.getSkyline(input);

        print2dMatrix<int>(output);

        cout << endl;
    }
}
