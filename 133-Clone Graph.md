# Clone Graph

[link](https://leetcode.com/problems/clone-graph)
**Level**: Easy

**Memory Use**: 19.8 MB

**Time**: 36 ms

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
    unordered_map<Node*, Node*> table;

public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr)
            return nullptr;
        if (table[node] != nullptr)
            return table[node];

        Node* newNode = new Node(node->val);
        table[node] = newNode;

        for(auto itr: node->neighbors){
            Node* temp = this->cloneGraph(itr);

            newNode->neighbors.push_back(temp);
        }

        return newNode;
    }
};

```
