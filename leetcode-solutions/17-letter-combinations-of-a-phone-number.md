#

[link]()
**Level**: Easy

**Memory Use**: 6.7 MB

**Time**: 5 ms

**Explanation**:

-   used simple recursion based method no hash-maps used nor backtracking.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
    unordered_map<char, string> characters = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations;

        string matches = characters[digits[0]];

        if (digits.empty())
            return {};

        if (digits.size() == 1) {
            for (char ch : matches)
                combinations.push_back(string(1, ch));
        } else {
            vector<string> com = letterCombinations(digits.substr(1));

            for (char ch : matches) {
                for (string s : com) {
                    combinations.push_back(ch + s);
                }
            }
        }

        return combinations;
    }
};
```

## 2.nd approach
uses less ram and answers only in one iteration. for explanation: [visit this link: striver's video](https://www.youtube.com/watch?v=jC_cWLy7jSI)
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int area = 0;
        int n = heights.size();

        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] <= heights[st.top()])) {
                int h = heights[st.top()];
                st.pop();
                int w;

                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                area = max(area, h * w);
            }

            st.push(i);
        }

        return area;
    }
};
```
