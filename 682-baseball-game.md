# 682. Base ball game.

[daily streak 10th april 2022](https://leetcode.com/problems/baseball-game/)
**Level**: Easy

**Memory Use**: 8.6 MB
**Time**: 8 ms
**Explanation**:

- Question needs basic knowledge of stack, integer to string conversation, and back.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
typedef unsigned long long ull;

class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        stack<string> container;

        for (string s : ops) {
            if (s == "C") {
                container.pop();

            }

            else if (s == "D") {
                string d = container.top();

                int m = stoi(d) * 2;

                container.push(to_string(m));

            }

            else if (s == "+") {
                int a = stoi(container.top());
                container.pop();

                int b = stoi(container.top());

                container.push(to_string(a));
                container.push(to_string(a + b));
            }

            else {
                container.push(s);
            }
        }

        int answer = 0;

        while (container.size()) {
            answer += stoi(container.top());
            container.pop();
        }

        return answer;
    }
};
```
