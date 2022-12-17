# Kruskal algorithm is used to find minimum spanning tree in a graph.
- the concept of Disjoint set is used.
- we first sort all edges according to their weight.
- we then greedily iterate over all edges,
- if two nodes consisting belong to same component, we move on. else we join them
- this method doesn't use Adjecency list concept. 


```cpp
class Solution {
public:  
    int findParent(int node, vector<int>&parent){
        if(parent[node] == node) return node;

        return parent[node] = findParent(parent[node]);
    }

    int doUnion(int u, int v, vector<int>&rank, vector<int>&parent) {
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

    void kruskalAlgorithm(vector<vector<int>>adjList){
        // convert adjlist to a form which can be sorted. 
        // { weight, a, b}g
        int n = adjList.size();
        vector<int>parent(n,0);

        for(int i = 0; i < n; i++) {
            parent[i]=i;
        }
        vector<int>rank(n, 0)
        vector<vector<int>>sortedList;
        for(int i = 0; i < adjList.size(); i++) {
            for(int j=0; j < adjList[i].size(); j++) {
                sortedList.push_back({adjList[i][j][1], i, adjList[i][j][0]});
            }
        }

        sort(sortedList.begin(), sortedList.end());

        makeSet(adjList.size());

        for(int i = 0; i < n; i++) {
            
        }
    }
}

```

### striver implementation.
```cpp
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}

```