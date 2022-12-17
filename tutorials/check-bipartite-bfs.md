# check bipartite of a graph.

if it is possible to color the whole graph using just 2 colors such that no two adjecent nodes have same color, 

observation: 
- if there is a cycle 
    - cycle length is even: bipartite
    - cycle length is odd: not
- else bipartite.

```cpp
class Solution {
public: 
    bool checkBipartite(vector<vector<int>>adjList) {
        int n = adjList.size();

        vector<int>visited(n, -1); // -1 is not colored, colors are 0 & 1,

        for(int i = 0; i<n;i++) {
            if(visited[i] == -1) {
                if(!bipartiteBfs(i, adjList, visited)) 
                    return false;
            }
        }

        return true;
    }

    bool bipartiteBfs(int current, vector<vector<int>>&adjList, vector<int>&visited) {
        queue<int>q;
        q.push(current);
        visited[current]=1;

        while(!q.empty()){
            int node = q.front(); 
            q.pop();

            for(int i : adjList[node]) {
                if(visited[i] == -1) {
                    visited[i]=1-visited[node];
                    q.push(i);
                } else if(visited[i] == visited[node]) 
                    return false; 
            }
        }

        return true;
    }
}
```
