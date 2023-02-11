# Disjoint set & path compression,
- the main point is to check if two nodes belong to same component or not.
- algorithm: we maintain a parent list, for telling who is parent of whom.
- we also maintain rank array for checking which of the two component is smaller. so that the merger would be efficient.
- time complexity is O(alpha): means it is constant. (proved mathematically)
### Algorithm:
- we first initialise all parent by itself. means all nodes are their parent.
- we iterate over all edges and try to merge two nodes ( so components ).
- first we find each nodes parent.
- if parent's rank are equal then we can take any node and make it other's parent. and increase high parent rank by 1.
- otherwise we change smaller ones parent with larger's parent. we don't change rank.


```cpp
class Solution {
public:  
    int parent[100000];
    int rank[100000];

    void makeSet(n){
        for(int i = 0; i < n; i++) {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(int node){
        if(parent[node] == node ) return node;

        return  parent[node] = findParent(parent[node]);
    }

    int union(int u, int v) {
        int a = findParent(u);
        int b = findParent(v);

        if(rank[a] < rank[b]) {
            parent[a] = b; 
        } else if(rank[a] > rank[b]) {
            parent[b]=a;
        } else {
            parent[a] = b;
            rank[a]++; 
        }
    }
}

```