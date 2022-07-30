# Clone Graph

[link](https://leetcode.com/problems/clone-graph)
**Level**: Medium

**Space complexity**: $O(n)$
**time complexity**: $O(n + e)$, for storing the element, 
 - e is the number of edges. 

- bfs solution 
```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mp;

        queue<Node*>q;
        
        if(node == nullptr) return nullptr;

        Node* answer  = new Node(node->val);
        mp[node]=answer;

        q.push(node);

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            for(auto it: current->neighbors) {
                if(mp.find(it) == mp.end()) {
                    Node* temp = new Node(it->val);
                    mp[it] = temp;
                    q.push(it);
                }

                mp[current]->neighbors.push_back(mp[it]);
            }
        }

        return answer;
    }
};
```

- i did it myself.
```cpp
// node class definiton.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// actual solution.
class Solution {
public:
    Node* cloneGraph(Node* node) {  
        map<Node*, Node*>visited;
        return dfs(node, visited);
    }

    Node* dfs(Node* node, map<Node*, Node*>&visited) {
        
        if(node == nullptr) return nullptr;

        Node* newNode = new Node();
        newNode->val = node->val;
        visited[node] = newNode;

        Node* t;
        for(Node* it: node->neighbors) {
            auto temp = visited.find(it);

            if(temp  == visited.end()) {
                dfs(it, visited);
            }
            newNode->neighbors.push_back(visited[it]);
        }

        return newNode;
    }
};
  
```

# previous solution
- i must have copied this one.
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
