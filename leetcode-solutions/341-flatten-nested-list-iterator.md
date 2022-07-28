# 341. Flatten Nested List Iterator 

[link](https://leetcode.com/problems/flatten-nested-list-iterator/)
**Level**: Medium 

**Memory Use**:  13.1 MB

**Time**: 34 ms

**Explanation**:

-   this question only looks difficult, but actually very easy. just recurstion to be used to flatten the array.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp

class NestedIterator {
public:
    queue<int>bucket;
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillup(nestedList);
    }
    
    int next() {
        int val = bucket.front();
        bucket.pop();
        
        return val;
    }
    
    bool hasNext() {
        return !bucket.empty();
    }
    
    void fillup(vector<NestedInteger>& nestedlist){
        for(auto &i: nestedlist){         
            if(i.isInteger())
                bucket.push(i.getInteger());
            else fillup(i.getList());
        }
    }
    
    
};

```

