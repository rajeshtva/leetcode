# Dijkshtra Algorithm to find shortest path in undirected graph.

- the pair represent {element, weight};
- the pair going inside priority queue is of {weight, element}; (thing to consider properly).

```cpp
class Solution {
public: 
    findShortestPath(vector<vector<pair<int,int>>>&adjList, int n, int source) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>distance(n, INT_MAX);

        distance[source]=0;

        pq.push({0,source});

        while(!pq.empty()) {
            int weight = pq.top().second;
            int prev = pq.top().first;

            pq.pop();

            for(auto it: adjList[prev]) {
                int nextNode = it.first;
                int distanceW = it.second;

                if(weight + distanceW < distance[nextNode]) {
                    distance[nextNode]=weight+distanceW;
                    pq.push({distance[nextNode], nextNode});
                }
            }
        }

    }
}
```