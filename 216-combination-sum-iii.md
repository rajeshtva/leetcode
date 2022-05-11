#

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

-

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp


class solution {
public:
    vector<vector<int>> answer;

    int sum(vector<int>& combination)
    {
        int ans = 0;
        for (int i : combination) {
            ans += i;
        }

        return ans;
    }

    void helper(int k, int n, vector<int>& combination, int num)
    {
        if (k == 0) {
            if (this->sum(combination) == n) {
                answer.push_back(combination);
            }
        }

        if (num > 9) {
            return;
        }

        combination.push_back(num);
        helper(k - 1, n, combination, num + 1);
        combination.pop_back();
        helper(k, n, combination, num + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> combination;
        helper(k, n, combination, 1);
        return answer;
    }
}


```

### The method i tried

-   doens't work entirely correctly. it has issue of repeating arrays.
-   needs to be fixed
```cpp

class Solution {

public:
    unordered_map<int, bool> numbers;

    vector<vector<int>> combinationSum3(int k, int n)
    {
        return tracker(k, n);
    }

    vector<vector<int>> tracker(int k, int n)
    {

        if (n <= 0)
            return {};

        if (k == 1 && numbers[n] == false)
            return { { n } };

        vector<vector<int>> bucket, answer;

        for (int i = 1; i <= 9; i++) {

            if (numbers[i] == true)
                continue;

            numbers[i] = true;
            bucket = tracker(k - 1, n - i);
            numbers[i] = false;

            for (auto j : bucket) {
                j.push_back(i);

                answer.push_back(j);
            }
        }

        return answer;
    }
};
```
