class Solution {
public:
    int n;
    int res=INT_MAX;
    vector<vector<int>>adj;
    vector<int>val;
    int total;

    int dfs2(int x,int par,int ans1,int anc){
        int xorr=val[x];
        for(int &ch:adj[x]){
            if(ch==par) continue;
            xorr^=dfs2(ch,x,ans1,anc);
        }
        if(par==anc) return xorr;

        res = min(res,max({xorr,ans1,total^ans1^xorr})-min({xorr,ans1,total^ans1^xorr}));
        

        return xorr;       
    }

    int dfs(int x,int par){
        int xorr=val[x];
        for(int &ch:adj[x]){
            if(ch==par) continue;
            xorr^=dfs(ch,x);
            
        }

        for(int &ch:adj[x]){
            if(ch==par) dfs2(ch,x,xorr,x);
        }

        return xorr;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n=nums.size();
        adj.assign(n,{});
        for(auto& edge:edges){
            int u=edge[0], v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        val=nums;
        total=0;
        for(int& x:nums){
            total^=x;
        }
        dfs(0,-1);
        return res;
    }
};