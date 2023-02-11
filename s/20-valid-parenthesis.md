# Valid Parenthesis

[link](https://leetcode.com/problems/valid-parentheses)
**Level**: Easy

**Explanation**:

- use stack to

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> bucket;

        if (s.size() == 1)
            return false;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                bucket.push(ch);
            } else {
                if (bucket.size()) {

                    if (
                        ((ch == ')' && bucket.top() != '(')
                            || (ch == '}' && bucket.top() != '{')
                            || (ch == ']' && bucket.top() != '[')))
                        return false;
                    bucket.pop();
                } else {
                    return false;
                }
            }
        }

        if (bucket.size())
            return false;

        return true;
    }
};

```
