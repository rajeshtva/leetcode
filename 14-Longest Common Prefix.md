# Longest Common Prefix

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

-

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = "";

        int i = 0;
        size_t minLength = INT_MAX;

        for (string& s : strs) {
            minLength = min(minLength, s.size());
        }
        char temp = ' ';
        for (int i = 0; i < minLength; i++) {
            temp = strs[0][i];

            for (int j = 0; j < strs.size(); j++) {
                if (temp != strs[j][i]) {
                    return ans;
                }

                if (j == strs.size() - 1) {
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};



```
