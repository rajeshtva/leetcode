# Toplogical sort using Queue & indegrees of nodes.(Kahn's Algorithm)

- can only implemented in directed acyclic graph.
- first we are calculating indegrees of nodes.
- then we put in the queues those nodes which have indegree 0.
- we take first element out of queue
    - we iterate
    - we reduce indegree of all nodes which are going out of that node.
    - if we find any node whose indegree has become 0, we push that node into queue.


```cpp
class Solution  {
public: 
    vector<int> topoSort(vector<vector<int>>adjList, int n){
        vector<int>indegree(n);

        for(int i = 0; i < n; i++) {
            for(int j: adjList[i]) {
                indegree[j]++;
            }
        }

        queue<int>q;

        for(int i = 0; i < n;i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>sortedArray;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            sortedArray.push_back(node); // storing result.

            for(int i :adjList[node]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        return sortedArray;
    }
}
```