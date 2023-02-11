# Articulation Point 

- an articulation point is a node in graph, which upon removing increases number of components.
- the algorithm is very much similar to finding bridges in graph problem
- one node can be articulation point for some edges and not for some. so the resultant answer may have repetitive nodes. so better to store that in a set.
- also we have to consider the parent-child case. which means that if in a for loop there are more than one depth-fist traversal. 

```cpp
class Solution {
public:  
    set<int> findArticulationPoints(vector<pair<int,int>>edges, int n, int e) {
        vector<vector<int>>adjList(n);
        vector<bool>visited(n, false);

        for(auto &it: edges){
            adjList[it.first].push_back(it.second);
            adjList[it.second].push_back(it.first);
        }

        vector<int>low(n,-1);
        vector<int>timeOfDiscovery(n,-1);
        int timer = 1;
        set<int>answer;

        for(int i = 0; i < n; i++) {
            dfs(i, -1, timer, edges, answer, timeOfDiscovery, low, visited)
        }

        return answer;
    }

    void dfs(int node, int parent, int &timer, vector<vector<int>>&edges, set<int>&answer, vector<int>&timeOfDiscovery, vector<int>&low, vector<int>&visited) {

        timeOfDiscovery[node]=low[node]=timer++;

        visited[node]=true;
        int child = 0;

        for(auto &it: vector[node]) {
            if(parent == it) continue;

            if(!visited[node]) {
                dfs(it, node, timer, edges, answer, timeOfDiscovery, low, visited);
                child++;
                low[node]=min(low[node], low[it]);

                if(low[it] >= timeOfDiscovery[node] && parent != -1) {
                    answer.insert(node);
                }
            } else {
                low[node] = min(low[node], timeOfDiscovery[it]);
            }
        }

        if(parent == -1 && child > 1) {
            answer.insert(node);
        }
    }
}
```