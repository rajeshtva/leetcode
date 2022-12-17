```cpp
/**
 * breadth first search: 
 **/
class Solution {
public: 
    void bfs(int node, vector<vector<int>>&adjList, vector<bool>&visited) {
        visited[node]=true; 
        queue<int>q;
        q.push(node);

        while(!q.empty()) {
            int current = q.front();
            q.pop();

            for(auto itr: adjList[current]) {
                if(!visited[itr]) {
                    visited[itr]=true; 
                    q.push(itr);
                }
            }
        }
    }
}

/**
 * depth first search. 
 **/
class Solution {
public: 
    void dfs(int node, vector<vector<int>>&adjList, vector<bool>&visited) {
        if(!visited[node]) visited[node]=true; 

        for(auto it: adjList[node]) {
            if(!visited[it]) {
                visited[itr]=true;
                dfs(itr, adjList, visited);
            }
        }
    }
}

// check for bipartiteness of a graph.
class Solution {
public: 
    bool checkBipartite(vector<vector<int>>&adjList) {
        int n = adjList.size(); 
        vector<int>visited(n, -1);

        for(int i = 0; i < n; i++) {
            if(visited[i] == -1) {
                if(!isBipartite(i, adjList, visited)) return false;
            }
        }

        return true;
    }

    bool isBartite(int current, vector<vector<int>>&adjList, vector<int>&visited) {
        visited[current] = 1;
        queue<int>q;
        q.push(current);

        while(!q.empty()) {
            int node = q.front(); 
            q.pop();

            for(int i: adjList[node]){
                if(visited[i] == -1) {
                    visited[i] = 1 - visited[node];

                    q.push(i);
                } else if(visited[i] == visited[node]) {
                    return false;
                }
            }
        }

        return true;
    }

}


// code for bipartite dfs
class Solution {
public: 
    bool checkBipartite(vector<vector<int>>&adjList, int n) {
        vector<int>visited(n, -1);

        for(int i = 0; i < n; i++) {
            if(visited[i] == -1) {
                if(!isBipartite(i, adjList, visited)) return false;
            }
        }

        return true;
    }    

    bool isBipartite(int current, vector<vector<int>>adjList, vector<int>&visited, int color=1) {

        visited[current] = color;

        for(int i: adjList[current]) {
            if(visited[i] == -1) {
                if(!isBipartite(i, adjList, visited, 1-color)) return false;
            } else if(visited[i] == color) 
                return false;
        }

        return true;
    }
}

// cycle detection in directed graph using dfs. 

class Solution {
public :
    bool isCyclic(vector<vector<int>>&edges, int n) {
        vector<bool>visited(n, false);
        vector<bool>dfsVisited(n, false);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                if(checkCycle(i, adjList, visited, dfsVisited)) return true;
            }
        }

        return false;
    }

    bool checkCycle(int current, vector<vector<int>>&adjList, vector<bool>&visited, vector<bool>&dfsVisited) {
        visited[current] = true;
        dfsVisited[current] = true;

        for(int i: adjList[current]) {
            if(!visited[i])
                if(checkCycle(i, adjList, visited, dfsVisited)) return true; 
            else if(dfsVisited[i]) return true;
        }

        dfsVisited[current] = false;
        return false;
    }
}

// Topological sorting.
class Solution {
public: 
    vector<int>topoSort(vector<vector<int>>&adjList, int n){

        vector<bool>visited(n, false);
        stack<int>s;

        for(int i = 0; i<n;i++) {
            if(!visited[i]) dfs(i, adjList, visited, s); 
        }

        vector<int>res;

        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }

    void dfs(int current, vector<vector<int>>&adjList, vector<bool>&visited, stack<int>&s) {
        visited[current] = true;

        for(int i: adjList[current]) {
            if(!visited[i]) {
                dfs(i, adjList, visited, s);
            }
        }

        s.push(current);
    }
}

//topological sorting using kahn's algo: bfs implementation only, dfs already covered.
// directed acyclic graph only.
class Solution {
public: 
    bool vector<int> topoSort(vector<vector<int>>&adjList, int n) {
        vector<int>indegree(n);
        queue<int>q;


        for(int i = 0; i< n;i++) {
            for(int j : adjList[i]) {
                indegree[j]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // sorting here. 
        vector<int>result;

        while(!q.empty()) {
            int node = q.front(); 
            result.push_back(node);
            q.pop(); 
           

            for(int i: adjList[node]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        return result;
    }
}


// use kahn's algorithm to detect cycle in directed graph, IT IS ACTUALLY A BFS FOR FINDING CYCLE IN DIRECTED GRAPH.
CODE: 
class Solution {
public: 
    bool findCycle(vector<vector<int>>&adjList, int n) {

        vector<int>indegree(n,0);
        queue<int>q;

        for(int i = 0; i < n; i++) {
            for(int j: adjList[i]) {
                indegree[j]++;
            }
        }

        for(int i = 0; i< n ;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop(); 
            count++;

            for(int i : adjList[node]){
                indegree[i]--;

                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if(count == n) return false;

        return true;

    }
}


/**
*   finding shortest distance between two nodes in a directed graph with each node having unit weight.
*/
class Solution {
public:
    void findShotestPath(vector<vector<int>>&adjList, int n, int sourceNode)  {
        vector<int>visited(n, 0);
        stack<int>s;
        int w = 1; // common weight for all node.
        int INF = 1e9;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                dfs(i, adjList, visited, s);
            }
        }

        vector<int>result;

        fill(visited.begin(), visited.end(), INF);
        visited[sourceNode] = 0;

        while(!s.empty()) {
            int currentNode = s.top();
            s.pop();

            if(visited[currentNode] != INF) {
                for(int i : adjList[currentNode]) {
                    if(visited[currentNode] + w < visited[i]) {
                        visited[i] = visited[currentNode]+w;
                    }
                }
            }
        }

        return visited;
    }   

    void dfs(int currentNode, vector<vector<int>>&adjList, vector<bool>&visited, stack<int>&s) {
        visited[currentNode]=1;

        for(int i : adjList[currentNode]) {
            if(visited[i]==0){
                dfs(i, adjList, visited, s);
            }
        }

        s.push(currentNode);
    }
}

/**
* dijkstra's algorithm:  
*/
class Solution {
public: 
    vector<int> dijkstraAlgorithm(vector<vector<int>>&adjList, int n, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<int>distance(n, 1E9);

        distance[src] = 0;

        pq.push({0, src});

        while(!pq.empty()) {
            int currentNode = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            for(auto itr: adjList[currentNode]) {
                if(weight + itr.second < distance[itr.first]) {
                    distance[itr.first] = weight+itr.second;
                    pq.push({distance[itr.first], itr.first});
                }
            }
        }

        return distance;
    }
}

/**
    PRIM'S ALGORITHM FOR FINDING MINIMUM SPANNING TREE. (BRUTE FORCE METHOD)
*/
class Solution {
public: 
    vector<int>primsAlgorithm(vector<vector<int>>&adjList, int n) {
        int INF = 1E9;
        vector<int>key(n, INF);
        vector<int>parent(n);
        vector<bool>mstSet(n, false);

        for(int count = 1; count < n; i++) {
            int min = INT_MAX, node;

            for(int i=0;i<n;i++) {
                if(mstSet[i] == false && key[i] < min) {
                    min = key[i]; node = i;
                }
            }

            mstSet[node] = true;

            for(auto it: adjList[node]) {
                if(mstSet[it.first] == false && key[it.first] < it.second) {
                    key[it.first] = it.second;
                    parent[it.first] = node;
                }
            }
        }
    }
}

/** 
    DISJOINTS SET.
*/
class Solution {
public: 
    int findParent(int node, vector<int>&parent) {
        if(node == parent[node]) return node;
        else return parent[node] = findParent(parent[node], parent); // here we are doing path compression.
    }

    int getDisjointSet(vector<pair<int,int>>edges, int n,  int first, int second){
        // question is to tell whethere first and second belong to same component.

        vector<int>parent(n);
        for(int i = 0; i < n; i++) parent[i]=i;
        vector<int>rank(n, 1);

        for(auto &p: edges) {
            int a = findParent(p.first);
            int b = findParent(p.second);

            if(a==b) {
                // lie in same group
            } 

            if(rank(a) == rank(b)) {
                parent[a]=b;
                rank[a]++;
            } else if(rank(a) < rank(b)) {
                parent[a]=b;
            } else {
                parent[b] = a;
            }
        }
    }
}

//Kruskal Algorithm: FIND MINIMUM SPANNING TREE.
class Solution {
public: 
    void doUnion(int first, int second, vector<int>&parent, vector<int>&rank) {

        if(rank[first] < rank[second]) {
            parent[first]=second;
        } else if(rank[first] > rank[second]) {
            parent[second]=first;
        } else {
            parent[first]=second;
            rank[second]++;
        }
        
    }

    static bool compare(Node &a, Node &b) {
        return a.weight < b.weight;
    }

    vector<pair<int,int>> kruskalAlgorithm(vector<Node>&edges) {
        // Node is {first,second,weight} construct: 

        int cost = 0;
        vector<pair<int,int>>result;

        sort(edges.begin(), edges.end(), compare);

        for(int i = 0; i < n;i++) {
            parent[i]=i;
            rank[i]=0;
        }

        for(auto &p: edges) {
            int a = findParent(p.first);
            int b = findParent(p.second);

            if(rank[a] != rank[b]) {// checking if they belong to same component or not.
                doUnion(a, b);
                cost+=p.weight;
                result.push_back({a,b});
            }
        }

        return result;
    }
}

/***
    FINDING BRIDGES IN GRAPH.
*/
class Solution {
public:
    vector<vector<int>> findBridges(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> adjList(n);
        vector<vector<int>> result;

        for (auto it : connections) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        int timer = 1;
        vector<bool> visited(n, false);
        vector<int> low(n, INT_MAX), tIn(n, INT_MAX); // time of discovery.

        function<void(int, int)> dfs = [&](int current, int parent) -> void {
            visited[current] = true;

            low[current] = tIn[current] = timer++;

            for (auto it : adjList[current]) {
                if (it == parent)
                    continue;

                if (!visited[it]) {
                    dfs(it, current);
                    low[current] = min(low[current], low[it]);

                    if (low[it] > tIn[current]) {
                        result.push_back({ it, current });
                    }
                } else {
                    low[current] = min(low[current], tIn[it]);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, -1);
        }

        return result;
    }
};
/**
    FINDING ARTICULATION POINT IN GRAPH.
*/
class Solution {
    vector<int> findArticulationPoint(vector<vector<int>>&adjList, int n) {
        vector<bool>visted(n, false);
        vector<int>tIn(n, INT_MAX), low(n, INT_MAX);
        vector<bool>result(n, false);
        int timer = 1;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                doDfs(i, -1, adjList, visited, tIn, low, result, timer);
            }
        }

        return result;
    }

    void doDfs(int current, int parent, vector<vector<int>>&adjList, vector<int>&visited, vector<int>&tIn, vector<int>&low, vector<bool>&result, int &timer) {

        visited[current]=true;
        low[current] = tIn[current]=timer++;
        int child = 0;

        for(auto it: adjList[current]) {
            if(it == parent) continue;

            if(!visited[it]) {
                child++;
                doDfs(it, current, adjList, visited, tIn, low, result, timer);
                low[current] = min(low[current], low[it]);

                if(low[it] >= tIn[current] && parent != -1) {
                    result[current]=true;
                }
            } else {
                low[current] = min(low[current], tIn[it]);
            }
        }

        if(parent == -1 && child > 1) 
            result[current]=true;
    }
}


/**
    KOSARAJU'S ALGORITHM FOR FINDING STRONGLY CONNECTED COMPONENTS;
    : this algorithm counts total number of strongly connected components. even one single node is considered as a component: 
    : works in directed graph. 
*/
class Solution {
    int findCountOfStronglyConnectedComponents(vector<vector<int>>&adjList, int n){
        stack<int>st;
        vector<bool>visited(n, false);

        for(int i=0; i<n;i++) {
            if(!visited[i]) {
                topoSort(adjList, i, visited, st);
            }
        }

        // creating reverse adjecency list.
        vector<vector<int>>reverseAdjList(n);

        for(int i = 0; i < adjList.size(); i++) {
            for(int j : adjList[i]) {
                reverseAdjList[j].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), false);

        int count = 0; 

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(!visited[it]) {
                count++;
                dfs(it, reverseAdjList, visited);
            }
        }

        return count;

    }

    void dfs(int node, vector<vector<int>>&adjList, vector<int>&visited) {
        visited[node]=true;

        for(auto it: adjList[node]) {
            if(!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

    void topoSort(vector<vector<int>>&adjList, int current, vector<bool>&visited, stack<int>&st) {
        visited[current]=true;

        for(auto it: adjList[current]) {
            if(!visited[it])
                topoSort(adjList, it, visited);
        }

        st.push(it);
    }
}

/**
    BELLMANN-FORD ALGORITHM: detects negative cycle, and computes shortest path from a source to any node.
    we do relaxations.
    works in a directed graph.
*/
struct Node {
    int first;
    int second;
    int weight;
    Node(int f, int s, int w){
        first = f;
        second = s;
        weight = w;
    }
}
class Solution {
public: 
    int INF = 1e9;
    vector<int> bellmanFordAlgorithm(vector<Node>edges, int n, int source){

        vector<int>distance(n, INF);
        int edgeSize = edges.size();

        distance[source] = 0;

        for(int count = 0; count < n-1; count++) {
            for(int i = 0; i < edgeSize; i++) {
                Node edge = edges[i];

                if(distance[edge.first] == INF) continue;

                if(distance[edge.first] + edge.weight < distance[edge.second]) {
                    distance[edge.second] = distance[edge.first]+edge.weight;
                }
            }
        }

        // till now we should get minimum weight for all nodes. now final cycle check.
        for(int i = 0; i < edgeSize; i++) {
            Node edge = edges[i];

            if(distance[edge.first] == INF) continue;

            if(distance[edge.first] + edge.weight < distance[edge.second]) {
                // cycle detected. do somethin drastic.
                return {};
            }
        }

        return distance;
    }
}
```
