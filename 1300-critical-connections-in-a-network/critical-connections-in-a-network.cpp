class Solution {
public:
    vector<vector<int>>bridges;
    vector<int>low;
    vector<int>tim;
    int time = 1;

    void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        low[node] = tim[node] = time;
        time++;

        for(int& v:adj[node]){
            if(v==par) continue;

            if(!vis[v]){
                dfs(v,node,adj,vis);
                low[node] = min(low[node],low[v]);
                if(low[v]>tim[node]){
                    bridges.push_back({node,v});
                }
            }else{
                low[node]=min(low[node],low[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &it: connections){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        low.resize(n);
        tim.resize(n);
        vector<int>vis(n,0);
        dfs(0,-1,adj,vis);

        return bridges;
    }
};