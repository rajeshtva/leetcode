#include <functional>
#include <iostream>
#include <vector>

#define min(a, b) ((a < b) ? a : b)
#define ALLOWED_NUMBERS 1, \
                        2, \
                        3
#define func1(a) (a * 4)
#define func2(a, b) ((a * b))
using namespace std;

vector<string> digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void printDigits(int n)
{
    if (n == 0)
        return;
    int rem = n % 10;

    printDigits(n / 10);

    cout << digits[rem] << " ";
}

class Solution {
public:
    int findSum(vector<int>& nums)
    {

        function<int(int)> f = [&](int i) -> int {
            if (i < 0)
                return 0;

            return f(i - 1) + nums[i];
        };

        int n = nums.size();

        return f(n - 1);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /**
     *
        cout << min(66, 5) << endl;
        vector<int> nums = { ALLOWED_NUMBERS };

        for (auto it : nums)
            cout << it;

        cout << endl
             << func2(5, 6) << endl;
        cout << func1(4);
     */

    // const vector<int> d = { 5, 6, 3 };
    // // d.push_back(33);
    // printDigits(32090);
    // cout << endl;
    // printDigits(4347);
    Solution solution;
    vector<int> nums1 = { 3, 4, 5, 3 };
    vector<int> nums2 = {};

    int arr[] = new int[6];

    cout << solution.findSum(nums1) << endl;
    cout << solution.findSum(nums2) << endl;
}
