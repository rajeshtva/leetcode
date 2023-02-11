# Reverse Words in a String

[link](https://leetcode.com/problems/reverse-words-in-a-string/)

**Level**: Medium

**Explanation**:

- use of stringstream class, and its property to ignore white-space characters.

**Space complexity**: $O(1)$

**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    string reverseWords(string s)
    {
        stringstream sst(s);
        s.clear();

        string word;

        while (sst >> word) {
            for (char ch : word) {
                s.push_back(ch);
            }
            s.push_back(' ');
        }

        s.pop_back();

        reverse(s.begin(), s.end());

        auto start = s.rbegin();

        for (auto itr = s.rbegin(); itr != s.rend(); itr++) {

            if (*itr == ' ') {
                reverse(start, itr);
                start = s.rend();
            } else if (start == s.rend()) {
                start = itr;
            }
        }

        reverse(start, s.rend());

        return s;
    }
};
```
