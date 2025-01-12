class Solution {
public:
    unordered_map<int,vector<int>>adj;
    int bfs(int n){
        queue<int>q;
        q.push(0);
        vector<bool>visited(n,0);
        visited[0]=1;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                if(node==n-1) return level;
                for(int child:adj[node]){
                    if(!visited[child]){
                        q.push(child);
                        visited[child]=1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int>result;
        for(auto& query:queries){
            int u=query[0];
            int v=query[1];
            adj[u].push_back(v);
            int d=bfs(n);
            result.push_back(d);
        }

        return result;
    }
};