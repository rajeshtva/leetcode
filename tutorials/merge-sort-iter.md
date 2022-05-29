```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int n = nums.size();

        for (int currentSize = 1; currentSize <= n-1; currentSize = currentSize * 2) {
            for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize) {
                int mid = min(leftStart + currentSize - 1, n - 1);
                int rightEnd = min(leftStart + 2 * currentSize - 1, n - 1);

                merge(nums, leftStart, mid, rightEnd);
            }
        }

        return nums;
    }

    void merge(vector<int>& array, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> left(n1), right(n2);

        // copy data to temp array Left to right.
        for (i = 0; i < n1; i++) {
            left[i] = array[l + i];
        }

        for (j = 0; j < n2; j++) {
            right[j] = array[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                array[k] = left[i++];
            } else {
                array[k] = right[j++];
            }

            k++;
        }

        while (i < n1) {
            array[k++] = left[i];
            i++;
        }

        while (j < n2) {
            array[k++] = right[j];
            j++;
        }
    }
};
```
