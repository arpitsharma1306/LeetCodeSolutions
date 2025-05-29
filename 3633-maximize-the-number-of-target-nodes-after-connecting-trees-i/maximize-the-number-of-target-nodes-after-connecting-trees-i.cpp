class Solution {
public:
    int bfs(unordered_map<int,vector<int>>&adj,int node,int k){
        queue<int>q;
        q.push(node);
        int depth=1;
        vector<bool>vis(adj.size(),false);
        vis[node]=true;
        int cnt=0;
        while(depth<=k && !q.empty()){
            int sz=q.size();
            depth++;
            for(int i=0;i<sz;i++){
                cnt++;
                int curr=q.front();
                q.pop();
                for(auto &child:adj[curr]){
                    if(!vis[child]){
                        q.push(child);
                        vis[child]=true;
                    }
                }
            }
        }

        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1, m=edges2.size()+1;
        unordered_map<int,vector<int>>adj1(n);
        unordered_map<int,vector<int>>adj2(m);

        for(auto &edge:edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto &edge:edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        int maxNodes2=0;
        for(int i=0;i<m;i++){
            maxNodes2=max(maxNodes2,bfs(adj2,i,k));
        }
        cout<<maxNodes2;
        vector<int>answer(n);
        for(int i=0;i<n;i++){
            int nodes=bfs(adj1,i,k+1);
            answer[i]=nodes+maxNodes2;
        }

        return answer;
        
    }
};