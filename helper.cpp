#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>nums = {5,7,7,8,8,10}; int target = 8;

    auto one = lower_bound(nums.begin(), nums.end(), target);
    auto two = upper_bound(nums.begin(), nums.end(), target);

    cout << one-nums.begin() << " "<< two-nums.begin() << endl;


}
