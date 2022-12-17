# Bellman-Ford Algorithm: 
- this algorithm is an alternative to dijkstra's algorithm, and overcomes dijkstra's limitation that dijkstra's algorithm doesn't work when there is a negative edge in graph
- but bellman-ford can deal with that.
- bellman-ford method can work with directed graph, if the graph in undirected, then it needs to be converted to directed by making each edge bi-directinal & assiging same weight to each direction.
- this algorithm requires `n-1` cycle because this is the number of cycle which will be required for resolve all edges of graph.
- the Node is the data structure which is storing starting node(first), ending node(second) and the weight associated with it. the direction is first -> second;
- the time complexity is $O(n * e)$ and space complexity is $O(n)$

```cpp
struct Node { 
    int first;
    int second;
    int weight;

    Node(int x, int y, int w): first(x), second(y), weight(w);
}

class Solution {
public: 
    vector<int> bellmanfordAlgo(vector<Node>edges, int n, int source) {

        vector<int>distance(n, INT_MAX);
        distance[source]=0;

        for(int i = 1; i <= n-1; i++) {
            for(auto &it: edges) {
                if(distance[it.first]+it.weight < distance[it.second]) {
                    distance[it.second] = distance[it.first]+it.weight;
                }
            }
        }

        // detecting negative cycle.
        bool hasNegativeCycle = false;
       for(auto &it: edges) {
            if(distance[it.first]+it.weight < distance[it.second]) {
                hasNegativeCycle = true; break;
            }
        }

        if(hasNegativeCycle) return {};

        return distance;
    }
}
```