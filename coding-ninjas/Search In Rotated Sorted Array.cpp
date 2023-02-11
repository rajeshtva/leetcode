#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
using namespace std;
#endif

int findPosition(vector<int>& arr, int n, int k)
{
    function<int(void)> f = [&]() -> int {
        int start = 0;
        int end = n - 1;

        int mid = start + (end - start) / 2;

        while (start < end) {
            if (arr[mid] < arr[0]) {
                end = mid;
            } else {
                start = mid + 1;
            }

            mid = start + (end - start) / 2;
        }

        return start;
    };

    int pivot = f();

    function<int(int, int)> binarySearch = [&](int start, int end) -> int {
        int mid = start + (end - start) / 2;

        while (start <= end) {
            if (arr[mid] == k)
                return mid;
            else if (arr[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

            mid = start + (end - start) / 2;
        }

        return -1;
    };

    // return arr[0] < k ? binarySearch(0, pivot - 1) : binarySearch(pivot, n - 1);

    if (arr[pivot] <= k && k <= arr[n - 1])
        return binarySearch(pivot, n - 1);
    else
        return binarySearch(0, pivot - 1);
}
