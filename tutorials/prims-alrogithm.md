# Prims' Algorithm for finding minimun spanning tree.
 
- a spanning tree is a tree obtained by removed some or none of the edges such that the remained graph has `n-1` edges. 
- there could be multiple spannign trees of a graph.
- the minimum spaning tree is a spanning tree whose sum of the weights is minimum among all spaning trees.

- in block no. 1(loop), we are iterating for `n-1` times in because in the desired tree there will be only `n-1` edges. (definition of spanning tree).
- in `key` array we are storing the smallest possible weight to reach that node from tree. not overall, from the starting node.
- `mstSet` keeps the current state of spaning tree. by marking nodes in tree as `true`
- `parent` keeps track of the which node is the father of which node. by assigning an node no at every index. suppose `parent[i]=j`, it means that j is the index of parent of node at index i


## brute force approach.
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=5,m=6;
    vector<pair<int,int> > adj[N]; 


    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});
    
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 
  
    // b0,
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 


    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;

    // b1
    for (int count = 0; count < N - 1; count++) 
    { 
        int mini = INT_MAX, u; 
        // b2,
        for (int v = 0; v < N; v++) 
        {
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v;  // u is the index of the key 
        }
                 
        mstSet[u] = true; 
        
        // b3,
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    //b2
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 


    return 0;
}
```


## efficient approach.(always use this)
- we are assuming that `adjList` containes the connection of this node with other node & stores pairs in the form of {edge, weight}
- we are storing {key, index} in the priority queue which is a minheap
- before implementing algorithm make sure that index & node numbering matches & take zero-based indexing. even if nodes are string, then convert them in int, make another adjList if required. this is crucial...
```cpp
class Solution {
public: 
    vector<vector<int>> findMinimumSpaningTree(vector<vector<pair<int,int>>>adjList, int source) {
        int n = adjList.size();

        // three vectors, 
        vector<int>key(n, INT_MAX);
        vector<bool>msSet(n, false);
        vector<int>parent(n, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,0});

        for(int i = 0; i < n-1; i++) {
            auto temp = pq.front();
            int index = temp.second;
            int node = temp.first;
            pq.pop();

            msSet[index]=true;

            for(auto itr: adjList[index]) {
                int weight = itr.second;
                int neighbour = itr.first;

                if(msSet[neighbour] == false && weight < key[neighbour]) {
                    key[neighbour] = weight;
                    parent[neighbour] = index;
                    pq.push({weight, neighbour});
                }
            }
        }
    }
}
```
