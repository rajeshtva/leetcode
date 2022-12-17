// #include <bits/stdc++.h>
#include "includes/leetcode.h"

using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll c = 1e6;

    bool prime[c + 1];

    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= c; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= c; i += p) {
                prime[i] = false;
            }
        }
    }

    vector<ll> values;

    for (ll i = 2; i <= c; i++) {
        if (prime[i] == true)
            values.push_back(i);
    }

    print(values);
}
