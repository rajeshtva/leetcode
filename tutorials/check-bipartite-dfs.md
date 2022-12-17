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
                visited[i]=1; //colored the first node. here.
                if(!bipartiteDfs(i, adjList, visited)) 
                    return false;
            }
        }

        return true;
    }

    bool bipartiteDfs(int current, vector<vector<int>>&adjList, vector<int>&visited) {
        int availableColor = 1-visited[current];

        for(int i : adjList[current]) {
            if(visited[i] == -1) {
                visited[i]= availableColor;
                if(!bipartiteDfs(i, adjList, visited)) return false;

            } else if(visited[current] == visited[i]) return false;
        }

        return true;
    }
}
```
