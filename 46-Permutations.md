# 

[link]()
**Level**: Easy 

**Memory Use**:  19.8 MB

**Time**: 36 ms

**Explanation**:

- maintain a mapping of traversed value. 

for getting top element.

```cpp
class Solution {
public:
    vector<bool> table;

    vector<vector<int>> findAnswer(vector<int>& nums, int depth)
    {
        int n = nums.size();

        if (n == 0)
            return { {} };

        if (depth == 1) {
            for (int i = 0; i < this->table.size(); i++) {
                if (this->table[i] == false) {
                    return { { nums[i] } };
                }
            }
        }

        vector<vector<int>> output;

        for (int i = 0; i < n; i++) {
            if (this->table[i] == true)
                continue;

            this->table[i] = true;
            vector<vector<int>> res = this->findAnswer(nums, depth - 1);
            this->table[i] = false;

            for (vector<int> itr : res) {
                itr.push_back(nums[i]);
                output.push_back(itr);
            }
        }

        return output;
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        this->table = vector<bool>(nums.size());
        return this->findAnswer(nums, nums.size());
    }
};
```

### based on hashmap
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

    vector<vector<int>> permute(vector<int>& nums)
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
