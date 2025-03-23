class Solution {
public:
    typedef pair<long long,int> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& road:roads){
            int u=road[0], v=road[1], w=road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<P, vector<P>, greater<P>> pq; //weight, node
        vector<int>ways(n,0);
        ways[0]=1;
        vector<long long>result(n,LONG_MAX);
        result[0]=0;
        int mod = (int)(1e9+7);
        pq.push({0,0});
        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& it:adj[node]){
                int adjnode = it.first, w = it.second;
                if(d+w<result[adjnode]){
                    result[adjnode] = d+w;
                    ways[adjnode] = ways[node];
                    pq.push({d+w,adjnode}); 
                }
                else if(d+w==result[adjnode]){
                    ways[adjnode] = (ways[adjnode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;

    }
};