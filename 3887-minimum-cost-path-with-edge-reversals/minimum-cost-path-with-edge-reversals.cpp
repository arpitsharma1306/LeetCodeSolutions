class Solution {
public:
    
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],2*e[2]});
        }

        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            for(auto &p:adj[u]){
                int v = p.first, w=p.second;
                if(d+w<dist[v]){
                    dist[v]=d+w;
                    pq.push({d+w,v});
                }
            }
        }

        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};