class Solution {
public:
    bool isBipartite(unordered_map<int,vector<int>>&adj,vector<int>&colors,int currColor, int curr){
        colors[curr]=currColor;

        for(auto ngbr:adj[curr]){
            if(colors[ngbr]==colors[curr]){
                return false;
            }
            if(colors[ngbr]==-1){
                if(isBipartite(adj,colors,1-currColor,ngbr)==false){
                    return false;
                }
            }
        }

        return true;
    }

    int bfs(unordered_map<int,vector<int>>&adj,int node,int n){
        vector<int>visited(n+1,false);
        queue<int>q;
        q.push(node);
        visited[node]=true;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(auto &ngbr:adj[curr]){
                    if(!visited[ngbr]){
                        q.push(ngbr);
                        visited[ngbr]=true;
                    }
                }
            }
            level++;
        }

        return level;
    }

    int getMaxElement(unordered_map<int,vector<int>>&adj,int curr,vector<int>&levels,vector<bool>&visited){
        int maxGrp = levels[curr];
        visited[curr]=true;
        for(auto &ngbr:adj[curr]){
            if(!visited[ngbr]){
                visited[ngbr]=true;
                maxGrp = max(maxGrp,getMaxElement(adj,ngbr,levels,visited));
            }
        }

        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //bipartite check
        vector<int>colors(n+1,-1);
        for(int i=1;i<=n;i++){
            if(colors[i]==-1){
                if(isBipartite(adj,colors,1,i)==false){
                    return -1;
                }
            }
        }

        vector<int>levels(n+1,0);
        for(int i=1;i<=n;i++){
            levels[i]=bfs(adj,i,n);
        }

        int result=0;
        vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                result+= getMaxElement(adj,i,levels,visited);
            }
        }

        return result;
    }
};