# Toplogical sort using Queue & indegrees of nodes.(Kahn's Algorithm)

- we proceed using kahn's algorithms as usual. i.e...
    - first we are calculating indegrees of nodes.
    - then we put in the queues those nodes which have indegree 0.
    - we take first element out of queue
        - we iterate
        - we reduce indegree of all nodes which are going out of that node.
        - if we find any node whose indegree has become 0, we push that node into queue.
- we also maintain counter which counts node of nodes coming out of queue. 
- if count is equal to node. then it means it is not cyclic, otherwise one node will be inserted twice in the queue. hence count will be different.

```cpp
class Solution  {
public: 
    vector<int> isCyclic(vector<vector<int>>adjList, int n){
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

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            sortedArray.push_back(node); // storing result.

            for(int i :adjList[node]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        // return sortedArray;

        if(count == n) return false; // count  should exactly be equal to no of
        // nodes. not cyclic if counts equals to node count. 

        return true;
    }
}
```