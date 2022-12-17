# Kosaraju's Algorithm:
- 0-based indexing considered.
- strongly connected components: In the components in a graph, if a node can be reached from any other node, then we call it strongly connected components.

- sort all nodes in finishing time.(just a simpl dfs would suffice)
- store all nodes in stack upon exiting function recursion call.
- steps: 
     - find all nodes involved by doing simple recursion, put them into stack in order ot finishing time.(means which node finishes earlier).
     - also transpose the `adjList` matrix because upon reversing the strongly connected component will not be affected because there is a path from every node to every other node. only paths which don't have bidirectionaly path will be broken.
     - traverse over new stack, do dfs on adjList, from this loop every single time we iterate over unvisited node we will have a new component which is strongly connected.

```cpp
class Solution {
public: 
    void getToposortList(vector<vector<int>>&adjList, int node, int n, vector<bool>&visited, stack<int>&sortedNode) {
        visited[node]=true;

        for(auto it: adjList[node]) {
            if(!visited[it]) {
                getToposortList(adjList, it, n, visited, sortedNode);
            }
        }

        sortedNode.push(node);
    }

    void reverseDfs(vector<vector<int>>&transpose, int node, vector<int>&visited, vector<int>&temp) {
        temp.push_back(node);
        visited[node]=true;

        for(auto it: transpose[node]) {
            if(!visited[it]) {
                reverseDfs(transpose, it, visited, temp);
            }
        }
    }

    void kosarajuAlgo(vector<vector<int>>&adjList, int n) {
        vector<bool>visited(n, false);
        stack<int>sortedNode;

        for(int i = 0; i < n; i++) {
            if(!visited[i])
                getToposortList(adjList, i, n, visited, sortedNode);
        }

        // making transpose of the original adjecency list./matrix.
        vector<vector<int>>transpose(n);
        
        for(int i = 0; i < adjList.size(); i++) {
            for(int j = 0; j < adjList[i].size(); j++) {
                transpose[j].push_back(i);
            }
        }

        // resetting visited array for another dfs traversal
        for(int i = 0; i<visited.size();i++) {
            visited[i]=false;
        }

        vector<vector<int>>result;
        while(!sortedNode.empty()) {
            vector<int>temp;
            int node = sortedNode.top();
            sortedNode.pop();

            reverseDfs(transpose, node, visited, temp);

            result.push_back(temp);
        }
    }
}
```