# Implement strStr()

[link]()
**Level**: Easy 


**Explanation**:

- used geeks for geeks code to find subarray within parent array

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;

        int m = haystack.size();
        int n = needle.size();

        while (i < m && j < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;

                if (j == n)
                    return i - j;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }

        return -1;
    }
};



```


