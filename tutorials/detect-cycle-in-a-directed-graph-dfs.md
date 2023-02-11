# Detect Cycle in a directed Graph using DEPTH FIRST SEARCH. 

- `visited` array keeps record of overall visit of a node. 
- `dfsVisited` array keeps record of node visit in a recursion. upon leaving the node, the node is marked as $0$ means it is not visited anymore. thus makes node free to be reached from other paths.
- a cycle will appear if a node is encountered while recursing, means during going down we are meeting same node twice. which is the case when `dfsVisited` & `visited` both are marked $1$.
- if a node is marked visited through `visited` & we encounter same node again through some other paths. that means that there is no cycle present in the recursion tree of that node. so it is unwise to check that node. had there been any cycle, it would have been already detected.

```cpp
class Solution {
public: 
    bool isCyclic(vector<vector<int>>adjList) {
        int n = adjList.size(); 
        vector<bool>visited(n, false);
        vector<bool>dfsVisited(n,false);

        for(int i = 0; i<n;i++) {
            if(!visited[i]) {
                if(checkCycle(i, adjList, visited, dfsVisited)) {
                    return  true;
                }
             }
        }

        return false;
    }

    bool checkCycle(int node, vector<vector<int>>&adjList, vector<bool>&visited, vector<bool>&dfsVisited ) {
        visited[node]=true;
        dfsVisited[node]=true;

        for(int i : adjList[node]) {
            if(!visited[i]) {
                if(checkCycle(i, adjList, visited, dfsVisited)) return true;
            } else if(dfsVisited[i]) {
                return true;
            } 
        }
        dfsVisited[node] = false;
        return false;
    }
}



```  
