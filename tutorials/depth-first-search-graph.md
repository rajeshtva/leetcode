```cpp

class Solution {
public: 
    vector<int> dfsForGraph(int n, vector<vector<int>>graph){
        vector<int>visited(n+1,0); // none are visited. 
        vector<int>answer;

        /**
         *  Do something here.
         */

        for(int i = 1;i<=n;i++){
            if(!visited[i]){

                visited[i]=true;
                dfs(i, visited, graph, answer);
            }
        }   
    }

    void dfs(int current, vector<int>&visited,vector<vector<int>>&graph, vector<int>&answer){

        answer.push_back(current);

        for(auto i: graph[current]){
            if(!visited[i]) {
                visited[i]=true;
                dfs(i, visited, graph, answer);
            }
        }
    }
}
```