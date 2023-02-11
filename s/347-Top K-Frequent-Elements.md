## Tok K Frequest Elements. 

[link](https://leetcode.com/problems/top-k-frequent-elements/)



#### Naive solution:
**Time taken:** 27ms
**Space complexity:**13.9mb

```cpp
bool cmpFunction(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> table;

        for (auto i : nums) {
            table[i]++;
        }

        vector<pair<int, int>> sortArray;
        for (auto& i : table) {
            sortArray.push_back(i);
        }

        // sort the array.
        sort(sortArray.begin(), sortArray.end(), cmpFunction);

        // return the k most occuring eleemnt.
        vector<int>answer;
        for(auto itr = sortArray.end()-k; itr != sortArray.end(); itr++){
            answer.push_back(itr->first);
        }

        return answer;
    }
};


```

#### 2. using hash map and priority queue(minHeap)
**Time taken:** 12ms
**Space complexity:**13.7mb
```cpp
typedef pair<int, int> T;

class Compare {
public:
    bool operator()(T& a, T& b)
    {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> table;

        for (auto i : nums) {
            table[i]++;
        }

        priority_queue<T, vector<T>, Compare> minHeap;

        for (auto& i : table) {
            minHeap.push(i);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // return the k most occuring eleemnt.
        vector<int> answer;
        while (minHeap.size()) {
            answer.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return answer;
    }
};


```
