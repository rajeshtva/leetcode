#include <bits/stdc++.h>

using namespace std;

int aggressiveCows(vector<int>& stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls.back();

    function<bool(int)> isPossible = [&](int mid) -> bool {
        int cowsCount = 1;
        int lastPosition = 0;

        for (int i = 0; i < n; i++) {
            if (stalls[i] - stalls[lastPosition] >= mid) {
                lastPosition = i;
                cowsCount++;
                if (cowsCount >= k)
                    return true;
            }
        }

        return false;
    };

    // binary search in the [start,end]

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e) {
        if (isPossible(mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
