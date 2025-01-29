class Solution {
public:
    int n;
    bool bfs(unordered_map<int,vector<int>>&adj,int u,int v){
        queue<int>q;
        q.push(u);
        vector<bool>visit(n+1,false);
        visit[u]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==v) return true;

            for(auto &child:adj[node]){
                if(!visit[child]){
                    visit[child]=true;
                    q.push(child);
                }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n=edges.size();
        unordered_map<int,vector<int>>adj;
        vector<bool>visited(n+1,false);

        for(auto& edge:edges){
            int u=edge[0], v=edge[1];
            if(visited[u] && visited[v]){
                if(bfs(adj,u,v)){
                    return {u,v};
                }else{
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }

            }else{
                visited[u]=true;
                visited[v]=true;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

        }

        return {-1,-1};
    }
};