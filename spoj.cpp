#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    typedef long long ll;
    ll n, m;
    cin >> n >> m;

    vector<ll> nums(n, 0);
    ll start, end, mid, ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        start = min(start, nums[i]);
        end = max(end, nums[i]);
    }

    // solution
    function<ll(ll)> getWoodAmount = [&](ll h) -> ll {
        ll sum = 0;
        for (auto it : nums) {
            if (it >= h) {
                sum += (it - h);
            }
        }

        return sum;
    };

    mid = start + (end - start) / 2;

    while (start <= end) {
        ll wood = getWoodAmount(mid);

        if (wood == m) {
            ans = mid;
            break;
        } else if (wood > m) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    cout << ans;
}
