#

[link]()
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Explanation**:

- use hashmap to store unique numbers.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    vector<vector<int>> output;
    vector<int> current;
    unordered_map<int, int> table;
    int size;

    void findAnswer()
    {
        if (current.size() == size) {
            output.push_back(current);
        }

        for (auto& itr : table) {
            if (itr.second == 0) {
                continue;
            }

            itr.second--;
            current.push_back(itr.first);

            findAnswer();

            current.pop_back();
            itr.second++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        size = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
        }

        findAnswer();

        return this->output;
    }
};

```
