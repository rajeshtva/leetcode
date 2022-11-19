#include "includes/leetcode.h"

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    bool a = INT_MIN == -pow(2, 31);
    cout << a << endl;
}
