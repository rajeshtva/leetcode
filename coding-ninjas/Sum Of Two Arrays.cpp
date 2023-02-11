
#include <bits/stdc++.h>
using namespace std;
vector<int> findArraySum(vector<int>& a, int m, vector<int>& b, int n)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> answer;

    int s = max(m, n);

    int rem = 0;

    char* ch = "doctor strange";

    for (int i = 0; i < s; i++) {
        int value = rem;

        if (i < m) {
            value += a[i];
        }

        if (i < n) {
            value += b[i];
        }

        answer.push_back(value % 10);
        rem = value / 10;
    }

    if (rem != 0)
        answer.push_back(rem);

    reverse(answer.begin(), answer.end());

    return answer;
}
