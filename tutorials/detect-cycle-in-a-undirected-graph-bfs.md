```cpp
class Solution {
public: 

    bool detectCycle(int n, vector<vector<int>>&graph) {

        vector<int>visited(n+1,0);

        for(int i = 1; i<=n; i++) {
            if(!visited[i]){
                if(isCyclic(i, graph, visited)) return true;
            }
        }

        return false;
    }

    bool isCyclic(int i, vector<vector<int>>&graph, vector<int>&visited) {
        queue<pair<int,int>>q; 

        visited[i]=1;

        q.push({i, -1});

        while(!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(int t: graph[node]){
                if(!visited[t]) {
                    visited[t]=1;
                    q.push({t,node});
                } else {
                    if(parent != t) return true;
                }
            } 


        }

        return false;
    }
}
```