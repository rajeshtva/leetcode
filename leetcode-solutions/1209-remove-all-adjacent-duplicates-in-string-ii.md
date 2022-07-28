# 1209. Remove All Adjacent Duplicates in String II

[link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)
**Level**: Medium

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

-

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

1st approach. using stack only. causes TLE

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        string storage = "";

        if (s.size() < k)
            return s;

        while (true) {

            storage = "";
            stack<char> bucket;

            for (char c : s) {
                if (bucket.size() == k) {
                    int t = k;
                    while (t--) {
                        bucket.pop();
                    }
                } else if (bucket.size() && bucket.top() != c) {
                    while (!bucket.empty()) {
                        storage.push_back(bucket.top());
                        bucket.pop();
                    }
                }

                bucket.push(c);
            }

            if (bucket.size() == k) {
                int v = k;
                while (v--) {
                    bucket.pop();
                }
            } else if (!bucket.empty()) {
                while (!bucket.empty()) {
                    storage.push_back(bucket.top());
                    bucket.pop();
                }
            }

            if (storage == s)
                return s;
            else if (storage.size() < k)
                return storage;

            s = storage;
        }

        return s;
    };
};

```


## 2nd approach.
**explanation**: 
-   use stack to put character.
-   use pair instead of single characters.

**Space complexity**: $O(n)$
**time complexity**: $O(n)$, for storing the element, $O(1)$ for 
```cpp
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        if (s.size() < k)
            return s;

        stack<pair<char, int>> bucket;

        for (char c : s) {
            if (bucket.empty() || bucket.top().first != c)
                bucket.push({ c, 1 });
            else {
                pair<char, int> previous = bucket.top();
                bucket.pop();
                bucket.push({ c, previous.second + 1 });
            }

            if (bucket.top().second == k)
                bucket.pop();
        }

        string answer;
        if (bucket.size()) {
            while (bucket.size()) {
                pair<char, int> temp = bucket.top();
                bucket.pop();

                while (temp.second--) {
                    answer += temp.first;
                }
            }

            reverse(answer.begin(), answer.end());
        }

        return answer;
    };
};


```
