#include <bits/stdc++.h>
using namespace std;

int findLargestMinDistance(vector<int>& boards, int k)
{
    int n = boards.size();
    int s = 0;
    int e = accumulate(boards.begin(), boards.end(), 0);

    function<bool(int)> isPossible = [&](int mid) -> bool {
        // return if this value can be granted to all users .
        int painterCount = 0;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (temp + boards[i] <= mid) {
                temp += boards[i];
            } else {
                painterCount++;
                temp = boards[i];

                if (boards[i] > mid)
                    return false;
            }
        }

        return painterCount <= k ? true : false;
    };

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (isPossible(mid)) {
            e = mid - 1;
            ans = mid;
        } else {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
