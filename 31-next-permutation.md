# 31. Next permutation.

[link](https://leetcode.com/problems/next-permutation/)

**Level**: Medium

**Memory Use**: 12.3mb

**Time**: 100ms

**Explanation**:

- look for the index which is smaller than the next one. mark that index , if another i whose i+1 is bigger then marked value will be new i.
- put all numbers that comes after that numbers in bucket(multiset), if i is reset. clear bucket.
- find the next bigger number than i'th value from bucket.
- put i'th value in the bucket and put next bigger value at ith place.
- set left to i'th + 1 if there is any ascending pattern found otherwise left will 0.
- put all number after ith place.

**Space complexity**: $O(1)$

**time complexity**: $O(n.log(n))$

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        multiset<int> bucket;
        int left = 0;

        int nextMax = -1;
        bool nextSet = false;

        if(nums.size() < 2){
            return;
        }

        while (left <= nums.size() - 2) {
            if (nums[left] < nums[left + 1]) {
                nextMax = left;
                bucket.clear();
            } else {
                bucket.insert(nums[left]);
            }

            left++;
        }

        bucket.insert(nums[left]);

        if (nextMax != -1) {
            int maxValue = nums[nextMax];

            for (auto itr = bucket.begin(); itr != bucket.end(); itr++) {
                if (maxValue < *itr && nextSet == false) {
                    maxValue = *itr;
                    nextSet = true;
                    bucket.erase(itr);
                    break;
                }
            }
            bucket.insert(nums[nextMax]);
            nums[nextMax] = maxValue;
            left = nextMax + 1;

        } else {
            left = 0;
        }


        for (auto itr = bucket.begin(); itr != bucket.end(); itr++) {
            nums[left++] = *itr;
        }
    }
};

```

##### 2. approach (copied.)

```cpp
class Solution {
public:
    void helpr(vector<int>& nums, int i, int n)
    {
        int j = n-1;
        for (; j >= i; j--) {
            if (nums[i - 1] < nums[j]) {
                break;
            }
        }

        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());

        return;
    }
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int t = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                t = 1;
                helpr(nums, i, n);
                return;
            }
        }
        if (t == 0)
            reverse(nums.begin(), nums.end());
        return;
    }
};

```
