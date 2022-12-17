# Shortest path in Directed Graph
- directed acyclic graph.
- first find the topological sort of the array.
- from the stack obtained, we do traversal and calculate minimum distance to each node.
- since in the stack, all nodes which have inorder 0 are at the top, and inorder subsequently increases downward. so we don't need to maintain any queue like earlier. we just have to iterate & calculate weight of its children. we don't even store any node furthur in any queue. (stored already in stack).

```cpp
class Solution {
public: 
    int INF = 1e9;
    vector<int>shortestPath(vector<vector<pair<int,int>>>&adjList, int n, int src) {
        vector<bool>visited(n, false);
        stack<int>st;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                topoSort(adjList, i, st, visited);
            }
        }

        vector<int>distance(n, INF);
        distance[src]=0;

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(distance[node] != INF){
                for(auto it: adjList[node]) {
                    if(distance[node] + it.second < distance[it.first]) {
                        distance[it.first] = it.second + distance[node];
                    }
                }
            }
        }

        return distance;


    }

    void topoSort(vector<vector<pair<int,int>>>&adjList, int node, stack<int>&st, vector<bool>&visited) {
        visited[node]=true;

        for(int i = 0; i < adjList[node].size(); i++) {
            if(!visited[i]) {
                topoSort(adjList, i, st, visited);
            }
        }

        st.push(node);
    }
}
```
