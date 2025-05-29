class Solution {
public:
    int maxNode2;
    int dfs(unordered_map<int,vector<int>>&adj,int node,int parent,int cnt){   
        int even=0;
        if(cnt%2==0) even++;
        for(auto& child:adj[node]){
            if(child!=parent){
                even += dfs(adj,child,node,cnt+1);
            }
        }

        return even;
    }
    
    void dfs2(unordered_map<int,vector<int>>&adj,vector<int>&answer,int even,int odd,int node,int parent,int cnt){
        if(cnt%2==0) answer[node]=even+maxNode2;
        else answer[node]=odd+maxNode2;

        for(auto& child:adj[node]){
            if(child!=parent){
                dfs2(adj,answer,even,odd,child,node,cnt+1);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1, m=edges2.size()+1;
        unordered_map<int,vector<int>>adj1(n), adj2(m);
        for(auto &edge:edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto &edge:edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int cnt_even2=dfs(adj2,0,-1,0);
        int cnt_odd2=m-cnt_even2;
        maxNode2= max(cnt_even2,cnt_odd2);

        int cnt_even1=dfs(adj1,0,-1,0);
        int cnt_odd1=n-cnt_even1;

        vector<int>answer(n);
        dfs2(adj1,answer,cnt_even1,cnt_odd1,0,-1,0);

        return answer;
    }
};