# 1047. Remove All Adjacent Duplicates In String

[link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
**Level**: Easy

**Memory Use**: 10.7 MB

**Time**: 24 ms

**Explanation**:

- use string as a stack, this way extran loop won't be needed to convert stack into string.

**Space complexity**: $O(n)$
**time complexity**: $O(n)$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    string removeDuplicates(string s) {

        if(s.size() < 2) return s;

        string answer;
        answer.push_back(s[0]);
        for(int i = 1; i<s.size();i++){
           if(answer.back() == s[i]){
               answer.pop_back();
           } else {
               answer.push_back(s[i]);
           }
        }

        return answer;
    }
};
```
