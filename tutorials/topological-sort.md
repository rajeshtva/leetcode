# Topological Sort

- multiple answers are possible.
- Directed Acyclic Graph only
- reasons: 
    - we can't tell in undirected graph that which nodes come first in an edge.
    - if there is cycle, then also it makes it difficult to tell. as cycle will form connecting last & first node.

```cpp
class Solution {
public: 
    vector<int>findTopologicalSort(vector<vector<int>>adjList, int n) {
        stack<int>s;
        vector<bool>visited(n, false);

        for(int i = 0; i<n;i++) {
            if(!visited[i]) {
                topologySort(i, adjList, s, visited);
            }
        }

        vector<int>sortedArray();

        while(!s.empty()) {
            sortedArray.push_back(s.top());
            s.pop();
        }

        return sortedArray;
    }

    void topologySort(int node, vector<vector<int>>adjList, stack<int>&s, vector<bool>&visited) {
        visited[node] = true;

        for(int i: adjList[node]) {
            if(!visited[i]) { 
                topologySort(i, adjList, s, visited);
            }
        }

        s.push(node);
    }
}
```
