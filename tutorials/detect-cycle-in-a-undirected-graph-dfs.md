```cpp

- undirected graph: if there is an edge between $i$ and $j$ then one can go from $i$ to $j$ and opposite. (two way path)

class Solution
{
public:
    bool detectCycle(int n, vector<vector<int>>&graph) {

        vector<bool>visited(n+1, false);

        for(int i = 1; i<=n;i++) {
            if(!visited[i]){
                visited[i]=true;
                if(isCyclic(i, -1, graph, visited))
                    return true; 
            }
        }

        return false;
    } 

    bool isCyclic(int node, int parent, vector<vector<int>>&graph, vector<int>&visited) {

            for(int t : graph[node]) {
                if(!visited[t]) {
                    visited[t]=true;
                    if(isCyclic(t, node, graph,visited));
                        return true;
                } else if(parent != t) 
                    return true;
            }

        return false;
    }
    
};
```