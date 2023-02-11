# Finding Bridges in a graph
- zero based indexing
- a bridge is an edge in graph upon removing which the whole graph breaks into more no of components.
- `timeOfDiscovery` contains starting time of all nodes means when the node is visited for the first time. 
- `low` keep track of the lowest time in which its group can be visited(means its component) can be visited. It is set when we know all low of all adjecent nodes except parent.
- the main algorithm is: 
    - we first visit unvisited node recursively,
    - we mark that node visited, initialise 
    - during iterating adjecency list, except parent if we encouter any node which was already visited that means it is a case of back-edge, which means there is another path to reach node, so here we update `low[node]` with `timeOfDiscovery[it]`. we don't increment it by one, as we are not meant to check when a node is visited. but when a component is visited.

```cpp
class Solution {
public: 
    void findBridge(vector<vector<int>>&edges, int n, int edgeCount ) {
        // do dfs here.
        vector<bool>visited(n, false);
        vector<int>timeOfDiscovery(n,-1);
        vector<int>low(n,-1);
        int timer = 1;
        vector<pair<int,int>>answer;
        vector<vector<int>>adjList(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, -2, visited, timeOfDiscovery, low, timer, adjList, answer )
            }
        }

    }

    void dfs(int node, int parent, vector<int>&visited, vector<int>&timeOfDiscovery, vector<int>&low, int &timer, vector<vector<int>>&adjList, vector<pair<int,int>>&answer) {
        visited[node]=1;
        timeOfDiscovery[node] = low[node]=timer++;

        for(auto it: adjList[node]) {
            if(it == parent) continue;

            if(!visited[it]) {
                dfs(it, node, visited, timeOfDiscovery, low, timer, adjList, answer);

                low[node] = min(low[node], low[it]);

                if(timeOfDiscovery[node] < low[it]) {
                    answer.push_back({node,it});
                }
            } else {
                low[node]=min(low[node], timeOfDiscovery[it]);
            }
        }
    }
}
```