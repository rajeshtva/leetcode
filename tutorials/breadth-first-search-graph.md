- `nodes` is the adjecency list of graph

```cpp

class Solution {
public:
    vector<int>bfsOfGraph(int n, vector<vector<int>>nodes){

        vector<int>visited(n+1, 0);
        vector<int>answer;

        for(int i = 1; i <=n; i++) {
            if(!visited[i]){
                visited[i]=true;

                queue<int>q;
                q.push(i);
                visited[i]=true;

                while(!q.empty()){

                    int currentNode = q.front();
                    q.pop();

                    answer.push_back(currentNode);

                    for(auto j: nodes[currentNode]){
                        if(!visited[j]){
                            visited[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return answer;
    }
}
```
