class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &vec:roads){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>result(n,LONG_MAX);
        vector<int>ways(n,0);
        result[0]=0;
        ways[0]=1;
        int mod=(int)(1e9+7);

        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]){
                int adjnode=it.first;
                int w=it.second;

                if(d+w<result[adjnode]){
                    result[adjnode]=d+w;
                    pq.push({d+w,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(d+w==result[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};