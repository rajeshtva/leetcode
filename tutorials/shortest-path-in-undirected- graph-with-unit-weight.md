# Shortest path in undirected graph with unit weight.

- since there is no weight assigned to any of the edges. we can consider it to be unit.
- we fill visited/distance array with biggest value i.e.. INT_MAX, 1e9, 1e18..  generally infinity for the problem
- we also mark distance from source to source as 0.
- we are using BFS here.

```cpp
class Solution {
public: 
    vector<int> shortestPath(vector<vector<int>>&adjList, int n, int source) {
        vector<int>distance(INT_MAX);
        distance[source] = 0;

        queue<int>q; 
        q.push_back(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adjList[node]) {
                if(distance[node] + 1 < distance[it]) {
                    distance[it]=distance[node]+1;
                    q.push(it);
                }
            }
        }

        return distance;
    }
 }
```