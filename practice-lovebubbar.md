# macros in cpp

Types of macros

- object like macros.
  (simple macros such as that represents string or numbers)
- chain macros
  macros which forms a chain like macros's value is another macros, whoose value in turn is primitive.
- multiline macros
  object like macros with multiline like

```
#define numbers 1, \
                2, \
                3

```
- function like macros 
 appears like a literal followed with a pair with parenthesis optionally containing arguments like real functions, 
```cpp
#include <iostream>

#define min(a, b) ((a < b) ? a : b)
#define ALLOWED_NUMBERS = 1, \
                          2, \
                          3

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << min(66, 5) << endl;

    vector<int>nums = {ALLOWED_NUMBERS};
}
```
