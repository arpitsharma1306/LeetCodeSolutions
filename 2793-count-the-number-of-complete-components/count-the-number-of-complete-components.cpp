class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adj,int idx,vector<int>&indegree,vector<bool>&visited){
        visited[idx]=true;
        queue<int>q;
        q.push(idx);

        vector<int>nodes;
        nodes.push_back(idx);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& child:adj[node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                    nodes.push_back(child);
                }
            }
        }

        int sz=nodes.size();
        for(auto& node:nodes){
            if(indegree[node]!=sz-1) return false;
        }

        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0], v=edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool complete = bfs(adj,i,indegree,visited);
                if(complete) count++;
            }
        }

        return count;
    }
};